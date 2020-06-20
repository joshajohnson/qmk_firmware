#include QMK_KEYBOARD_H

#define KC_WRAP KC_F21

#define K1_SGL KC_A
#define K1_DBL KC_B
#define K2_SGL KC_C
#define K2_DBL KC_D
#define K3_SGL KC_E
#define K3_DBL KC_F
#define K4_SGL KC_G
#define K4_DBL KC_H

// Tap Dance Stuff
void td_1 (qk_tap_dance_state_t *state, void *user_data);
void td_2 (qk_tap_dance_state_t *state, void *user_data);
void td_3 (qk_tap_dance_state_t *state, void *user_data);
void td_4 (qk_tap_dance_state_t *state, void *user_data);

// Tap Dance declarations
enum {
    TD_KEY1,
    TD_KEY2,
    TD_KEY3,
    TD_KEY4
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY1] = ACTION_TAP_DANCE_FN(td_1),
    [TD_KEY2] = ACTION_TAP_DANCE_FN(td_2),
    [TD_KEY3] = ACTION_TAP_DANCE_FN(td_3),
    [TD_KEY4] = ACTION_TAP_DANCE_FN(td_4)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      TD(TD_KEY1),
      TD(TD_KEY2),
      TD(TD_KEY3),
      TD(TD_KEY4)
      )
};


// Below works around TD() not running key press through process_record_user.
void td_1 (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_WRAP);
    tap_code(K1_SGL);
    unregister_code(KC_WRAP);
  } else if (state->count == 2) {
    register_code(KC_WRAP);
    tap_code(K1_DBL);
    unregister_code(KC_WRAP);
  }
}

void td_2 (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_WRAP);
    tap_code(K2_SGL);
    unregister_code(KC_WRAP);
  } else if (state->count == 2) {
    register_code(KC_WRAP);
    tap_code(K2_DBL);
    unregister_code(KC_WRAP);
  }
}

void td_3 (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_WRAP);
    tap_code(K3_SGL);
    unregister_code(KC_WRAP);
  } else if (state->count == 2) {
    register_code(KC_WRAP);
    tap_code(K3_DBL);
    unregister_code(KC_WRAP);
  }
}

void td_4 (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_WRAP);
    tap_code(K4_SGL);
    unregister_code(KC_WRAP);
  } else if (state->count == 2) {
    register_code(KC_WRAP);
    tap_code(K4_DBL);
    unregister_code(KC_WRAP);
  }
}