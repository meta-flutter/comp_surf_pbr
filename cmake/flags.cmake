#
# Copyright 2020 Toyota Connected North America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions(
        TINYGLTF_ENABLE_DRACO
        TINYGLTF_USE_RAPIDJSON
        TINYGLTF_USE_CPP14
)

include_directories(third_party/draco/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(third_party/rapidjson/include/rapidjson)


string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--build-id=sha1")
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--gc-sections")
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--as-needed")


#
# 32/64 bit detect
#
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions(ENV64BIT)
elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
    add_compile_definitions(ENV32BIT)
endif ()
