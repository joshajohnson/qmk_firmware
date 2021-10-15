/* Copyright 2020 null-ll
 * Copyright 2021 Jels, Josh Johnson
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

#include "chalice.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_bs(  /* base */
      KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_TRNS,
      KC_INS,  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_DEL,  KC_BSPC,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_K,    KC_M,   KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,
               KC_LCTL, KC_LALT,          MO(1),          KC_SPC,            KC_SPC,           KC_LGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RIGHT
    ),

  [1] = LAYOUT_split_bs(  /* fn */
     /* esc       `        1        2        3        4        5        6        7        8        9        0        -        =       bspc   */
      RESET,   KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
     /* ins     tab        Q        W        E        R        T        Y        U        I        O        P        [        ]        \   */
      EEP_RST, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /* del     caps       A        S        D        F        G        H        J        K        L        ;        '       enter     */
      KC_TRNS, KC_DEL,  KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_INS,  KC_TRNS,
     /*         shift      Z        X        C        V        B        B        N        M        ,        .        /       shift     up   */
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
     /*         ctrl      alt              space              fn               space              alt      ctrl              left     down     right  */
               KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END
    ),

  [2] = LAYOUT_split_bs(
     /* esc       `        1        2        3        4        5        6        7        8        9        0        -        =       bspc   */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /* ins     tab        Q        W        E        R        T        Y        U        I        O        P        [        ]        \   */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /* del     caps       A        S        D        F        G        H        J        K        L        ;        '       enter     */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
     /*         shift      Z        X        C        V        B        B        N        M        ,        .        /       shift     up   */
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /*         ctrl      alt              space              fn               space              alt      ctrl              left     down     right  */
               KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

  [3] = LAYOUT_split_bs(
     /* esc       `        1        2        3        4        5        6        7        8        9        0        -        =       bspc   */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /* ins     tab        Q        W        E        R        T        Y        U        I        O        P        [        ]        \   */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /* del     caps       A        S        D        F        G        H        J        K        L        ;        '       enter     */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
     /*         shift      Z        X        C        V        B        B        N        M        ,        .        /       shift     up   */
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     /*         ctrl      alt              space              fn               space              alt      ctrl              left     down     right  */
               KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    )
};