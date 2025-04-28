// Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "nicola.h" // NICOLA親指シフト
#include <timer.h>
#include "rgb_config.h" // RGB LEDの定義

enum keymap_layers {
  _QWERTY = 0,
  _JTU,
// NICOLA親指シフト入力レイヤー
  _NICOLA,
// FUNCTION
  _FUNC
};
_Bool L_QWERTY = 0;
_Bool L_JTU = 0;
_Bool L_NICOLA = 0;
_Bool L_FUNC = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * |Esc|   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|MUT|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┬───┤
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│HOM|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │DEL|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│Mnu|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Sft|   |Up │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│---│Spc│   |   |Alt|Mo1│Ctl│Lft│Dwn|Rgh
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */

    [_QWERTY] = LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,    KC_F6,      KC_F7,    KC_F8,       KC_F9,      KC_F10,   KC_F11,    KC_F12,    KC_JTU,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,        KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,   KC_HOME,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,     KC_SCLN,     KC_QUOT,              KC_ENT,    KC_APP,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,     KC_RSFT,               KC_UP,
        MO(_FUNC),  KC_LGUI,  KC_LALT,           KC_SPC,   KC_SPC,     KC_BSPC,                        KC_RALT,   MO(_FUNC),     KC_RCTL,  KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

     [_JTU] = LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,    KC_F6,      KC_F7,    KC_F8,       KC_F9,      KC_F10,   KC_F11,    KC_F12, KC_QWERTY,
         JU_GRV,     KC_1,     JU_2,     KC_3,     KC_4,     KC_5,        JU_6,     JU_7,       JU_8,     JU_9,        JU_0,     JU_MINS,   JU_EQL,   KC_BSPC,   KC_HOME,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,        KC_P,     JU_LBRC,  JU_RBRC,   JU_BSLS,    KC_DEL,
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,     JU_SCLN,     JU_QUOT,              KC_ENT,    KC_APP,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,     KC_SLSH,     KC_RSFT,               KC_UP,
        MO(_FUNC),  KC_LGUI,  KC_LALT,           KC_SPC,   KC_SPC,     KC_BSPC,                        KC_RALT,   MO(_FUNC),     KC_RCTL,  KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [_NICOLA] = LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,    KC_F6,      KC_F7,    KC_F8,       KC_F9,      KC_F10,   KC_F11,    KC_F12,   KC_EISU,
         KC_ESC,     NG_1,     NG_2,     NG_3,     NG_4,     NG_5,        NG_6,     NG_7,       NG_8,     NG_9,        NG_0,     NG_MINS,   NG_EQL,   KC_BSPC,   KC_HOME,
         KC_TAB,     NG_Q,     NG_W,     NG_E,     NG_R,     NG_T,        NG_Y,     NG_U,       NG_I,     NG_O,        NG_P,     NG_LBRC,  NG_RBRC,   NG_BSLS,    KC_DEL,
        KC_LCTL,     NG_A,     NG_S,     NG_D,     NG_F,     NG_G,        NG_H,     NG_J,       NG_K,     NG_L,     NG_SCLN,     NG_QUOT,              KC_ENT,    KC_APP,
        KC_LSFT,     NG_Z,     NG_X,     NG_C,     NG_V,     NG_B,        NG_N,     NG_M,    NG_COMM,   NG_DOT,     NG_SLSH,     KC_RSFT,               KC_UP,
        MO(_FUNC),  KC_LGUI,  KC_LALT,          NG_SHFTL,  _______,   NG_SHFTR,                        KC_RALT,   MO(_FUNC),     KC_RCTL,  KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [_FUNC] = LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,  KC_WHOM,  KC_WSCH,   LSG(KC_S),RCS(KC_ESC),  KC_MPRV,  KC_MNXT,     KC_MPLY,     KC_PSCR,  KC_SCRL,   KC_PAUS,   KC_MUTE,
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,      KC_F8,    KC_F9,      KC_F10,      KC_F11,   KC_F12,    KC_DEL,    KC_END,
        JU_CAPS,  _______,    KC_UP,  _______,  _______,  _______,     KC_HOME,  KC_PGDN,    KC_PGUP,   KC_END,     _______,     RGB_MOD, RGB_RMOD,   RGB_TOG,    KC_INS,
        _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,  _______,  _______,     KC_LEFT,  KC_DOWN,      KC_UP, KC_RIGHT,     RGB_SPD,     RGB_SPI,             _______,    KC_APP,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    RGB_VAD,  RGB_VAI,     RGB_HUI,     _______,             KC_PGUP,
        _______,  _______,  _______,            KC_EISU,  _______,    KC_KANA2,                        _______,     _______,     _______,  KC_HOME,   KC_PGDN,    KC_END
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_JTU] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NICOLA] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUNC] =   { ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP)}
};
#endif



