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

/* LED control */
uint8_t status_en = 1;

/* Jiggler */
static uint32_t key_timer = 0;
static bool dir = true;
static bool en = false;

enum custom_codes{
    JIGGLER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
       RGB_TOG,    RGB_RMOD,    RGB_MOD,    JIGGLER,  \
       CK_TOGG,    CK_UP,    CK_DOWN,    KC_H,  \
       KC_I,    KC_J,    KC_K,    KC_L  \
)
};

/*
Per Key Actions
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case JIGGLER:
        if (record->event.pressed) {
            en ^= 1;
            if (en){
            } else {
            }
            return true;
        } else {
        }
        break;
    }
    return true;
}

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

/*
Mouse Jiggler
*/
void matrix_scan_user(void) {
    if (timer_elapsed32(key_timer) > 100) {
        key_timer = timer_read32();
        if (en && dir)
            tap_code(KC_MS_U);
        else if (en && !dir)
            tap_code(KC_MS_D);
        dir ^= 1;
    }
}
