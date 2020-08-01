/* Copyright 2020 joshajohnson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
       RGB_TOG,    RGB_RMOD,    RGB_MOD,    KC_D,  \
       KC_E,    KC_F,    KC_G,    KC_H,  \
       KC_I,    KC_J,    KC_K,    KC_L  \
)

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(RGB_HUI);
        } else {
            tap_code16(RGB_HUD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(RGB_SAI);
        } else {
            tap_code16(RGB_SAD);
        }
    } else if (index == 2) {
        if (clockwise) {
            tap_code16(RGB_VAI);
        } else {
            tap_code16(RGB_VAD);
        }
    } else if (index == 3) {
        if (clockwise) {
            tap_code16(RGB_SPI);
        } else {
            tap_code16(RGB_SPD);
        }
    }
}
