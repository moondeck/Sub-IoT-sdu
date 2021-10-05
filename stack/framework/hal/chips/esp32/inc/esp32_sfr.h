
/*
 * Copyright (c) 2021 Olgierd Nowakowski.
 * 
 * This file is part of Sub-IoT-sdu.
 * See https://github.com/moondeck/Sub-IoT-sdu for further info.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"))
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/*
 *
 *  TIMER 0 SECTION
 * 
 */

//timer 0 configuration register
#define TIMG0_T0CONFIG_REG *(0x3FF5F000)
#define TIMG1_T0CONFIG_REG *(0x3FF60000)

//timer 0 value low register
#define TIMG0_T0LO_REG *(0x3FF5F004)
#define TIMG1_T0LO_REG *(0x3FF60004)

//timer 0 value high register
#define TIMG0_T0HI_REG *(0x3FF5F008)
#define TIMG0_T0HI_REG *(0x3FF5F008)

//timer current value to TIMGn_T0_(LO/HI)_REG
#define TIMG0_T0UPDATE_REG *(0x3FF5F00C)
#define TIMG1_T0UPDATE_REG *(0x3FF6000C)

//timer 0 alarm value low 32 bits
#define TIMG0_T0ALARMLO_REG *(0x3FF5F00C)
#define TIMG1_T0ALARMLO_REG *(0x3FF6000C)

//timer 0 alarm value high 32 bits
#define TIMG0_T0ALARMHI_REG *(0x3FF5F014)
#define TIMG1_T0ALARMHI_REG *(0x3FF60014)

//timer 0 reload value, low 32 bits
#define TIMG0_T0LOADLO_REG *(0x3FF5F018)
#define TIMG1_T0LOADLO_REG *(0x3FF60018)

//timer 0 write-to-reload from TIMGn_T0_(LOADLOLOADHI)_REG 
#define TIMG0_T0LOAD_REG *(0x3FF5F020)
#define TIMG1_T0LOAD_REG *(0x3FF60020)

/*
 *
 *  TIMER 1 SECTION
 * 
 */

//timer 0 configuration register
#define TIMG0_T1CONFIG_REG *(0x3FF5F024)
#define TIMG1_T1CONFIG_REG *(0x3FF60024)

//timer 0 value low register
#define TIMG0_T1LO_REG *(0x3FF5F028)
#define TIMG1_T1LO_REG *(0x3FF60028)

//timer 0 value high register
#define TIMG0_T1HI_REG *(0x3FF5F02C)
#define TIMG0_T1HI_REG *(0x3FF5F02C)

//timer current value to TIMGn_T0_(LO/HI)_REG
#define TIMG0_T1UPDATE_REG *(0x3FF5F030)
#define TIMG1_T1UPDATE_REG *(0x3FF60030)

//timer 0 alarm value low 32 bits
#define TIMG0_T1ALARMLO_REG *(0x3FF5F034)
#define TIMG1_T1ALARMLO_REG *(0x3FF60034)

//timer 0 alarm value high 32 bits
#define TIMG0_T1ALARMHI_REG *(0x3FF5F038)
#define TIMG1_T1ALARMHI_REG *(0x3FF60038)

//timer 0 reload value, low 32 bits
#define TIMG0_T1LOADLO_REG *(0x3FF5F03C)
#define TIMG1_T1LOADLO_REG *(0x3FF6003C)

//timer 0 write-to-reload from TIMGn_T0_(LOADLOLOADHI)_REG 
#define TIMG0_T1LOAD_REG *(0x3FF5F044)
#define TIMG1_T1LOAD_REG *(0x3FF60044)

/*
 *
 *  WDT SECTION
 * 
 */

//watchdog timer configuration register
#define TIMG0_Tx_WDTCONFIG0_REG *(0x3FF5F048)
#define TIMG1_Tx_WDTCONFIG0_REG *(0x3FF60048)

//watchdog timer prescaler register
#define TIMG0_Tx_WDTCONFIG1_REG *(0x3FF5F04C)
#define TIMG1_Tx_WDTCONFIG1_REG *(0x3FF6004C)

//watchdog timer stage 0 timeout val
#define TIMG0_Tx_WDTCONFIG2_REG *(0x3FF5F050)
#define TIMG1_Tx_WDTCONFIG2_REG *(0x3FF60050)

//watchdog timer stage 1 timeout val
#define TIMG0_Tx_WDTCONFIG3_REG *(0x3FF5F054)
#define TIMG1_Tx_WDTCONFIG3_REG *(0x3FF60054)

//watchdog timer stage 2 timeout val        
#define TIMG0_Tx_WDTCONFIG4_REG *(0x3FF5F058)
#define TIMG1_Tx_WDTCONFIG4_REG *(0x3FF60058)

//watchdog timer stage 3 timeout val
#define TIMG0_Tx_WDTCONFIG5_REG *(0x3FF5F05C)
#define TIMG1_Tx_WDTCONFIG5_REG *(0x3FF6005C)

//watchdog timer write-to-feed
#define TIMG0_Tx_WDTFEED_REG *(0x3FF5F060)
#define TIMG1_Tx_WDTFEED_REG *(0x3FF60060)

//watchdog timer write protect reg
#define TIMG0_Tx_WDTFEED_REG *(0x3FF5F064)
#define TIMG1_Tx_WDTFEED_REG *(0x3FF60064)