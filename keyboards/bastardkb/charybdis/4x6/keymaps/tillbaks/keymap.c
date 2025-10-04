/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#if defined(RGB_MATRIX_ENABLE)
#    include "rgb_layer.h"
#endif

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &ko_make_basic(MOD_MASK_SHIFT, KC_DOT, S(KC_SEMICOLON)),
    &ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON),
    &ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH),
};

enum my_keycodes {
    TG_OS_MODE = SAFE_RANGE,
    START_OF_MAPPED_KEYCODES,
    MAPPED_UNDO,             // CUSTOM(66) in VIA
    MAPPED_REDO,             // CUSTOM(67)
    MAPPED_CUT,              // CUSTOM(68)
    MAPPED_COPY,             // CUSTOM(69)
    MAPPED_PASTE,            // CUSTOM(70)
    MAPPED_WORD_PREV,        // CUSTOM(71)
    MAPPED_WORD_NEXT,        // CUSTOM(72)
    MAPPED_WORD_DELETE_PREV, // CUSTOM(73)
    MAPPED_WORD_DELETE_NEXT, // CUSTOM(74)
    MAPPED_UC_AO,            // CUSTOM(75)
    MAPPED_UC_AE,            // CUSTOM(76)
    MAPPED_UC_OE,            // CUSTOM(77)
    MAPPED_UC_UE,            // CUSTOM(78)
    MAPPED_BACK,             // CUSTOM(79)
    MAPPED_FORWARD,          // CUSTOM(80)
    MAPPED_TAB_NEW,          // CUSTOM(81)
    MAPPED_TAB_CLOSE,        // CUSTOM(82)
    MAPPED_TAB_PREV,         // CUSTOM(83)
    MAPPED_TAB_NEXT,         // CUSTOM(84)
    MAPPED_SAVE,             // CUSTOM(85)
    MAPPED_FIND,             // CUSTOM(86)
    MAPPED_SELECT_ALL,       // CUSTOM(87)
    MAPPED_ZOOM_IN,          // CUSTOM(88)
    MAPPED_ZOOM_OUT,         // CUSTOM(89)
    MAPPED_ZOOM_RESET,       // CUSTOM(90)
    MAPPED_LOCK_DESKTOP,     // CUSTOM(91)
    END_OF_MAPPED_KEYCODES
};

