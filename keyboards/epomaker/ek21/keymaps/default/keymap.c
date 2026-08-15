/* Copyright 2023 Yiancar-Designs
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
#include "../../lib/rdr_lib/rdr_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_MUTE,   KC_MUTE,  MO(2),    KC_TAB,   KC_BSPC,  KC_BSPC,
        KC_NUM,    KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_P7,     KC_P8,    KC_P9,    KC_PPLS,
        KC_P4,     KC_P5,    KC_P6,
        KC_P1,     KC_P2,    KC_P3,
        KC_P0,               KC_PDOT,  KC_PENT
    ),
    [1] = LAYOUT_tkl_ansi(
        KC_MUTE,   KC_MUTE,  MO(3),    KC_TAB,   KC_BSPC,  KC_BSPC,
        KC_NUM,    KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_P7,     KC_P8,    KC_P9,    KC_PPLS,
        KC_P4,     KC_P5,    KC_P6,
        KC_P1,     KC_P2,    KC_P3,
        KC_P0,               KC_PDOT,  KC_PENT
    ),
    [2] = LAYOUT_tkl_ansi(
        KC_MUTE,   KC_MUTE,  KC_NO,    TIME_ST,  RGB_RTOG,  RGB_RTOG,
        QK_DEB,    RGB_HUD,  RGB_HUI,  RGB_VAD,
        RGB_SPD,   RGB_SPI,  TO(1),    RGB_VAI,
        MD_24G,    RGB_SAI,  RGB_SAD,
        MD_BLE1,   MD_BLE2,  MD_BLE3,
        U_EE_CLR,            QK_BAT,   RGB_MOD
    ),
    [3] = LAYOUT_tkl_ansi(
        KC_MUTE,   KC_MUTE,  KC_NO,    TIME_ST,  RGB_RTOG,  RGB_RTOG,
        QK_DEB,    RGB_HUD,  RGB_HUI,  RGB_VAD,
        RGB_SPD,   RGB_SPI,  TO(0),    RGB_VAI,
        MD_24G,    RGB_SAI,  RGB_SAD,
        MD_BLE1,   MD_BLE2,  MD_BLE3,
        U_EE_CLR,            QK_BAT,   RGB_MOD
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [1] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [2] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [3] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI) }
};

#endif