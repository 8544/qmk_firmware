/*
Copyright 2011 Jun Wako <wakojun@gmail.com>
Copyright 2020-2024 8544 <emacs@ymail.ne.jp>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include "hhkb_f411.h"

#define wait_us_arm(x) chSysPolledDelayX(US2RTC(STM32_SYSCLK, x))

// matrix state buffer(1:on, 0:off)
static matrix_row_t *matrix;
static matrix_row_t *matrix_prev;
static matrix_row_t _matrix0[MATRIX_ROWS];
static matrix_row_t _matrix1[MATRIX_ROWS];


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
#ifdef DEBUG
    debug_enable = true;
    debug_keyboard = true;
#endif

    KEY_INIT();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix0[i] = 0x00;
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix1[i] = 0x00;
    matrix = _matrix0;
    matrix_prev = _matrix1;

    matrix_init_kb();
}

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

uint8_t matrix_scan(void)
{
    uint8_t *tmp;

    tmp = matrix_prev;
    matrix_prev = matrix;
    matrix = tmp;

    // power on
    KEY_POWER_ON();
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            wait_us_arm(5);

            ROW_SELECT(row);
            wait_us_arm(12);

            if (matrix_prev[row] & (1<<col)) {
                KEY_PREV_ON();
            }
            wait_us_arm(5);

            KEY_SCAN_ON();
            wait_us_arm(1);
            COL_SELECT(col);

            // Wait for KEY_STATE outputs its value.
            wait_us_arm(2);

            if (KEY_STATE()) {
                matrix[row] &= ~(1<<col);
            } else {
                matrix[row] |= (1<<col);
            }

            wait_us_arm(1);
            KEY_SCAN_OFF();
            KEY_PREV_OFF();
            wait_us_arm(2);
            COL_SELECT(-1);

            // NOTE: KEY_STATE keep its state in 20us after KEY_ENABLE.
            // This takes 25us or more to make sure KEY_STATE returns to idle state.

            // Looks like JP needs faster scan due to its twice larger matrix
            // or it can drop keys in fast key typing
            wait_us_arm(30);
        }
    }
    KEY_POWER_OFF();

    matrix_scan_kb();

    wait_ms(12);
    return 1;
}

bool matrix_is_modified(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] != matrix_prev[i])
            return true;
    }
    return false;
}

inline
bool matrix_has_ghost(void)
{
    return false;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & (1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 01234567\n");
    for (uint8_t row = 0; row < matrix_rows(); row++) {
        xprintf("%02X: %08b\n", row, bitrev(matrix_get_row(row)));
    }
}

uint8_t matrix_key_count(void) {
    uint8_t count = 0;
    for (int8_t r = MATRIX_ROWS - 1; r >= 0; --r) {
        count += bitpop16(matrix_get_row(r));
    }
    return count;
}

void matrix_power_up(void) {
    KEY_POWER_ON();
}
void matrix_power_down(void) {
    KEY_POWER_OFF();
}
