//
// OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
// lowpower wireless sensor communication
//
// Copyright 2015 University of Antwerp
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "RadioPacket.h"


Register_Class(RadioPacket);

RadioPacket::RadioPacket(const char *name, int kind):RadioPacket_Base(name, kind)
{
}
RadioPacket::RadioPacket(const RadioPacket& other): RadioPacket_Base(other)
{
}

RadioPacket& RadioPacket::operator=(const RadioPacket& other)
{
	RadioPacket_Base::operator=(other);
	return *this;
}

RadioPacket *RadioPacket::dup() const
{
	return new RadioPacket(*this);
}

uint8_t* RadioPacket::getBufferPtr()
{
	return buffer_var;
}
