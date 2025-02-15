/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef _XPT2046_H
#define _XPT2046_H

#include "esp_log.h"
#include "touch_panel.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initial touch panel
 *
 * @param config Pointer to a structure with touch config arguments.
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_init(const touch_panel_config_t *xpt_conf);

/**
 * @brief Deinitial touch panel
 * 
 * @param free_bus Is free bus
 * 
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_deinit(void);

/**
 * @brief Check if there is a press
 * 
 * @return 
 *      - 0 Not press
 *      - 1 pressed
 */
int xpt2046_is_pressed(void);

/**
 * @brief Set touch rotate direction
 * 
 * @param dir rotate direction
 * 
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail 
 */
esp_err_t xpt2046_set_direction(touch_panel_dir_t dir);

/**
 * @brief Get raw data
 * 
 * @param x Value of X axis direction
 * @param y Value of Y axis direction
 * 
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail 
 */
esp_err_t xpt2046_get_rawdata(uint16_t *x, uint16_t *y);

/**
 * @brief Start run touch panel calibration
 * 
 * @param screen LCD driver for display prompts
 * @param recalibrate Is calibration mandatory
 * 
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail 
 */
esp_err_t xpt2046_calibration_run(const scr_driver_t *screen, bool recalibrate);

/**
 * @brief Start a sample for screen
 *
 * @param info a pointer of touch_panel_points_t contained touch information.
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_sample(touch_panel_points_t* info);

/**
 * @brief Get the temperature from the touchscreen controller
 *
 * @param temperature a pointer to a float to store the temperature in degrees C
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_get_temp_deg_c(float* temperature);

/**
 * @brief Get the voltage on the battery pin from the touchscreen controller
 *
 * @param voltage a pointer to a float to store the voltage in V
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_get_batt_v(float* voltage);

/**
 * @brief Get the voltage on the aux pin from the touchscreen controller
 *
 * @param voltage a pointer to a float to store the voltage in V
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 */
esp_err_t xpt2046_get_aux_v(float* voltage);


#ifdef __cplusplus
}
#endif

#endif
