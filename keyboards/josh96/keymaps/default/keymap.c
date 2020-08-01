#include "josh96.h"

// Shorter defs to fit in keymap
#define MT_RA_M1 RALT_T(KC_MS_BTN1)
#define MT_RC_APP RCTL_T(KC_APP)

/* LED control */
uint8_t status_en = 1;

/* Jiggler */
static uint32_t key_timer = 0;
static bool dir = true;
static bool en = false;

/*
Custom codes for layers and keys
*/
enum layer_names {
    _COLEMAK = 0,
    _QWERTY,
    _NORMAL,
    _MACRO,
    _LOWER,
    _RAISE
};

enum custom_codes{
    STAT_EN = SAFE_RANGE,
    UNDER_EN,
    JIGGLER
};

// Layer Shifting
#define MO_SPC_LWR LT(_LOWER, KC_SPACE)
#define MO_TAB LT(_RAISE, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = KEYMAP(
	KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS,  KC_DEL,  KC_HOME, KC_END, KC_PGUP,  KC_PGDN,
	KC_GRV,   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,                  KC_BSPC, KC_CAPS, KC_PSLS, KC_PAST, KC_PMNS,
	MO_TAB,     KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC,            KC_BSLS, KC_7,    KC_8,    KC_9,
	KC_BSPC,      KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_NUHS,             KC_ENT,  KC_4,    KC_5,    KC_6,    KC_PPLS,
	KC_LSHIFT,        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH,       KC_RSHIFT,  KC_UP,   KC_1,    KC_2,    KC_3,
	KC_LCTL, KC_LGUI, KC_LALT,                  MO_SPC_LWR,         MT_RA_M1, KC_NO, MT_RC_APP, KC_LEFT, KC_DOWN, KC_RGHT, KC_0,    KC_DOT,  KC_PENT),

	[_QWERTY] = KEYMAP(
	KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS,  KC_DEL,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
	KC_GRV,   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,                  KC_BSPC,  KC_CAPS, KC_PSLS, KC_PAST, KC_PMNS,
	MO_TAB,     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,               KC_BSLS,  KC_7,    KC_8,    KC_9,
	KC_BSPC,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS,          KC_ENT,   KC_4,    KC_5,    KC_6,    KC_PPLS,
	KC_LSHIFT,        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,       KC_RSHIFT,  KC_UP,    KC_1,    KC_2,    KC_3,
	KC_LCTL, KC_LGUI, KC_LALT,                  MO_SPC_LWR,         MT_RA_M1, KC_NO, MT_RC_APP, KC_LEFT, KC_DOWN,  KC_RGHT, KC_0,  KC_DOT,   KC_PENT),

    [_LOWER] = KEYMAP(
	_______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,
	_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_DEL, _______, _______, _______, _______,
	_______,    _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
	KC_DEL,      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,        _______, _______, _______, _______, _______,
	_______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,         _______, _______, _______, _______,
	_______, _______, _______,                               _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_RAISE] = KEYMAP(
	JIGGLER,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,_______, _______, _______, _______, _______,
	_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
	_______,    KC_VOLD, KC_VOLU, _______, _______, _______, _______,_______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
	_______,      KC_MPRV, KC_MNXT,  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
	_______,      RESET, TG(_QWERTY), _______, _______, _______, _______, _______, _______, _______, _______,       _______,         _______, _______, _______, _______,
	_______, _______, _______,                               _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RESET:
      if (record->event.pressed) {
        rgblight_setrgb(255, 0, 0);
      } else {
      }
      break;

    case JIGGLER:
        if (record->event.pressed) {
            en ^= 1;
            if (en){
                // rgblight_setrgb_at(64, 64, 64, LED2);
            } else {
                // rgblight_setrgb_at(0, 0, 0, LED2);
            }
            return true;
        } else {
        }
        break;
  }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _COLEMAK:
        rgblight_setrgb (0x66,  0x00, 0xCC);
        break;
    case _QWERTY:
        rgblight_setrgb (0xFF,  0x63, 0x00);
        break;
    case _LOWER:
        rgblight_setrgb (0x66,  0xCC, 0x00);
        break;
    case _RAISE:
        rgblight_setrgb (0x22,  0x44, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xF0,  0xF0, 0xF0);
        break;
    }
  return state;
}

/*
Mouse Jiggler
*/
void matrix_scan_user(void) {
    if (timer_elapsed32(key_timer) > 60000) {
        key_timer = timer_read32();
        if (en && dir)
            tap_code(KC_MS_U);
        else if (en && !dir)
            tap_code(KC_MS_D);
        dir ^= 1;
    }
}
