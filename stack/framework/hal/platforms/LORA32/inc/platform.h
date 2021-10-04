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

#ifndef __PLATFORM_H_
#define __PLATFORM_H_

#include "platform_defs.h"

#ifndef PLATFORM_LORA32
    #error Mismatch between the configured platform and the actual platform. Expected PLATFORM_LORA32 to be defined
#endif



/** Platform BD drivers*/
extern blockdevice_t * const metadata_blockdevice;
extern blockdevice_t * const persistent_files_blockdevice;
extern blockdevice_t * const volatile_blockdevice;
#define PLATFORM_METADATA_BLOCKDEVICE metadata_blockdevice
#define PLATFORM_PERMANENT_BLOCKDEVICE persistent_files_blockdevice
#define PLATFORM_VOLATILE_BLOCKDEVICE volatile_blockdevice


#endif
