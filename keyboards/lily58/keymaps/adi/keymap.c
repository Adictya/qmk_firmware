/* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

// extern uint8_t is_master;

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _LAYER4,
    _LAYER5,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.
     * ,-----------------------------------------. | ESC  |   1  |   2  |   3  |
     * 4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ~ |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| | Tab  |   Q  |   W  |   E  |
     * R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  - |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |LCTRL |   A  |   S  |   D  |
     * F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  ' |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |LShift|   Z  |   X  |   C  |
     * V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   / |RShift|
     * `-----------------------------------------/       /     \
     * \-----------------------------------------' |LOWER | LGUI | Alt  | /Space
     * /       \Enter \  |BackSP| RGUI |RAISE | |      |      |      |/       /
     * \      \ |      |      |      |
     *                   `-------------------''-------'
     * '------''--------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LOWER, KC_LGUI, KC_LALT, KC_SPC, KC_ENT, KC_BSPC, KC_RGUI, RAISE),
    /* LOWER
     * ,-----------------------------------------.
     * ,-----------------------------------------. |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |   !  |   @  |   #  |
     * $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |   1  |   2  |   3  |
     * 4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  | |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
     * `-----------------------------------------/       /     \
     * \-----------------------------------------' |LOWER | LGUI | Alt  | /Space
     * /       \Enter \  |BackSP| RGUI |RAISE | |      |      |      |/       /
     * \      \ |      |      |      |
     *                   `-------------------''-------'
     * '------''--------------------'
     */
    [_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_GRAVE, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,-----------------------------------------.
     * ,-----------------------------------------. |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |  F1  |  F2  |  F3  |  F4  |
     * F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12
     * |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
     * `-----------------------------------------/       /     \
     * \-----------------------------------------' |LOWER | LGUI | Alt  | /Space
     * /       \Enter \  |BackSP| RGUI |RAISE | |      |      |      |/       /
     * \      \ |      |      |      |
     *                   `-------------------''-------'
     * '------''--------------------'
     */

    [_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* ADJUST
     * ,-----------------------------------------.
     * ,-----------------------------------------. |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \
     * \-----------------------------------------' |LOWER | LGUI | Alt  | /Space
     * /       \Enter \  |BackSP| RGUI |RAISE | |      |      |      |/       /
     * \      \ |      |      |      |
     *                   `----------------------------'
     * '------''--------------------'
     */
    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______),
    [_LAYER5] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______),

    [_LAYER4] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else {
        if (clockwise) tap_code(KC_PGUP) else tap_code(KC_PGDN)
    }
}
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x7f, 0x99, 0xfe, 0x7f, 0xe6, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x7f, 0x99, 0xfe, 0x7f, 0xe7, 0x0e, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x61, 0x99, 0x80, 0x06, 0x03, 0x9c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x61, 0x99, 0x80, 0x06, 0x01, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x61, 0x99, 0x80, 0x06, 0x00, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x76, 0x61, 0x99, 0x80, 0x06, 0x00, 0x60, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x61, 0x99, 0x80, 0x06, 0x00, 0x60, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc6, 0x63, 0x99, 0x80, 0x06, 0x00, 0x60, 0x63, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x86, 0x67, 0x19, 0x80, 0x06, 0x00, 0x60, 0x61, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0x6e, 0x19, 0xfe, 0x06, 0x00, 0x60, 0x60, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x06, 0x7c, 0x19, 0xfe, 0x06, 0x00, 0x60, 0x60, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_P(logo, false);
}
char keylog_str[24]  = {};
char keylogs_str[21] = {};
int  keylogs_str_idx = 0;

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

const char *read_keylog(void) { return keylog_str; }

const char *read_keylogs(void) { return keylogs_str; }
// new

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(PSTR("Default"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("Raise"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("Lower"), false);
                break;
            case _ADJUST:
                oled_write_ln_P(PSTR("Adjust"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);

    } else {
        render_logo();
    }
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}


