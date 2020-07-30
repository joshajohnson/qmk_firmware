#include QMK_KEYBOARD_H

static uint32_t key_timer = 0;
static bool dir = true;
static bool en = true;

enum custom_keycodes {
    KEY_TIMER = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_NO
    )
};

void matrix_scan_user(void) { 
    if (timer_elapsed32(key_timer) > 30) {
        key_timer = timer_read32();  // reset timer
        if (en && dir)
            tap_code(KC_MS_U);
        else if (en && !dir)
            tap_code(KC_MS_D);
        dir ^= 1;
    }
}