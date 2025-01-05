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
bool IS_BRETH = 1;
bool DIS_BL = 1;



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
        KC_LCTL,     NG_A,     NG_S,     NG_D,     NG_F,     NG_G,        NG_H,     NG_J,       NG_K,     NG_L,     NG_SCLN,     KC_BSPC,              KC_ENT,    KC_APP,
        KC_LSFT,     NG_Z,     NG_X,     NG_C,     NG_V,     NG_B,        NG_N,     NG_M,    NG_COMM,   NG_DOT,     NG_SLSH,     KC_RSFT,               KC_UP,
        MO(_FUNC),  KC_LGUI,  KC_LALT,          NG_SHFTL,  _______,   NG_SHFTR,                        KC_RALT,   MO(_FUNC),     KC_RCTL,  KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [_FUNC] = LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,  KC_WHOM,  KC_WSCH,   LSG(KC_S),RCS(KC_ESC),  KC_MPRV,  KC_MNXT,     KC_MPLY,     KC_PSCR,  KC_SCRL,   KC_PAUS,   KC_MUTE,
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,      KC_F8,    KC_F9,      KC_F10,      KC_F11,   KC_F12,    KC_DEL,    KC_END,
        JU_CAPS,  _______,    KC_UP,  _______,  _______,  _______,     KC_HOME,  KC_PGDN,    KC_PGUP,   KC_END,     _______,     _______,  BL_BRTG,   BL_TOGG,    KC_INS,
        _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,  _______,  _______,     KC_LEFT,  KC_DOWN,      KC_UP, KC_RIGHT,     _______,     _______,             _______,    KC_APP,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    BL_DOWN,    BL_UP,     _______,     _______,             KC_PGUP,
        _______,  _______,  _______,            KC_EISU,  _______,    KC_KANA2,                        _______,     _______,     _______,  KC_HOME,   KC_PGDN,    KC_END
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(C(KC_WH_D), C(KC_WH_U)), ENCODER_CCW_CW(G(C(KC_LEFT)),G(C(KC_RGHT))) },
    [_JTU] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(C(KC_WH_D), C(KC_WH_U)), ENCODER_CCW_CW(G(C(KC_LEFT)),G(C(KC_RGHT))) },
    [_NICOLA] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(C(KC_WH_D), C(KC_WH_U)), ENCODER_CCW_CW(G(C(KC_LEFT)),G(C(KC_RGHT))) },
    [_FUNC] =   { ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) }
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

    /* TODO:
    _FUNCレイヤーの場合、以下の処理を行う
    BL_DOWN, BL_UPが押されている間は全点灯する
    BL_TOGG, BL_BRTG, BL_STEPが押されている間は本来の発行パターンに戻す
    L_NICOLAが立っており、MO(_FUNC)以外のキーが押されていないとき、全点灯する
    L_NICOLAが立っておらず、MO(_FUNC)以外のキーが押されていないとき、全消灯する
    */

    switch (keycode) {
        case MO(_FUNC):
            if (record->event.pressed) {
                L_FUNC = 0;
                IS_BRETH = is_backlight_breathing();
                DIS_BL = !(is_backlight_enabled());
                // if(L_NICOLA) {
                //     backlight_enable();
                //     backlight_disable_breathing();
                // } else {
                //     backlight_disable_breathing();
                //     backlight_disable();
                // }
            } else {
                // L_FUNC = 1;
                // if (IS_BRETH) {
                //     backlight_enable_breathing();
                // } else {
                //     backlight_disable_breathing();
                // }
                // if (DIS_BL) {
                //     backlight_disable();
                // } else {
                //     backlight_enable();
                // }
            }
            return true;
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
                // backlight_disable();
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
                // backlight_enable();
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
        // case BL_TOGG:
        //     if (record->event.pressed) {
        //         DIS_BL = !DIS_BL;
        //         if(DIS_BL) {
        //             backlight_disable_breathing();
        //             backlight_disable();
        //         } else {
        //             backlight_enable();
        //             if(IS_BRETH) {
        //                 backlight_enable_breathing();
        //             }
        //         }
        //     } else {
        //         if(L_NICOLA) {
        //             backlight_enable();
        //             backlight_disable_breathing();
        //         } else {
        //             backlight_disable();
        //             backlight_disable_breathing();
        //         }
        //     }
        //     return false;
        // case BL_BRTG:
        //     if (record->event.pressed) {
        //         IS_BRETH = !IS_BRETH;
        //         if(DIS_BL){
        //             backlight_disable();
        //             backlight_disable_breathing();
        //         } else if(IS_BRETH) {
        //             backlight_enable();
        //             backlight_enable_breathing();
        //         } else {
        //             backlight_enable();
        //             backlight_disable_breathing();
        //         }
        //     } else {
        //         if(L_NICOLA){
        //             backlight_disable_breathing();
        //             backlight_enable();
        //         } else {
        //             backlight_disable_breathing();
        //             backlight_disable();
        //         }
        //     }
        //     return false;
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

