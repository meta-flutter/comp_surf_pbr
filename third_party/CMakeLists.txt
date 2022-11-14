#
# Copyright 2022 Toyota Connected North America
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

add_subdirectory(draco)

add_subdirectory(gli)

add_subdirectory(glm)

set(KTX_FEATURE_TOOLS OFF CACHE INTERNAL "" FORCE)
set(KTX_FEATURE_TESTS OFF CACHE INTERNAL "" FORCE)
set(KTX_FEATURE_STATIC_LIBRARY ON CACHE INTERNAL "" FORCE)
add_subdirectory(KTX-Software)

set(RAPIDJSON_BUILD_DOC OFF CACHE INTERNAL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE INTERNAL "" FORCE)
set(RAPIDJSON_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
set(RAPIDJSON_BUILD_CXX11 OFF CACHE INTERNAL "" FORCE)
set(RAPIDJSON_BUILD_CXX17 ON CACHE INTERNAL "" FORCE)
set(RAPIDJSON_ENABLE_INSTRUMENTATION_OPT ON CACHE INTERNAL "" FORCE)
set(RAPIDJSON_HAS_STDSTRING ON CACHE INTERNAL "" FORCE)
set(RAPIDJSON_USE_MEMBERSMAP OFF CACHE INTERNAL "" FORCE)
add_subdirectory(rapidjson)

add_compile_definitions()
set(TINYGLTF_HEADER_ONLY ON CACHE INTERNAL "" FORCE)
set(TINYGLTF_INSTALL OFF CACHE INTERNAL "" FORCE)
set(TINYGLTF_BUILD_LOADER_EXAMPLE OFF CACHE INTERNAL "" FORCE)
add_subdirectory(tinygltf)
