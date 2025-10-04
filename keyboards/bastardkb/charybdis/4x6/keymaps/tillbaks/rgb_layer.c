#include QMK_KEYBOARD_H
#include "rgb_layer.h"

#if defined(RGB_MATRIX_ENABLE)

static bool get_layer_hsv(uint8_t layer, HSV *out) {
    if (layer == 0) {
        return false; // base layer off
    }

    uint8_t hue = 0;
    uint8_t sat = 0;

    switch (layer) {
        case 1:
            hue = 0;
            sat = 255;
            break;
        case 2:
            hue = 170;
            sat = 255;
            break;
        case 3:
            hue = 85;
            sat = 255;
            break;
        case 4:
            hue = 191;
            sat = 255;
            break;
        case 5:
            hue = 43;
            sat = 255;
            break;
        case 6:
            hue = 128;
            sat = 255;
            break;
        case 7:
            hue = 0;
            sat = 0;
            break;
        default:
            hue = 0;
            sat = 0;
            break;
    }

    out->h = hue;
    out->s = sat;
    out->v = LAYER_RGB_VAL;
    return true;
}

void set_layer_rgb(uint8_t layer) {
    if (layer == 0) {
        rgb_matrix_disable_noeeprom();
        return;
    }

    // Enable matrix and select NONE so indicators control per-key LEDs
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv;
    uint8_t layer = get_highest_layer(layer_state);
    if (!get_layer_hsv(layer, &hsv)) {
        return false; // Base layer: keep LEDs off
    }

    RGB rgb = hsv_to_rgb(hsv);

    // Clear the range we are allowed to touch (QMK passes [led_min, led_max) bounds)
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }

    // Light only keys that are configured on the active layer (skip KC_TRNS/KC_NO)
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            keypos_t keypos = (keypos_t){.row = row, .col = col};
            uint16_t keycode = keymap_key_to_keycode(layer, keypos);
            if (keycode == KC_NO || keycode == KC_TRNS) {
                continue;
            }

            uint8_t index = g_led_config.matrix_co[row][col];
            if (index != NO_LED && index >= led_min && index < led_max) {
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }

    return false;
}

void rgb_post_init(void) {
    // Keep base layer off at startup
    rgb_matrix_disable_noeeprom();
}

#endif // RGB_MATRIX_ENABLE
