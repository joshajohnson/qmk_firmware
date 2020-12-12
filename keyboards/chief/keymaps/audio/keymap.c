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
#include "muse.h"
#define _BASE   0
#define _LAYER1 1

/* LED control */
uint8_t status_en = 1;

/* Jiggler */
static uint32_t key_timer = 0;
static bool dir = true;
static bool en = false;

/* Audio */
float my_song[][2] = SONG(SANDSTORM);
// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 120;

enum custom_codes{
    JIGGLER = SAFE_RANGE,
    SONGTIME
};

// define buttons
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
       MO(_LAYER1),    MO(_LAYER1),    MO(_LAYER1),    LT(_LAYER1, KC_F24),  \
       CK_TOGG,    RGB_TOG,    JIGGLER,    KC_MPLY,  \
       KC_F21,  KC_F22,  KC_F23,  KC_F24  \
    ),
    [_LAYER1] = LAYOUT(
       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  \
       RGB_TOG,    RGB_TOG,    KC_MSTP,    KC_MPLY,  \
       KC_F21,  KC_F22,  KC_F23,  RGB_TOG  \
    ), 
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
    
    case RGB_TOG:
        if (record->event.pressed) {
            PLAY_SONG(my_song);
        }
        return true;
    default:
        return true;

    // case SONGTIME:
    //     if (record->event.pressed) {
    //         PLAY_SONG(STARTUP_SOUND);
    //     }
    //     break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)) {
        case 1:     // 1ST LAYER
            if (index == 0) {
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
            } else if (index == 1) {
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            } else if (index == 2) {
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
            } else if (index == 3) {
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
            }
            break;
        default:    // BASE LAYER
            if (index == 0) {
                // if (clockwise) {
                //     PLAY_SONG(my_song);
                // } else {
                //     PLAY_SONG(my_song);
                // }
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 2) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            } else if (index == 3) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            break;
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
