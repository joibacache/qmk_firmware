/* Copyright 2021 Jorge Ibacache
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
#include <keymap_spanish.h>
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    /*
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-------+-------+-------+----------------------------+
    | Esc |   | F1  | F2  | F3  | F4  |   | F5  | F6  | F7  | F8  |   | F9  | F10 | F11 | F12 |   | PrtSc | ScrLk | Pause |                            |
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+   +-------+-------+-------+   +------+-----+-----+-----+
    |  º  | 1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  '  |  ¡  |     BkSp    |   |  Ins  |  Home |  PgUp |   | Num  |  /  |  *  |  -  |
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+   +-------+-------+-------+   +------+-----+-----+-----+
    | Tab  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  `  |  +  |    Ent   |   |  Del  |  End  |  PgDn |   |   7  |  8  |  9  |     |
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+--------+        +   +-------+-------+-------+   +------+-----+-----+  +  +
    |CapsLock|  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ñ  |  ´  |  ç  |        |                               |   4  |  5  |  6  |     |
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+-----------------+           +-------+           +------+-----+-----+-----+
    |Shift|  <>  |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  -  |      Shift     |           |   Up  |           |   1  |  2  |  3  |     |
    +-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+---+-----+-----+-----+-----+     +-----+-------+-----+     +------+-----+-----+ ENT +
    |Ctrl |  Win  |  Alt  |                  Space                  | AltGr | Fn | Menu | Ctrl|     | Left|  Down |Right|     |      0     | Del |     |
    +-----+-------+-------+-----------------------------------------+-------+----+------+-----+-----+-----+-------+-----+-----+------------+-----+-----+
    */
    
   [_BASE] = LAYOUT(
		KC_ESC,  KC_NO,   KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
		KC_TAB,  KC_NO,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O, 
		KC_CAPS, KC_NO,   KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
		KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_NO,  KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
		
        KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_MINS, KC_EQL,  KC_NO,   KC_BSPC,KC_INS,  KC_HOME, KC_PGUP, KC_NLCK, KC_SLSH, KC_ASTR, KC_MINS,
		KC_P,    KC_LBRC, KC_RBRC, KC_ENT, KC_DEL,  KC_END,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PLUS, 
		KC_SCLN, KC_QUOT, KC_HASH, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_NO, 
		KC_SLSH, KC_NO,   KC_LSFT, KC_NO,  KC_NO,   KC_UP,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LGUI, KC_MENU, KC_NO,   KC_LCTL, KC_LEFT,KC_DOWN, KC_RIGHT,KC_P0,   KC_NO,   KC_PDOT, KC_NO

        // KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS,KC_SLCK,KC_PSCR,KC_F12,KC_F11,KC_F10,KC_F9,
        // KC_MINS,KC_ASTR,KC_SLSH,KC_NLCK,KC_PGUP,   KC_HOME, KC_INS,KC_BSPC, KC_NO,   KC_EQL, KC_MINS,
        // KC_PLUS, KC_P9,   KC_P8,   KC_P7,   KC_PGDN,   KC_END,   KC_DEL,KC_ENT,KC_RBRC, KC_LBRC, KC_P,    
        // KC_SCLN,KC_QUOT,KC_HASH,  KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_P4,    KC_P5,      KC_P6,KC_NO, 
		// KC_PENT,KC_P3,   KC_P2,   KC_P1,   KC_NO,   KC_UP,   KC_NO,   KC_NO,  KC_LSFT, KC_NO,   KC_SLSH, 
		// KC_LGUI,  KC_NO, KC_PDOT,  KC_NO,    KC_P0,    KC_RIGHT, KC_DOWN,  KC_LEFT,KC_LCTL, KC_NO,   KC_MENU

    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
