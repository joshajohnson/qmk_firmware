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

#define SINGLE_TAP_1 	KC_A
#define SINGLE_HOLD_1 KC_B
#define DOUBLE_TAP_1 	KC_C
#define DOUBLE_HOLD_1	KC_D

#define SINGLE_TAP_2 	KC_E
#define SINGLE_HOLD_2 KC_F
#define DOUBLE_TAP_2 	KC_G
#define DOUBLE_HOLD_2 KC_H

#define SINGLE_TAP_3 	KC_I
#define SINGLE_HOLD_3 KC_J
#define DOUBLE_TAP_3 	KC_K
#define DOUBLE_HOLD_3 KC_L

#define SINGLE_TAP_4 	KC_M
#define SINGLE_HOLD_4 KC_N
#define DOUBLE_TAP_4 	KC_O
#define DOUBLE_HOLD_4 KC_P

#define ENC1_CLOCKWISE	KC_Q
#define ENC1_ANTICLOCK	KC_R
#define ENC2_CLOCKWISE	KC_S
#define ENC2_ANTICLOCK	KC_T

// Quad Function Tap-Dance
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
  KEY1 = 0,
  KEY2,
  KEY3,
  KEY4
};

// Fancy tap dancing function defs
int cur_dance (qk_tap_dance_state_t *state);
void key1_finished (qk_tap_dance_state_t *state, void *user_data);
void key1_reset (qk_tap_dance_state_t *state, void *user_data);
void key2_finished (qk_tap_dance_state_t *state, void *user_data);
void key2_reset (qk_tap_dance_state_t *state, void *user_data);
void key3_finished (qk_tap_dance_state_t *state, void *user_data);
void key3_reset (qk_tap_dance_state_t *state, void *user_data);
void key4_finished (qk_tap_dance_state_t *state, void *user_data);
void key4_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(KEY1), TD(KEY2),
    TD(KEY3), TD(KEY4)
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left Encoder */
        if (clockwise) {
            tap_code(ENC1_CLOCKWISE);
        } else {
            tap_code(ENC1_ANTICLOCK);
        }
    } else if (index == 1) { /* Right Encoder */
        if (clockwise) {
            tap_code(ENC2_CLOCKWISE);
        } else
            tap_code(ENC2_ANTICLOCK);
        }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case GNU_CP:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING("I'd just like to interject for a moment. What you're referring to as Linux, is in fact, GNU/Linux, or as I've recently taken to calling it, GNU plus Linux. Linux is not an operating system unto itself, but rather another free component of a fully functioning GNU system made useful by the GNU corelibs, shell utilities and vital system components comprising a full OS as defined by POSIX.");
    //     tap_code(KC_ENTER);
    //     SEND_STRING("Many computer users run a modified version of the GNU system every day, without realizing it. Through a peculiar turn of events, the version of GNU which is widely used today is often called 'Linux', and many of its users are not aware that it is basically the GNU system, developed by the GNU Project.");
    //     tap_code(KC_ENTER);
    //     SEND_STRING("There really is a Linux, and these people are using it, but it is just a part of the system they use. Linux is the kernel: the program in the system that allocates the machine's resources to the other programs that you run. The kernel is an essential part of an operating system, but useless by itself; it can only function in the context of a complete operating system. Linux is normally used in combination with the GNU operating system: the whole system is basically GNU with Linux added, or GNU/Linux. All the so-called 'Linux' distributions are really distributions of GNU/Linux.");
    //   } else {
    //     // when keycode is released
    //   }
    // break;

  }
  return true;
};

// Fancy Tap Dance stuff
// https://docs.qmk.fm/#/feature_tap_dance?id=tap-dance-a-single-key-can-do-3-5-or-100-different-things
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void key1_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(SINGLE_TAP_1); break;
    case SINGLE_HOLD: register_code(SINGLE_HOLD_1); break;
    case DOUBLE_TAP: register_code(DOUBLE_TAP_1); break;
    case DOUBLE_HOLD: register_code(DOUBLE_HOLD_1); break;
    case DOUBLE_SINGLE_TAP: register_code(SINGLE_TAP_1); unregister_code(SINGLE_TAP_1); register_code(SINGLE_TAP_1);
  }
}

void key1_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(SINGLE_TAP_1); break;
    case SINGLE_HOLD: unregister_code(SINGLE_HOLD_1); break;
    case DOUBLE_TAP: unregister_code(DOUBLE_TAP_1); break;
    case DOUBLE_HOLD: unregister_code(DOUBLE_HOLD_1);
    case DOUBLE_SINGLE_TAP: unregister_code(SINGLE_TAP_1);
  }
  xtap_state.state = 0;
}

void key2_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(SINGLE_TAP_2); break;
    case SINGLE_HOLD: register_code(SINGLE_HOLD_2); break;
    case DOUBLE_TAP: register_code(DOUBLE_TAP_2); break;
    case DOUBLE_HOLD: register_code(DOUBLE_HOLD_2); break;
    case DOUBLE_SINGLE_TAP: register_code(SINGLE_TAP_2); unregister_code(SINGLE_TAP_2); register_code(SINGLE_TAP_2);
  }
}

void key2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(SINGLE_TAP_2); break;
    case SINGLE_HOLD: unregister_code(SINGLE_HOLD_2); break;
    case DOUBLE_TAP: unregister_code(DOUBLE_TAP_2); break;
    case DOUBLE_HOLD: unregister_code(DOUBLE_HOLD_2);
    case DOUBLE_SINGLE_TAP: unregister_code(SINGLE_TAP_2);
  }
  xtap_state.state = 0;
}

void key3_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(SINGLE_TAP_3); break;
    case SINGLE_HOLD: register_code(SINGLE_HOLD_3); break;
    case DOUBLE_TAP: register_code(DOUBLE_TAP_3); break;
    case DOUBLE_HOLD: register_code(DOUBLE_HOLD_3); break;
    case DOUBLE_SINGLE_TAP: register_code(SINGLE_TAP_3); unregister_code(SINGLE_TAP_3); register_code(SINGLE_TAP_3);
  }
}

void key3_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(SINGLE_TAP_3); break;
    case SINGLE_HOLD: unregister_code(SINGLE_HOLD_3); break;
    case DOUBLE_TAP: unregister_code(DOUBLE_TAP_3); break;
    case DOUBLE_HOLD: unregister_code(DOUBLE_HOLD_3);
    case DOUBLE_SINGLE_TAP: unregister_code(SINGLE_TAP_3);
  }
  xtap_state.state = 0;
}

void key4_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(SINGLE_TAP_4); break;
    case SINGLE_HOLD: register_code(SINGLE_HOLD_4); break;
    case DOUBLE_TAP: register_code(DOUBLE_TAP_4); break;
    case DOUBLE_HOLD: register_code(DOUBLE_HOLD_4); break;
    case DOUBLE_SINGLE_TAP: register_code(SINGLE_TAP_4); unregister_code(SINGLE_TAP_4); register_code(SINGLE_TAP_4);
  }
}

void key4_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(SINGLE_TAP_4); break;
    case SINGLE_HOLD: unregister_code(SINGLE_HOLD_4); break;
    case DOUBLE_TAP: unregister_code(DOUBLE_TAP_4); break;
    case DOUBLE_HOLD: unregister_code(DOUBLE_HOLD_4);
    case DOUBLE_SINGLE_TAP: unregister_code(SINGLE_TAP_4);
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [KEY1]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,key1_finished, key1_reset),
  [KEY2]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,key2_finished, key2_reset),
  [KEY3]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,key3_finished, key3_reset),
  [KEY4]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,key4_finished, key4_reset)
};
