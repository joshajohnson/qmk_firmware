#include "josh96.h"

enum keyboard_layers{
	_COLEMAK = 0,
	_QWERTY,
	_LOWER,
	_RAISE,
	_ADJUST
};

enum custom_keycodes{
  FLASH = SAFE_RANGE,
  MAKE,
  LENNY,
  TBL_FLP,
  SHRUG,
  LOD,
  CLOUD
};

// Tap Dancing
enum tap_dances{
  TD_PAGE_DWN = 0,
  TD_PAGE_UP
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PAGE_UP]  = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
  [TD_PAGE_DWN]  = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END)
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
	KC_LCTL, KC_LGUI, KC_LALT,                  MO_SPC_LWR,         KC_RALT, KC_RCTL, MO(_ADJUST), KC_LEFT, KC_DOWN, KC_RGHT, KC_0,    KC_DOT,  KC_PENT),

	[_QWERTY] = KEYMAP(
	KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS,  KC_DEL,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN,
	KC_GRV,   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,                  KC_BSPC,  KC_CAPS, KC_PSLS, KC_PAST, KC_PMNS,
	MO_TAB,     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,               KC_BSLS,  KC_7,    KC_8,    KC_9,
	KC_BSPC,      KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS,          KC_ENT,   KC_4,    KC_5,    KC_6,    KC_PPLS,
	KC_LSHIFT,        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,       KC_RSHIFT,  KC_UP,    KC_1,    KC_2,    KC_3,
	KC_LCTL, KC_LGUI, KC_LALT,                  MO_SPC_LWR,         KC_RALT, KC_RCTL, MO(_ADJUST), KC_LEFT, KC_DOWN,  KC_RGHT, KC_0,  KC_DOT,   KC_PENT),

    [_LOWER] = KEYMAP(
	_______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,
	_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_DEL, _______, _______, _______, _______,
	_______,    _______, _______, _______, _______, _______, _______,_______, TD(TD_PAGE_DWN), TD(TD_PAGE_UP), _______, _______,   _______, _______, _______, _______, _______,
	KC_DEL,      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,         _______, _______, _______, _______, _______,
	_______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,         _______, _______, _______, _______,
	_______, _______, _______,                               _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_RAISE] = KEYMAP(
	_______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______,
 	_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         UC_M_LN, UC_M_WI, _______, _______, _______,
	_______,     KC_VOLD, KC_VOLU, _______, _______, _______, _______,_______, KC_WH_D, KC_WH_U, _______, _______,   _______,      _______, _______, _______, _______,
	_______,     KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,       _______,     LOD,   CLOUD, _______, _______,
	_______,      _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______,       _______,     LENNY, TBL_FLP,   SHRUG, _______,
	_______, _______, _______,                               _______,                          _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[_ADJUST] = KEYMAP(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
	_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
	_______,    RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______,       _______, _______, _______, _______,
	_______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
	_______,        RESET, FLASH, MAKE, TG(_QWERTY), _______, _______, _______, _______, _______, _______,       _______,         _______, _______, _______, _______,
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

    case FLASH:
      if (record->event.pressed) {
        tap_code(KC_ENTER);
        SEND_STRING("qmk flash -kb josh96 -km default");
        tap_code(KC_ENTER);
        rgblight_enable();
        rgblight_setrgb(255, 0, 0);
        reset_keyboard();
      } else {
      }
      break;

    case MAKE:
      if (record->event.pressed) {
        tap_code(KC_ENTER);
        SEND_STRING("qmk compile -kb josh96 -km default");
        tap_code(KC_ENTER);
      } else {
      }
      break;

    case LENNY: // ( ͡° ͜ʖ ͡°)
      if (record->event.pressed) {
      	send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
      } else {
      }
      break;

    case TBL_FLP: // (╯°□°)╯ ︵ ┻━┻
      if(record->event.pressed){
        send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
      } else {
      }
      break;

    case SHRUG: // ¯\_(ツ)_/¯
      if (record->event.pressed) {
      	send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
      } else {
      }
      break;

    case LOD:   // ಠ_ಠ
   		if(record->event.pressed){
        send_unicode_hex_string("0CA0 005F 0CA0");
      } else {
      }
      break;

    case CLOUD:   // (っ◕‿◕)っ
   		if(record->event.pressed){
        send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063");
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
