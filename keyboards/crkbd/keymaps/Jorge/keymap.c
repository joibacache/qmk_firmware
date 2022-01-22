#include QMK_KEYBOARD_H
#include <stdio.h>

enum corne_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE_FN,
  _MAC
};

enum corne_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MAC
};
#define SPACE_FN LT(_SPACE_FN, KC_SPC)
// #define SHIFT_SPC MT(MOD_LSFT, KC_SPC)
#define VS_PREV RCTL(KC_MINS)
#define VS_NEXT RCS(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY - WINDOWS
 * ,-----------------------------------------+            +-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |            |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+            +------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |            |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+            +------+------+------+------+------+------|
 * | LCtrl|   Z  |   X  |   C  |   V  |   B  |            |   N  |   M  |   ,  |   .  |      |SftEnt|
 * `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
 *                         | LAlt | Lower|SpcSFT|      |SpaceF| Raise|   /  |
 *                         `--------------------'      `--------------------'
 */ 

[_QWERTY] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A,  KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,  KC_X, KC_C, KC_V, KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT, KC_NO,   KC_SFTENT,
    KC_LALT, LOWER, KC_LCTL,                              SPACE_FN, RAISE, KC_SLSH  
),

/* QWERTY - MAC
 * ,-----------------------------------------+            +-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |            |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+            +------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |            |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+            +------+------+------+------+------+------|
 * | LCtrl|   Z  |   X  |   C  |   V  |   B  |            |   N  |   M  |   ,  |   .  |      |SftEnt|
 * `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
 *                         | LAlt | Lower|SpcSFT|      |SpaceF| Raise|   /  |
 *                         `--------------------'      `--------------------'
 */ 

[_MAC] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_TAB,  KC_A,  KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LGUI, KC_Z,  KC_X, KC_C, KC_V, KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT, KC_NO,   KC_SFTENT,
    KC_LALT, LOWER, KC_NO,                              SPACE_FN, RAISE, KC_SLSH  
),

    
/* Lower
* ,-----------------------------------------+            +-----------------------------------------.
* |   ~  |   !  |   @  |   #  |   $  |   %  |            |   ^  |   &  |   *  |   (  |   )  | Bksp |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |            |  F6  |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |            |  F12 |      |      |      |      |      |
* `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
*                         | LAlt | Lower|      |      |SpaceF| Raise|      |
*                         `--------------------'      `--------------------'
*/

[_LOWER] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,        KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,       KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LALT, LOWER, KC_NO,                                  SPACE_FN,RAISE, KC_NO
),

    
/* Raise
* ,-----------------------------------------+            +-----------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |            |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |            |  F6  |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |            |  F12 | Del  |      |      |      |      |
* `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
*                         | LAlt | Lower|      |      |SpaceF| Raise|      |
*                         `--------------------'      `--------------------'
*/

[_RAISE] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_1,  KC_2, KC_3,   KC_4,   KC_5,             KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,            KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,           KC_F12, KC_DEL,  KC_BSPC, KC_PGUP, KC_VOLU, KC_PGDN,
    KC_LALT, LOWER, KC_NO,                                  SPACE_FN, RAISE, KC_NO
),

    
/* Adjust (Lower + Raise)
* ,-----------------------------------------+            +-----------------------------------------.
* |  MAC |      |      |      |      |      |            |      |      |      |      |      |      |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* |RGB_TG|RGB_H+|RGB_S+|RGB_V+|      |      |            |      |      |      |      |      |      |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* |RGB_MD|RGB_H-|RGB_S-|RGB_V-|      |      |            |      |      |      |      |      |      |
* `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
*                         |      |      |      |      |      |      |      |
*                         `--------------------'      `--------------------'
*/

[_ADJUST] = LAYOUT_split_3x6_3(
    MAC,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO
),

    
/* Space fn
* ,-----------------------------------------+            +-----------------------------------------.
* |PRNTSC|RGB_H+|RGB_H-| Home |  UP  | End  |            | Home |  UP  | End  |      |      | Bksp |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* | Del  |RGB_S+|RGB_S-|LEFT  | DOWN | RIGHT|            | LEFT | DOWN |RIGHT | Mute | Vol+ |      |
* |------+------+------+------+------+------+            +------+------+------+------+------+------|
* |LCtrl |RGB_V+|RGB_V-|      |      |RGB_MD|            |VSPREV| Play | Prev | Next | Vol- |      |
* `------+------+------+--+------+---+--+------+      +--+------+---+--+---+--+------+------+------'
*                         | LAlt |      |LShift|      |SpaceF|RGB_TG|RGB_MD|
*                         `--------------------'      `--------------------'
*/

[_SPACE_FN] = LAYOUT_split_3x6_3(
    LSG(KC_S), RGB_HUI, RGB_HUD, KC_HOME, KC_UP,   KC_END,        KC_HOME, KC_UP,   KC_END,   KC_NO,   KC_NO,   KC_BSPC,
    KC_DEL,    RGB_SAI, RGB_SAD, KC_LEFT, KC_DOWN, KC_RIGHT,      KC_LEFT, KC_DOWN, KC_RIGHT, KC_MUTE, KC_VOLU, KC_NO,
    KC_LSFT,   RGB_VAI, RGB_VAD, KC_NO,   KC_NO,   RGB_MOD,       VS_PREV, KC_MPLY, KC_MPRV,  KC_MNXT, KC_VOLD, KC_NO,
    KC_LALT,   KC_LGUI, KC_LCTL,                                    SPACE_FN, RGB_TOG, RGB_MOD
)
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  // if (!is_keyboard_master()) {
  //   return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  // }
   
  return rotation;
} 

#define L_QWERTY 0
#define L_COLEMAK 1
#define L_LOWER 2
#define L_RAISE 3
#define L_ADJUST 4
#define L_SPACE_FN 5
#define L_MAC 6


void oled_render_layer_state(void) {
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state)) {
        case  _QWERTY:
            oled_write_ln_P(PSTR("QWERTY - WIN"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLEMAK - WIN"), false);
            break;
        case _MAC:
            oled_write_ln_P(PSTR("QWERTY - MAC"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJUST"), false);
            break;
          case _SPACE_FN:
            oled_write_ln_P(PSTR("SPACE FN"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  // if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))
  // { 
  //   keycode = keycode & 0xFF; 
  // }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf( keylog_str, 
            sizeof(keylog_str), 
            "(%dx,%d), kc%2d : %c",
            record->event.key.row, 
            record->event.key.col,
            keycode, 
            name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
  #ifdef OLED_ENABLE
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
  #endif

  switch (keycode) {
    case LOWER:
      record -> event.pressed ? layer_on(_LOWER) : layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
    
    case RAISE:
      record -> event.pressed ? layer_on(_RAISE) : layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;

    case MAC:
      record -> event.pressed ? layer_on(_MAC) : layer_off(_MAC);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}
