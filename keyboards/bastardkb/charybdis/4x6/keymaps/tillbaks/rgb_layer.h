#pragma once

#include <stdint.h>
#include <stdbool.h>

// Shared layer RGB brightness
#define LAYER_RGB_VAL 85

// Applies enable/disable + base mode for RGB Matrix according to active layer
void set_layer_rgb(uint8_t layer);

// Per-key indicators: lights only VIA-configured keys on the active layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max);

// Called from keyboard_post_init_user to set initial RGB state
void rgb_post_init(void);
