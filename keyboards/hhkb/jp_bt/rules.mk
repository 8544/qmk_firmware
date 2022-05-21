# MCU name
MCU = STM32F411
STM32_BOOTLOADER_ADDRESS = 0x1FFF0000

# Build Options
#   comment out to disable the options.
#
CUSTOM_MATRIX = yes    # Custom matrix file for the HHKB

AUDIO_DRIVER = pwm_hardware
# EEPROM_DRIVER = spi
EEPROM_DRIVER = transient
# project specific files
SRC = matrix.c
