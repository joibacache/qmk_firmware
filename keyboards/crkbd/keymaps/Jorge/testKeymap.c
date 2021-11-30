#define SPACE_FN LT(_SPACE_FN, KC_SPC)
#define VS_PREV RCTL(KC_MINS)
#define VS_NEXT RCS(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------+      +-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+      +------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+      +------+------+------+------+------+------|
 * | LCtrl|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |      |SftEnt|
 * `------+------+------+------+------+------+      +------+------+------+------+------+------'
 *                      | LAlt | Lower|SpcSFT|      |SpaceF| Raise|   /  |
 *                      `--------------------'      `--------------------'
 */ 

[_QWERTY] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,           KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G,           KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_N, KC_M, KC_COMM, KC_DOT, KC_NO,   KC_SFTENT,
    KC_LALT, MO(_LOWER), SFT_T(KC_SPC)               SPACE_FN,MO(_RAISE), KC_SLSH  
),

/* Lower
* ,-----------------------------------------+      +-----------------------------------------.
* |   ~  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |
* `------+------+------+------+------+------+      +------+------+------+------+------+------'
*                      | LAlt | Lower|      |      |SpaceF| Raise|      |
*                      `--------------------'      `--------------------'
*/

[_LOWER] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,            KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,           KC_F12,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_LALT, MO(_LOWER), KC_NO                                  SPACE_FN,MO(_RAISE), KC_NO
),

/* Raise
* ,-----------------------------------------+      +-----------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 | Del  |      |      |      |      |
* `------+------+------+------+------+------+      +------+------+------+------+------+------'
*                      | LAlt | Lower|      |      |SpaceF| Raise|      |
*                      `--------------------'      `--------------------'
*/

[_RAISE] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_1,  KC_2, KC_3,   KC_4,   KC_5,         KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,        KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,       KC_F12, KC_DEL,  KC_BSPC, KC_PGUP, KC_VOLU, KC_PGDN,
    KC_LALT, MO(_LOWER), KC_NO                          SPACE_FN,MO(_RAISE), KC_NO
),

/* Adjust (Lower + Raise)
* ,-----------------------------------------+      +-----------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* |RGB_TG|RGB_H+|RGB_S+|RGB_V+|      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* |RGB_MD|RGB_H-|RGB_S-|RGB_V-|      |      |      |      |      |      |      |      |      |
* `------+------+------+------+------+------+      +------+------+------+------+------+------'
*                      |      |      |      |      |      |      |      |
*                      `--------------------'      `--------------------'
*/

[_ADJUST] = LAYOUT_split_3x6_3(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO,
),



/* Space fn
* ,-----------------------------------------+      +-----------------------------------------.
* |PRNTSC|      |      | Home |  UP  | End  |      | Home |  UP  | End  |      |      | Bksp |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* | Del  |      |      | LEFT | DOWN | RIGHT|      | LEFT | DOWN |RIGHT | Mute | Vol+ |      |
* |------+------+------+------+------+------+      +------+------+------+------+------+------|
* |LCtrl |      |      |      |      |      |      |VSPREV| Play | Prev | Next | Vol- |      |
* `------+------+------+------+------+------+      +------+------+------+------+------+------'
*                      | LAlt |      |LShift|      |SpaceF|      |      |
*                      `--------------------'      `--------------------'
*/

[_SPACE_FN] = LAYOUT_split_3x6_3(
    LSG(KC_S), KC_NO, KC_NO, KC_HOME, KC_UP,   KC_END,            KC_HOME, KC_UP,   KC_END,   KC_NO,   KC_NO,   KC_BSPC
    KC_DEL,    KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,          KC_LEFT, KC_DOWN, KC_RIGHT, KC_MUTE, KC_VOLU, KC_NO
    KC_LCTL,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,             VS_PREV, KC_MPLY, KC_MPRV,  KC_MNXT, KC_VOLD, KC_NO,
    KC_LALT,   KC_NO, KC_LSFT                                     SPACE_FN, KC_NO, KC_NO
)
};