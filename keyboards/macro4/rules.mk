# MCU name
MCU = STM32F072

BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = no  	# Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	    # USB Nkey Rollover
CUSTOM_MATRIX = no 		# Custom matrix file
ENCODER_ENABLE = yes	# Rotary Encoder support
TAP_DANCE_ENABLE = yes 	# Support for tap dancing
RGBLIGHT_ENABLE = yes	# under board WS2812 support
WS2812_DRIVER = bitbang	# could not get SPI working on STM32F072

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
