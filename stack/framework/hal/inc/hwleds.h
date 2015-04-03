/* * OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
 * lowpower wireless sensor communication
 *
 * Copyright 2015 University of Antwerp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \file leds.h
 *
 * \author maarten.weyn@uantwerpen.be
 * \author glenn.ergeerts@uantwerpen.be
 * \author daniel.vandenakker@uantwerpen.be
 *
 */

#ifndef __LEDS_H__
#define __LEDS_H__

#include "platform.h"

#ifndef HW_NUM_LEDS
    #warning the platform does not define HW_NUM_LEDS
#endif

#include "types.h"
#include "link_c.h"

/*! \brief Initialise the leds of the platform
 *
 *  This function initialises the leds of the platform. This function is NOT part of the
 *  'user' API and should only be called from the initialisation code of the specific platform
 *
 */
__LINK_C void __led_init();

/*! \brief Turn a led on
 *
 *  \param led_id The id of the led to turn on. This must be a number between 0
 * 		  and HW_NUM_LEDS. Out-of-range indexes are silently ignored
 *
 */
__LINK_C void led_on(uint8_t led_id);

/*! \brief Turn a led off
 *
 *  \param led_id The id of the led to turn off. This must be a number between 0
 * 		  and HW_NUM_LEDS. Out-of-range indexes are silently ignored
 *
 */
__LINK_C void led_off(uint8_t led_id);

/*! \brief Toggle a led. If it was on it is turned off and vice versa.
 *
 *  \param led_id The id of the led to toggle. This must be a number between 0
 * 		  and HW_NUM_LEDS. Out-of-range indexes are silently ignored
 *
 */
__LINK_C void led_toggle(uint8_t led_nr);

#endif // __LEDS_H__
