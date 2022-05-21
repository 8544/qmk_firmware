#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"
#include "pins.h"

static const pin_t matrix_row_pins[MATRIX_ROW_PINS] = MATRIX_ROW_PIN;
static const pin_t matrix_col_pins[MATRIX_COL_PINS] = MATRIX_COL_PIN;

static inline void KEY_INIT(void)
{
    for (int i = 0; i < MATRIX_ROW_PINS; i++) {
        setPinOutput(matrix_row_pins[i]);
    }
    setPinOutput(MATRIX_ROW_INV_PIN);
    for (int i = 0; i < MATRIX_COL_PINS; i++) {
        setPinOutput(matrix_col_pins[i]);
    }
    setPinOutput(WAKE_UP_PIN);
    setPinOutput(SCAN_PIN);
    setPinOutput(PREV_PIN);
    setPinInputHigh(KEY_PIN);

    setPinOutput(LED_BLUE_PIN);
    setPinOutput(LED_ORANGE_PIN);
}


static inline void KEY_POWER_ON(void)
{
    writePinHigh(WAKE_UP_PIN);
}

static inline void KEY_POWER_OFF(void)
{
    writePinLow(WAKE_UP_PIN);
    for (int i = 0; i < MATRIX_ROW_PINS; i++) {
        writePinHigh(matrix_row_pins[i]);
    }
    writePinHigh(MATRIX_ROW_INV_PIN);
    for (int i = 0; i < MATRIX_COL_PINS; i++) {
        writePinHigh(matrix_col_pins[i]);
    }
}

static inline void ROW_SELECT(int row)
{
    // row
    for (int i = 0; i < MATRIX_ROW_PINS; i++) {
        writePin(matrix_row_pins[i], row & (1 << i));
    }
    // inv of last pin
    writePin(MATRIX_ROW_INV_PIN, ~(row | ~(1 << (MATRIX_ROW_PINS - 1))));

    return;
}

static inline void COL_SELECT(int col)
{
    for (int i = 0; i < MATRIX_COL_PINS; i++) {
        if (i == col)
            writePinLow(matrix_col_pins[i]);
        else
            writePinHigh(matrix_col_pins[i]);
    }
    return;
}

static inline void KEY_PREV_ON(void)
{
    writePinHigh(PREV_PIN);
}

static inline void KEY_PREV_OFF(void)
{
    writePinLow(PREV_PIN);
}

static inline void KEY_SCAN_ON(void)
{
    writePinLow(SCAN_PIN);
}

static inline void KEY_SCAN_OFF(void)
{
    writePinHigh(SCAN_PIN);
}

static inline bool KEY_STATE(void)
{
    return readPin(KEY_PIN);
}
