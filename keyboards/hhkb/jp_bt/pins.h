#pragma once

/*
 * HHKB Matrix I/O
 *
 * wake:    waken: 1
 * row:     [A,B,C,D,~D]  selects scan row0-7
 * col:     [A,B,C,D,E] selects scan col0-4
 * scan:    start scan pressed key
 * key:     on: 0/off: 1
 * prev:    hysteresis control: assert(1) when previous key state is on
 *
 * For 8544's HHKB-BT alt controller Rev 20210427 (WeAct STMF411CEU),
 * pins are assigned as follows:
 *
 * wake:    PB14
 * row:     PB10, PB1, PB0, PA3, PA2
 * col:     PA1, PA0, PC15, PC14, PB9
 * scan:    PB6
 * key:     PB8 (pull-uped)
 * prev:    PB7
 * led blue: PB12 (set high to turn the LED on)
 * led orange: PB13 (set high to turn the LED on)
 */
              
#define WAKE_UP_PIN B14
#define MATRIX_ROW_PINS 4
#define MATRIX_COL_PINS 5
#define MATRIX_ROW_PIN {B10, B1, B0, A3}
#define MATRIX_ROW_INV_PIN A2
#define MATRIX_COL_PIN {A1, A0, C15, C14, B9}
#define UNUSED_PINS {A8, A9, A10, A11, A12, A15, B2, B3, B5, C13}

#define SCAN_PIN B6
#define KEY_PIN B8
#define PREV_PIN B7

#define LED_BLUE_PIN B12
#define LED_ORANGE_PIN B13
