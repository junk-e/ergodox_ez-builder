#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define CODE 1
#define MDIA 2 // media keys
#define NPAD 3

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

// Define keycode alias
#define XXXXXXXX KC_NO
#define ________ KC_TRNS
#define A_MEH MEH_T(KC_NO)
#define A_IME LCTL(KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
    // Left
    /**/ KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_MINS ,
    /**/ KC_GRV  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , TG(MDIA),
    /**/ KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,
    /**/ KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , A_MEH   ,
    /**/ KC_LCTRL, KC_LALT , XXXXXXXX, XXXXXXXX, XXXXXXXX,

    /**/                                                   A_IME   , KC_ESC  ,
    /**/                                                             KC_LSFT ,
    /**/                                         KC_LGUI , KC_SPC  , MO(MDIA),

    // Right
    /**/ KC_EQL  , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
    /**/ TG(CODE), KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
    /**/           KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    /**/ TG(NPAD), KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    /**/                     XXXXXXXX, KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT,

    /**/ XXXXXXXX, XXXXXXXX,
    /**/ KC_RCTRL,
    /**/ MO(CODE), KC_ENT  , KC_BSPC
),

[CODE] = LAYOUT_ergodox(
    // Left
    /**/ ________, ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________, KC_MINS , ________,
    /**/ ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________,

    /**/                                                   ________, ________,
    /**/                                                             ________,
    /**/                                         ________, ________, ________,

    // Right
    /**/ ________, ________, ________, ________, KC_LPRN , KC_RPRN , ________,
    /**/ ________, KC_EQL  , ________, ________, KC_LBRC , KC_RBRC , ________,
    /**/           ________, ________, ________, KC_LCBR , KC_RCBR , ________,
    /**/ ________, ________, ________, ________, KC_LABK , KC_RABK , ________,
    /**/                     ________, ________, ________, ________, ________,

    /**/ ________, ________,
    /**/ ________,
    /**/ ________, ________, ________
),

[MDIA] = LAYOUT_ergodox(
    // Left
    /**/ ________, KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , RESET   ,
    /**/ XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_MS_U , XXXXXXXX, XXXXXXXX, ________,
    /**/ ________, XXXXXXXX, KC_MS_L , KC_MS_D , KC_MS_R , XXXXXXXX,
    /**/ ________, XXXXXXXX, XXXXXXXX, KC_BTN1 , KC_BTN2 , XXXXXXXX, ________,
    /**/ KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, ________,

    /**/                                                   ________, ________,
    /**/                                                             ________,
    /**/                                         ________, ________, ________,

    // Right
    /**/ XXXXXXXX, KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    /**/ ________, ________, KC_VOLD , KC_VOLU , KC_MUTE , XXXXXXXX, KC_F12  ,
    /**/           KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, XXXXXXXX, XXXXXXXX,
    /**/ ________, XXXXXXXX, XXXXXXXX, KC_MPLY , KC_MPRV , KC_MNXT , ________,
    /**/                     ________, KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXXX,

    /**/ ________, ________,
    /**/ ________,
    /**/ ________, ________, ________
),

[NPAD] = LAYOUT_ergodox(
    // Left
    /**/ ________, ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________, ________, ________,
    /**/ ________, ________, ________, ________, ________,

    /**/                                                   ________, ________,
    /**/                                                             ________,
    /**/                                         ________, ________, ________,

    // Right
    /**/ XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_NLCK ,
    /**/ ________, XXXXXXXX, KC_P7   , KC_P8   , KC_P9   , KC_PSLS , XXXXXXXX,
    /**/           XXXXXXXX, KC_P4   , KC_P5   , KC_P6   , KC_PAST , XXXXXXXX,
    /**/ ________, XXXXXXXX, KC_P1   , KC_P2   , KC_P3   , KC_PMNS , XXXXXXXX,
    /**/                     KC_P0   , KC_PDOT , KC_PEQL , KC_PPLS , XXXXXXXX,

    /**/ ________, ________,
    /**/ ________,
    /**/ ________, ________, ________
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
