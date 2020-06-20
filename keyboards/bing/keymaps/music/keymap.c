#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_KEY1,
    TD_KEY2,
    TD_KEY3,
    TD_KEY4
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_KEY1] = ACTION_TAP_DANCE_DOUBLE(KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE),
    [TD_KEY2] = ACTION_TAP_DANCE_DOUBLE(KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK),
    [TD_KEY3] = ACTION_TAP_DANCE_DOUBLE(KC_AUDIO_VOL_DOWN, KC_MEDIA_PREV_TRACK),
    [TD_KEY4] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, KC_TRNS)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
          TD(TD_KEY1),
          TD(TD_KEY2),
          TD(TD_KEY3),
          TD(TD_KEY4)
          )
};