const uint16_t mapped_keys[][2] = {
    [MAPPED_UNDO - START_OF_MAPPED_KEYCODES] = {G(KC_Z), C(KC_Z)},
    [MAPPED_REDO - START_OF_MAPPED_KEYCODES] = {G(S(KC_Z)), C(KC_Y)},
    [MAPPED_CUT - START_OF_MAPPED_KEYCODES] = {G(KC_X), S(KC_DELETE)},
    [MAPPED_COPY - START_OF_MAPPED_KEYCODES] = {G(KC_C), C(KC_INS)},  
    [MAPPED_PASTE - START_OF_MAPPED_KEYCODES] = {G(KC_V), S(KC_INS)},
    [MAPPED_WORD_PREV - START_OF_MAPPED_KEYCODES] = {A(KC_LEFT), C(KC_LEFT)},
    [MAPPED_WORD_NEXT - START_OF_MAPPED_KEYCODES] = {A(KC_RIGHT), C(KC_RIGHT)},
    [MAPPED_WORD_DELETE_PREV - START_OF_MAPPED_KEYCODES] = {A(KC_BSPC), C(KC_BSPC)},
    [MAPPED_WORD_DELETE_NEXT - START_OF_MAPPED_KEYCODES] = {A(KC_DEL), C(KC_DEL)},
    [MAPPED_UC_AO - START_OF_MAPPED_KEYCODES] = {UC(0xE4), UC(0xE4)},
    [MAPPED_UC_AE - START_OF_MAPPED_KEYCODES] = {UC(0xE5), UC(0xE5)},
    [MAPPED_UC_OE - START_OF_MAPPED_KEYCODES] = {UC(0xF6), UC(0xF6)},
    [MAPPED_UC_UE - START_OF_MAPPED_KEYCODES] = {UC(0xFC), UC(0xFC)},
    [MAPPED_BACK - START_OF_MAPPED_KEYCODES] = {G(KC_LEFT), A(KC_LEFT)},
    [MAPPED_FORWARD - START_OF_MAPPED_KEYCODES] = {G(KC_RIGHT), A(KC_RIGHT)},
    [MAPPED_TAB_NEW - START_OF_MAPPED_KEYCODES] = {G(KC_T), C(KC_T)},
    [MAPPED_TAB_CLOSE - START_OF_MAPPED_KEYCODES] = {G(KC_W), C(KC_W)},
    [MAPPED_TAB_PREV - START_OF_MAPPED_KEYCODES] = {C(S(KC_TAB)), C(S(KC_TAB))},
    [MAPPED_TAB_NEXT - START_OF_MAPPED_KEYCODES] = {C(KC_TAB), C(KC_TAB)},
    [MAPPED_SAVE - START_OF_MAPPED_KEYCODES] = {G(KC_S), C(KC_S)},
    [MAPPED_FIND - START_OF_MAPPED_KEYCODES] = {G(KC_F), C(KC_F)},
    [MAPPED_SELECT_ALL - START_OF_MAPPED_KEYCODES] = {G(KC_A), C(KC_A)},
    [MAPPED_ZOOM_IN - START_OF_MAPPED_KEYCODES] = {G(KC_EQL), C(KC_EQL)},
    [MAPPED_ZOOM_OUT - START_OF_MAPPED_KEYCODES] = {G(KC_MINS), C(KC_MINS)},
    [MAPPED_ZOOM_RESET - START_OF_MAPPED_KEYCODES] = {G(KC_0), C(KC_0)},
    [MAPPED_LOCK_DESKTOP - START_OF_MAPPED_KEYCODES] = {G(C(KC_Q)), G(S(KC_Q))}
    // [MAPPED_OPEN - START_OF_MAPPED_KEYCODES]    = {G(KC_O), C(KC_O)},
    // [MAPPED_FIND_AGAIN - START_OF_MAPPED_KEYCODES]    = {G(KC_G), KC_F3},
    // [MAPPED_SCREEN_CAPTURE - START_OF_MAPPED_KEYCODES]    = {S(G(KC_4)), KC_PSCR},
    // [MAPPED_DOC_START - START_OF_MAPPED_KEYCODES]  = {G(KC_UP), C(KC_HOME)},
    // [MAPPED_DOC_END - START_OF_MAPPED_KEYCODES]  = {G(KC_DOWN), C(KC_END)},
    // [MAPPED_LINE_BEG - START_OF_MAPPED_KEYCODES] = {G(KC_DOWN), C(KC_END)},
    // [MAPPED_LINE_END - START_OF_MAPPED_KEYCODES] = {G(KC_DOWN), C(KC_END)},
    // [MAPPED_PARAGRAPH_PREV - START_OF_MAPPED_KEYCODES] = {A(KC_UP), C(KC_UP)},
    // [MAPPED_PARAGRAPH_NEXT - START_OF_MAPPED_KEYCODES] = {A(KC_DOWN), C(KC_DOWN)},
    // [MAPPED_APP_NEXT - START_OF_MAPPED_KEYCODES]  = {RGUI(KC_TAB), A(KC_TAB)},
    // [MAPPED_APP_PREV - START_OF_MAPPED_KEYCODES]  = {RGUI(RSFT(KC_TAB)), A(S(KC_TAB))},
    // [MAPPED_WIN_NEXT - START_OF_MAPPED_KEYCODES]  = {RCTL(KC_TAB), C(KC_TAB)},
    // [MAPPED_WIN_PREV - START_OF_MAPPED_KEYCODES]  = {RCTL(RSFT(KC_TAB)), C(S(KC_TAB))},
};

