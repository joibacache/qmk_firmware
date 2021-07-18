/* Copyright 2020 Victor Lucachi
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _ILUSTRATOR,
    _CALC,
    _PHOTOSHOP,
    _FN,
};

enum custom_keycodes {
    IL_UNDO = SAFE_RANGE,
    IL_REDO,
    IL_NWDOC,
    IL_FOPEN,
    IL_SAVE,
    IL_SAVEAS,
    IL_ZOOMIN,
    IL_ZOOMOUT,
    PS_TRSLIBRE,
    PS_PINCPLUS,
    PS_PINCMINUS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case IL_UNDO:
                // CTRL+Z
                // tap_code16(LCTL(KC_Z));
                tap_code16(LGUI(KC_Z));
                break;
            case IL_REDO:
                // Mayús + Ctrl + Z
                // tap_code16(LSFT(LCTL(KC_Z)));
                tap_code16(LSFT(LGUI(KC_Z)));
                break;
            case IL_NWDOC:
                //Ctrl + N
                // tap_code16(LCTL(KC_N));
                tap_code16(LCTL(KC_N));
                break;
            case IL_FOPEN:
                //Ctrl + O
                // tap_code16(LCTL(KC_O));
                tap_code16(LGUI(KC_O));
                break;
            case IL_SAVE:
                // Ctrl + S
                // tap_code16(LCTL(KC_S));
                tap_code16(LGUI(KC_S));
                break;
            case IL_SAVEAS:
                // Mayús + Ctrl + S
                // tap_code16(LSFT(LCTL(KC_S)));
                tap_code16(LSFT(LGUI(KC_S)));
                break;
            case IL_ZOOMIN:
                // Ctrl + "+"
                // tap_code16(LCTL(KC_KP_PLUS));
                tap_code16(LGUI(KC_KP_PLUS));
                break;
            case IL_ZOOMOUT:
                // Ctrl + "-"
                // tap_code16(LCTL(KC_KP_MINUS));
                tap_code16(LGUI(KC_KP_MINUS));
                break;
            case PS_TRSLIBRE:
                // Ctrl + T
                // tap_code16(LCTL(KC_T));
                tap_code16(LGUI(KC_T));
                break;
            case PS_PINCPLUS:
                register_code16(LALT(KC_LBRACKET));
                break;
            case PS_PINCMINUS:
                register_code16(LALT(KC_RBRACKET));
                break;
        }
    } 
    else 
    {
        switch (keycode) {
            case PS_PINCPLUS:
                clear_keyboard();
                break;
            case PS_PINCMINUS:
                clear_keyboard();
                break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,---------------------------.
 * |ILSTR |PHTSHP|      | CALC |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |  FN  |      |      |      |
 * `---------------------------'
 */
[_BASE] = LAYOUT_ortho_4x4(
    DF(_ILUSTRATOR),    DF(_PHOTOSHOP),  KC_NO,  DF(_CALC),
    KC_NO,              KC_NO,  KC_NO,  KC_NO,
    KC_NO,              KC_NO,  KC_NO,  KC_NO,
    TT(_FN),            KC_NO,  KC_NO,  KC_NO
),

/* ILUSTRATOR
 * ,---------------------------.
 * | UNDO | REDO | NWDOC|FOPEN |
 * |------+------+------+------|
 * | SAVE |SAVEAS|ZOOM+ |ZOOM- |
 * |------+------+------+------|
 * | LAZO | PLUMA|CTAGTA| MANO |
 * |------+------+------+------|
 * |TIJERA|  CMD |TRSLBR|BASEL |
 * `---------------------------'
 */
[_ILUSTRATOR] = LAYOUT_ortho_4x4(
    IL_UNDO,    IL_REDO,    IL_NWDOC,   IL_FOPEN,
    IL_SAVE,    IL_SAVEAS,  IL_ZOOMIN,  IL_ZOOMOUT,
    KC_Q,       KC_P,       KC_I,       KC_H,
    KC_C,       KC_LGUI,    KC_E,       DF(_BASE)
),

/* CALC
 * ,---------------------------.
 * |   7  |   8  |   9  |   *  |
 * |------+------+------+------|
 * |   4  |   5  |   6  |   -  |
 * |------+------+------+------|
 * |   1  |   2  |   3  |   +  |
 * |------+------+------+------|
 * |   0  |   /  |   =  |BASEL |
 * `---------------------------'
 */
[_CALC] = LAYOUT_ortho_4x4(
    KC_KP_7,    KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK,
    KC_KP_4,    KC_KP_5,        KC_KP_6,        KC_KP_MINUS,
    KC_KP_1,    KC_KP_2,        KC_KP_3,        KC_KP_PLUS,
    KC_KP_0,    KC_KP_SLASH,    KC_KP_EQUAL,    DF(_BASE)
),

/* PHOTOSHOP
 * ,---------------------------.
 * | UNDO | REDO |NWDOC |FOPEN |
 * |------+------+------+------|
 * |PINCEL|CLONAR|ZOOM+ |ZOOM- |
 * |------+------+------+------|
 * | LAZO |PLUMA |BORRAR| MANO |
 * |------+------+------+------|
 * | VMAG |RECORT|TRSLBR|BASEL |
 * `---------------------------'
 */
[_PHOTOSHOP] = LAYOUT_ortho_4x4(
    IL_UNDO,    IL_REDO,    IL_NWDOC,       IL_FOPEN,
    KC_B,       KC_S,       IL_ZOOMIN,      IL_ZOOMOUT,
    KC_L,       KC_P,       KC_E,           KC_H,
    KC_W,       KC_C,       PS_TRSLIBRE,    DF(_BASE)
),


/* FN
 * ,---------------------------.
 * | RESET|      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * |------+------+------+------|
 * |      |      |      |      |
 * `---------------------------'
 */
[_FN] = LAYOUT_ortho_4x4(
    RESET,   KC_NO,   KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,    KC_NO
)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return true;
}