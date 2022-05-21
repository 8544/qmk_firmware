/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2020-2022 8544 <emacs@ymail.ne.jp> 
-
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define DESCRIPTION     q.m.k keyboard firmware for HHKB-BT

/* key matrix size */
#define MATRIX_ROWS 16
#define MATRIX_COLS 5

// SPI driver
#define SPI_DRIVER                          SPID1
#define SPI_SCK_PIN                         A5
#define SPI_SCK_PAL_MODE                    5
#define SPI_MOSI_PIN                        A7
#define SPI_MOSI_PAL_MODE                   5
#define SPI_MISO_PIN                        A6
#define SPI_MISO_PAL_MODE                   5

// EEPROM driver
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4

/* https://github.com/qmk/qmk_firmware/pull/8780#issuecomment-626994586 */
/* https://github.com/WeActTC/MiniSTM32F4x1/blob/master/SDK/STM32F411CEU6/MicroPython/WeAct_F411CE/mpconfigboard.h#L32 */
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 4

/* https://www.winbond.com/resource-files/W25Q32JV%20RevI%2005042021%20Plus.pdf */
#define EXTERNAL_EEPROM_BYTE_COUNT (4 * 1024 * 1024)
#define EXTERNAL_EEPROM_PAGE_SIZE 256
#define EXTERNAL_EEPROM_ADDRESS_SIZE 3

// Audio Driver
#define AUDIO_PIN B4
#define AUDIO_PWM_DRIVER PWMD3  /* use TIM3 for PWM*/
#define AUDIO_PWM_PAL_MODE 2
#define AUDIO_PWM_CHANNEL 1
#define AUDIO_STATE_TIMER GPTD4  /* use TIM4 for audio timer */

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 440.0f
#define AUDIO_CLICKY_FREQ_MAX 4000.0f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.3f

#define MUSIC_MAP

// VIA
#define BOOTMAGIC_LITE_ROW 4
#define BOOTMAGIC_LITE_COL 1
