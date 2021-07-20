#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |SftEnt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | LGUI | LCtrl| LAlt | Lower|    Space    | Raise|   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */ 
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,     KC_Q,     KC_W,     KC_E,     KC_R,       KC_T, KC_Y,   KC_U,       KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,     KC_A,     KC_S,     KC_D,     KC_F,       KC_G, KC_H,   KC_J,       KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,       KC_B, KC_N,   KC_M,       KC_COMM,  KC_DOT,   KC_UP,    KC_SFTENT,
    KC_NO,      KC_LGUI,  KC_LCTL,  KC_LALT,  MO(_LOWER),    KC_SPC,    MO(_RAISE), KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
),

/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home |      | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Play    |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_TRNS,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_NO,  KC_END,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_MPLY,     KC_TRNS,    KC_MPRV,    KC_VOLD, KC_VOLU, KC_MNXT
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Del  | Bksp |Pg Up |      |Pg Dn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Play    |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, KC_PGUP, KC_NO, KC_PGDN,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_MPLY,     KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust
* ,-----------------------------------------------------------------------------------.
 * |RESET |      |MS_UP |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MS_LFT|MS_DWN|MS_RGT|      |      |MS_BT1|MS_BT2|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |MS_BT1| MS_UP|MS_BT2|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |MS_LFT|MS_DWN|MS_RGT|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    RESET,  KC_NO,      KC_MS_UP,   KC_NO,        KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,      KC_NO,
    KC_NO,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,  KC_NO,  KC_NO,  KC_MS_BTN1, KC_MS_BTN2, KC_NO,  KC_NO,      KC_NO,      KC_NO,
    KC_NO,  KC_NO,      KC_NO,      KC_NO,        KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,  KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,
    KC_NO,  KC_NO,      KC_NO,      KC_NO,        KC_NO,       KC_NO,         KC_NO,      KC_NO,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
}