# 
# OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
# lowpower wireless sensor communication
#
# Copyright 2015 University of Antwerp
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#This file contains helper MACRO's that are only available to individual modules

# Declare a parameter for the module. Module parameters are 
# automaticall shown/hidden in the CMake GUI depending on whether or 
# not the module is enabled.
# 
# Module parameters are stored in the cache, just like regular parameters.
# This means that the properties of the parameter can be set in the normal manner
# (by using the SET_PROPERTY command)
#
# Usage:
#    MODULE_PARAM(<var> <default_value> <type> <doc_string>)
#	<var> 		is the name of the variable to set. By convention 
#			all module parameters should be prefixed by the 
#			${MODULE_PREFIX} variable (see examples below).
#
#       <default_value> the default value of the parameter.
#
#	<type>		the type of the parameter. Any valid CMake cache <type>
#			except INTERNAL. At the time of writing these are the valid
#			types:
#				FILEPATH = File chooser dialog.
#				PATH     = Directory chooser dialog.
#				STRING   = Arbitrary string.
#				BOOL     = Boolean ON/OFF checkbox.
#				See http://www.cmake.org/cmake/help/v3.0/command/set.html
#
#	<doc_string>	the documentation string explaining the parameter
#
# Examples:
#	MODULE_PARAM(${MODULE_PREFIX}_STR "Default_Str" STRING "Parameter Explanation")
#		-Adds a STRING parameter '${MODULE_PREFIX}_STR' with default 
#		 value 'Default_Str' and explanation 'Parameter Explanation'
#		 The value of the parameter can be queried using:
#			${${MODULE_PREFIX}_STR}
#	
#	MODULE_PARAM(${MODULE_PREFIX}_LIST "item1" STRING "A List of items")
#	SET_PROPERTY(CACHE ${MODULE_PREFIX}_LIST PROPERTY STRINGS "item1;item2;item3")
#		-Adds a parameter '${MODULE_PREFIX}_LIST', with possible values
#		 'item1', 'item2' and 'item3'. Please note that this is done in
#		 exactly the same manner as for regular 'CACHE' parameters
MACRO(MODULE_PARAM var value type doc)
    SET(MODULE_PARAM_LIST "${MODULE_PARAM_LIST};${var}" CACHE INTERNAL "")
    #Set entry in cache if the module is being loaded
    SETCACHE_IF(${var} ${value} ${type} ${doc} ${MODULE_PREFIX})
ENDMACRO()

# Declare an option for the used module. Like module parameters,
# module options are automatically shown/hidden in the CMake GUI 
# depending on whether or not the module is enabled.
#
# As with module parameters, options are stored in the cache (just like
# regular CMake options)
#
# Usage:
#    MODULE_OPTION(<option> <doc_string> <default_value>)
#	<option>	is the name of the option to set. By convention 
#			all module options should be prefixed by the 
#			${MODULE_PREFIX} variable.
#
#	<doc_string>	the documentation string explaining the option
#
#       <default_value> the default value of the parameter.
#
#    In accordance with CMake's implementation of 'ADD_OPTION',
#    calling: 
#	MODULE_OPTION(<option> <doc_string> <default_value>)
#    is equivalent to calling:
#	MODULE_PARAM( <option> <default_value> BOOL <doc_string>
#
# Examples:
#	MODULE_OPTION(${MODULE_PREFIX}_OPT "OPT Explanation" FALSE)
#		-Adds a module option '{MODULE_PREFIX}_OPT' with 
#		 default value FALSE and explanation 'OPT Explanation'.
#		 The value of the option can be queried using:
#		    ${${MODULE_PREFIX}_OPT}
#
MACRO(MODULE_OPTION option doc default)
    MODULE_PARAM( ${option} ${default} BOOL ${doc})
ENDMACRO()