enum uint32_t { OS_MAC, OS_PC } OS_MODE;
typedef union {
    uint32_t raw;
    struct {
        uint32_t os_index; // 0 = MAC, 1 = PC (Windows/Linux)
    };
} user_config_t;

user_config_t user_config;
enum uint8_t { OFF, BLUE, GREEN } notification_rgb;
uint32_t notification_times;

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
#ifdef RGB_MATRIX_ENABLE
    rgb_post_init();
#endif
}

#define tap_mapped_key(keycode) tap_code16(mapped_keys[keycode - START_OF_MAPPED_KEYCODES][user_config.os_index])
#define register_mapped_key(keycode) register_code16(mapped_keys[keycode - START_OF_MAPPED_KEYCODES][user_config.os_index])
#define unregister_mapped_key(keycode) unregister_code16(mapped_keys[keycode - START_OF_MAPPED_KEYCODES][user_config.os_index])

bool process_mapped_key(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode >= START_OF_MAPPED_KEYCODES && keycode < END_OF_MAPPED_KEYCODES) {
            register_mapped_key(keycode);
            return false;
        }
        switch (keycode) {
            case KC_COPY:
                register_mapped_key(MAPPED_COPY);
                return false;
            case KC_PASTE:
                register_mapped_key(MAPPED_PASTE);
                return false;
            case KC_CUT:
                register_mapped_key(MAPPED_CUT);
                return false;
            case KC_UNDO:
                register_mapped_key(MAPPED_UNDO);
                return false;
            case KC_AGAIN:
                register_mapped_key(MAPPED_REDO);
                return false;
            case KC_WWW_BACK:
                register_mapped_key(MAPPED_BACK);
                return false;
            case KC_WWW_FORWARD:
                register_mapped_key(MAPPED_FORWARD);
                return false;
        }
    } else {
        if (keycode >= START_OF_MAPPED_KEYCODES && keycode < END_OF_MAPPED_KEYCODES) {
            unregister_mapped_key(keycode);
            return false;
        }
        switch (keycode) {
            case KC_COPY:
                unregister_mapped_key(MAPPED_COPY);
                return false;
            case KC_PASTE:
                unregister_mapped_key(MAPPED_PASTE);
                return false;
            case KC_CUT:
                unregister_mapped_key(MAPPED_CUT);
                return false;
            case KC_UNDO:
                unregister_mapped_key(MAPPED_UNDO);
                return false;
            case KC_AGAIN:
                unregister_mapped_key(MAPPED_REDO);
                return false;
            case KC_WWW_BACK:
                unregister_mapped_key(MAPPED_BACK);
                return false;
            case KC_WWW_FORWARD:
                unregister_mapped_key(MAPPED_FORWARD);
                return false;
        }
    }
    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_mapped_key(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case TG_OS_MODE:
            if (record->event.pressed) {
                if (user_config.os_index == OS_MAC) {
                    set_unicode_input_mode(UNICODE_MODE_LINUX);
                    user_config.os_index = OS_PC;
                    notification_rgb     = GREEN;
                    notification_times   = 150;
                } else {
                    set_unicode_input_mode(UNICODE_MODE_MACOS);
                    user_config.os_index = OS_MAC;
                    notification_rgb     = BLUE;
                    notification_times   = 150;
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
    }
    return true;
}

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_0 = 0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    LAYER_5,
    LAYER_6,
    LAYER_7,
};

/* LAYER_RGB_VAL moved to rgb_layer.h */

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_3

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define PT_Z LT(LAYER_3, KC_Z)
#define PT_SLSH LT(LAYER_3, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t
pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_3);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
    }

    void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_3);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#endif     // POINTING_DEVICE_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
#if defined(POINTING_DEVICE_ENABLE) && defined(CHARYBDIS_AUTO_SNIPING_ON_LAYER)
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
#endif
#if defined(RGB_MATRIX_ENABLE)
    set_layer_rgb(get_highest_layer(state));
#endif
    return state;
}