void matrix_init_user(void) {
    L_QWERTY = 1;
    // NICOLA親指シフト
    set_nicola(_NICOLA);
    // NICOLA親指シフト
}

// Initialize the 13th LED
void keyboard_post_init_user(void) {
    nicola_off();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static bool lshift = false;//jtu-custom
    static bool rshift = false;//jtu-custom

    switch (keycode) {
#    ifdef RGB_MATRIX_ENABLE
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
         return false;
#    endif
        // 英数キー(Caps Lock)、nicola mode オフ
        case KC_EISU:
            if (record->event.pressed) {
                // send_string(SS_TAP(X_LNG2));
                // send_string(SS_LSFT(SS_TAP(X_CAPS_LOCK)));
                tap_code(KC_INT5);  // Win
                tap_code(KC_LNG2);  // Mac
            // #ifdef USE_OBSERVE_IME
                nicola_off();
                // layer_on(_JTU);
                L_NICOLA = 0;
                // L_JTU = 1;
            // #endif
            }
            return false;
        // 英数モードのとき左親指キー(KANA)で、nicola mode オン
        case KC_KANA2:
            if (record->event.pressed) {
                // send_string(SS_TAP(X_F14));
                tap_code(KC_INT2);  // Win
                tap_code(KC_LNG1);  // Mac
            // #ifdef USE_OBSERVE_IME
                nicola_on();
            // #endif
                L_NICOLA = 1;
            }
            return false;

        case KC_JTU:
            if (record->event.pressed) {
                layer_move(_JTU);
                L_QWERTY = 0;
                L_JTU = 1;
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                layer_move(_QWERTY);
                L_QWERTY = 1;
                L_JTU = 0;
            }
            return false;
        case KC_APP:
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (record->event.pressed) {
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_APP);
                    unregister_code(KC_APP);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_LGUI);
                    register_code(KC_F23);
                    unregister_code(KC_F23);
                    unregister_code(KC_LGUI);
                    unregister_code(KC_LSFT);
                }
            return false;
            }
    }

    // NICOLA親指シフト
    bool a = true;
    if (nicola_state()) {
        nicola_mode(keycode, record);
        a = process_nicola(keycode, record);
    }
    if (a == false) return false;


  // jtu-custom
  switch (keycode) {
    case JU_2:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_2);
          unregister_code(KC_2);
        }
      }
      return false;
      break;
    case JU_6:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_EQL);
          unregister_code(KC_EQL);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_6);
          unregister_code(KC_6);
        }
      }
      return false;
      break;
    case JU_7:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_6);
          unregister_code(KC_6);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_7);
          unregister_code(KC_7);
        }
      }
      return false;
      break;
    case JU_8:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_8);
          unregister_code(KC_8);
        }
      }
      return false;
      break;
    case JU_9:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_8);
          unregister_code(KC_8);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_9);
          unregister_code(KC_9);
        }
      }
      return false;
      break;
    case JU_0:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_0);
          unregister_code(KC_0);
        }
      }
      return false;
      break;
    case JU_MINS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_INT1);
          unregister_code(KC_INT1);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_MINS);
          unregister_code(KC_MINS);
        }
      }
      return false;
      break;
    case JU_EQL:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_MINS);
          unregister_code(KC_MINS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case JU_LBRC:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
        }
      }
      return false;
      break;
    case JU_RBRC:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_NUHS);
          unregister_code(KC_NUHS);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_NUHS);
          unregister_code(KC_NUHS);
        }
      }
      return false;
      break;
    case JU_BSLS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_INT3);
          unregister_code(KC_INT3);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_INT1);
          unregister_code(KC_INT1);
        }
      }
      return false;
      break;
    case JU_SCLN:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_SCLN);
          unregister_code(KC_SCLN);
        }
      }
      return false;
      break;
    case JU_QUOT:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_7);
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case JU_GRV:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_LSFT);
          register_code(KC_EQL);
          unregister_code(KC_EQL);
          unregister_code(KC_LSFT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    case JU_CAPS:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_CAPS);
          unregister_code(KC_CAPS);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_CAPS);
          unregister_code(KC_CAPS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
      break;
    // jtu-custom

  }

    return true;
}

