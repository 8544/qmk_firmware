/* Copyright 2020 Nick Brassel (tzarc)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include_next "mcuconf.h"

#undef STM32_PWM_USE_TIM5
#define STM32_PWM_USE_TIM5 TRUE

/* select SPI peripheral to be used */

#undef STM32_SPI_USE_SPI1
#undef STM32_SPI_USE_SPI2
#undef STM32_SPI_USE_SPI3

#define STM32_SPI_USE_SPI1                  TRUE
#define STM32_SPI_USE_SPI2                  FALSE
#define STM32_SPI_USE_SPI3                  FALSE

/* audio driver: uses PB4 for output */
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE
#undef STM32_GPT_USE_TIM4
#define STM32_GPT_USE_TIM4 TRUE
