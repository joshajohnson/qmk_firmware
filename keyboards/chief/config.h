/*
Copyright 2020 joshajohnson

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6A6A  // JJ
#define PRODUCT_ID      0x4441  // DA
#define DEVICE_VER      0x0001
#define MANUFACTURER    bing
#define PRODUCT         chief
#define DESCRIPTION     4 knobs 8 keys rgb and stuff

/* key matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

#define DIRECT_PINS { \
    { B2,  B1, A6,  A8 }, \
    { B14, A5, A13, B3 }, \
    { B9,  B4, B7,  B8 }  \
}

/* Rotary Encoder Things */
#define ENCODER_DIRECTION_FLIP
#define ENCODERS_PAD_A { A7, B12, A14, B5 }
#define ENCODERS_PAD_B { B0, B13, A15, B6 }

#define RGB_DI_PIN B15
#define DRIVER_LED_TOTAL 16
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_AFTER_TIMEOUT 0
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 16
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL

// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define DISABLE_RGB_MATRIX_BREATHING
// #define DISABLE_RGB_MATRIX_BAND_SAT
// #define DISABLE_RGB_MATRIX_BAND_VAL
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_ALL
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define DISABLE_RGB_MATRIX_DUAL_BEACON
// #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define DISABLE_RGB_MATRIX_RAINDROPS
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define DISABLE_RGB_MATRIX_SPLASH
// #define DISABLE_RGB_MATRIX_MULTISPLASH
// #define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Tap delay for tap vs hold */
#define TAPPING_TERM 200

/* Slow down key press speed to ensure computer picks it up */
#define TAP_CODE_DELAY 20

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#ifndef LINK_TIME_OPTIMIZATION_ENABLE
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION
#endif
