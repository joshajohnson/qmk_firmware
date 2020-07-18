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

#define ___ KC_NO

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _MACRO,
    _FN
};

#define MO_SPC_RSE LT(_RAISE, KC_SPACE)

#define MT_RA_M1 RALT_T(KC_MS_BTN1)
#define MT_RC_M2 RCTL_T(KC_MENU)  // Can't get the tap button working, maybe basic keycodes only?


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_2U_SS(
    _______, _______, KC_MUTE, KC_MPLY,  KC_ESC,   KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12, KC_INS, KC_DEL,  KC_HOME,  \
    KC_PMNS, KC_PAST, KC_PSLS, KC_CAPS,  KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,  KC_EQL,    KC_BSPC,    KC_PGUP,  \
               KC_P7,   KC_P8,   KC_P9,  KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,   KC_LBRC, KC_RBRC,  KC_BSLS,    KC_PGDN,  \
    KC_PPLS,   KC_P4,   KC_P5,   KC_P6,  KC_BSPC,         KC_A,    KC_R,   KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   KC_QUOT,          KC_ENT,     KC_END,  \
               KC_P1,   KC_P2,   KC_P3,  KC_LSFT,           KC_Z,    KC_X,  KC_C,    KC_V,    KC_B,    KC_K,    KC_M,  KC_COMM,   KC_DOT, KC_SLSH,       KC_RSFT,    KC_UP,    MO(_FN),  \
    KC_PENT, KC_PDOT,      KC_P0,        KC_LCTL,  KC_LGUI,    KC_LALT,          MO_SPC_RSE,    KC_SPC,          MO(_LOWER),        MT_RA_M1,   MT_RC_M2,   KC_LEFT, KC_DOWN, KC_RIGHT
),

    [_QWERTY] = LAYOUT_2U_SS(
    _______, _______, _______, _______,  KC_ESC,   KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12, KC_INS, KC_DEL,  KC_HOME,  \
    KC_PMNS, KC_PAST, KC_PSLS, KC_NLCK,  KC_GRV,      KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,  KC_EQL,    KC_BSPC,    KC_PGUP,  \
               KC_P7,   KC_P8,   KC_P9,  KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC,  KC_BSLS,    KC_PGDN,  \
    KC_PPLS,   KC_P4,   KC_P5,   KC_P6,  KC_BSPC,         KC_A,    KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,   KC_QUOT,         KC_ENT,     KC_END,  \
               KC_P1,   KC_P2,   KC_P3,  KC_LSFT,           KC_Z,    KC_X,  KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,   KC_DOT, KC_SLSH,       KC_RSFT,    KC_UP,    MO(_FN),  \
    KC_PENT, KC_PDOT,      KC_P0,        KC_LCTL,  KC_LGUI,    KC_LALT,          MO_SPC_RSE,    KC_SPC,          MO(_LOWER),        MT_RA_M1,   MT_RC_M2,   KC_LEFT, KC_DOWN, KC_RIGHT
),

    [_LOWER] = LAYOUT_2U_SS(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,      _______,      _______,  \
             _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,    _______,   _______,  \
    _______, _______, _______, _______,  KC_DEL,        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,        _______,      _______,  \
             _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,  KC_END, KC_HOME, _______, _______,      _______,     _______, _______,  \
    _______, _______,          _______, _______,   _______,    _______,         _______,       _______,      _______,        _______,              _______,  _______, _______, _______
),


    [_RAISE] = LAYOUT_2U_SS(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,     _______,      _______,  \
             _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,  \
    _______, _______, _______, _______,  KC_DEL,        KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, _______,  KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______,       _______,      _______,  \
             _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, _______,  \
    _______, _______,          _______, _______,   _______,    _______,         _______,       _______,      _______,        _______,              _______,  _______, _______, _______
),


    [_MACRO] = LAYOUT_2U_SS(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,      _______,  \
             _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,  \
    _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,      _______,  \
             _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, _______,  \
    _______, _______,          _______, _______,   _______,    _______,         _______,       _______,      _______,        _______,              _______,  _______, _______, _______
),


    [_FN] = LAYOUT_2U_SS(
    _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RESET,  \
    _______, _______, _______, KC_NLCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,     TG(_QWERTY),  \
             _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,  TG(_MACRO),  \
    _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,      _______,  \
             _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, _______,  \
    _______, _______,          _______, _______,   _______,    _______,         _______,       _______,      _______,        _______,              _______,  _______, _______, _______
)

};

// Encoder control
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_FN)){
        if (index == 0) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        } else if (index == 1) {
            if (clockwise) {
                rgblight_increase_sat();
            } else {
                rgblight_decrease_sat();
            }
        } else if (index == 2) {
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        } else if (index == 3) {
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        } else if (index == 4) {
            // if (clockwise) {
            //     tap_code(KC_MNXT);
            // } else {
            //     tap_code(KC_MPRV);
            // }
        }
    } else {
            if (index == 0) {
            // if (clockwise) {
            //     tap_code(KC_MNXT);
            // } else {
            //     tap_code(KC_MPRV);
            // }
        } else if (index == 1) {
            // if (clockwise) {
            //     tap_code(KC_MNXT);
            // } else {
            //     tap_code(KC_MPRV);
            // }
        } else if (index == 2) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 3) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        } else if (index == 4) {
            // if (clockwise) {
            //     tap_code(KC_MNXT);
            // } else {
            //     tap_code(KC_MPRV);
            // }
        }
    }
}