// This function gets called at every matrix scan.
void matrix_scan_user(void) {

	uint32_t now = timer_read32();
	timer_tick(now);	// drive nicola state-machine.
}

// This function switches the LED pattern for each layer.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // rgb_matrix_set_color_all(0, 0, 0);
    // for (uint8_t i = led_min; i < led_max; i++)
    //     RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
    uint8_t va = rgb_matrix_get_val();
    if (va < 20) {
        va = 20;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 0, va, 0);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 0, 0, 0);
        }
    }

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            // RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 255, 255, 0); // nicola : off
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, va, va, va); //
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, va, va, va); //
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, va, va, va); //
            if (L_FUNC) {
                rgb_matrix_set_color_all(0, 0, 0);
                L_FUNC = 0;
            }
            break;
        case _JTU:
            // RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 255, 255, 0); // nicola : off
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, 0, 0, va);
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, 0, 0, va);
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, 0, 0, va);
            if (L_FUNC) {
                rgb_matrix_set_color_all(0, 0, 0);
                L_FUNC = 0;
            }
            break;
        case _NICOLA:
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, va, va, 0); // nicola : on
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, va, va, 0); // nicola : on
            RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, va, va, 0); // nicola : on
            if (L_FUNC) {
                rgb_matrix_set_color_all(0, 0, 0);
                L_FUNC = 0;
            }
            break;
        case _FUNC:
            L_FUNC = 1;
            if (L_NICOLA) {
                for (uint8_t i = 0; i < 14; i++) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, va, va, 0);
                }
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, va, va, 0); // nicola : on
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, va, va, 0); // nicola : on
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, va, va, 0); // nicola : on
                // if (!rgb_matrix_get_flags()) {
                //     for (uint8_t i = 0; i < 14; i++) {
                //         RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
                //     }
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, 0, 0, 0); //
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, 0, 0, 0); //
                // }
            } else if(L_QWERTY) {
                for (uint8_t i = 0; i < 14; i++) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, va, va, va);
                }
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, va, va, va);
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, va, va, va);
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, va, va, va);
                // if (!rgb_matrix_get_flags()) {
                //     for (uint8_t i = 0; i < 14; i++) {
                //         RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
                //     }
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, 0, 0, 0); //
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, 0, 0, 0); //
                // }
            } else if(L_JTU) {
                for (uint8_t i = 0; i < 14; i++) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, va);
                }
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, 0, 0, va);
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_CENTER_INDEX, 0, 0, va);
                RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, 0, 0, va);
                // if (!rgb_matrix_get_flags()) {
                //     for (uint8_t i = 0; i < 14; i++) {
                //         RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
                //     }
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_LEFT_INDEX, 0, 0, 0); //
                //     RGB_MATRIX_INDICATOR_SET_COLOR(OYA_RIGHT_INDEX, 0, 0, 0); //
                // }
            } else {
                for (uint8_t i = 0; i < 14; i++) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
                }
            }
            break;
    }
    return false;
}
