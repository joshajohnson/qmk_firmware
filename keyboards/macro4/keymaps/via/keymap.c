/*
Copyright 2020 Josh Johnson <josh@joshajohnson.com>

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
#include QMK_KEYBOARD_H

enum custom_keycodes{
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    MACRO_1, RGB_TOG,
    MACRO_3, MACRO_4
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO_1:
        if (record->event.pressed) {
        SEND_STRING(SS_LCTL("m")); // Mute Webex
      }

    // case MACRO_2:
    //     tap_code16(RGB_TOG);
    //   break;

    case MACRO_3:
        SEND_STRING(SS_LCTL(SS_LALT("d"))); // Share Screen
        break;

    case MACRO_4:
        SEND_STRING(SS_LCTL(SS_LALT("a"))); // Share Application
        break;
  }
  return true;
};

// Encoder turns volume up / down
void encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
};
