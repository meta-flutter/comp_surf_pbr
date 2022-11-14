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

option (USE_D2D_WSI "Build the project using Direct to Display swapchain" OFF)
if (USE_D2D_WSI)
    MESSAGE("Using direct to display extension...")
    add_compile_definitions(_DIRECT2DISPLAY)
endif()

option (USE_WAYLAND_WSI "Build the project using Wayland swapchain" ON)
if (USE_WAYLAND_WSI)
    message("Using wayland extension...")
    include(wayland)
    add_compile_definitions(VK_USE_PLATFORM_WAYLAND_KHR)
endif ()

option (USE_XCB_WSI "Build the projcet using XCB swapchain" OFF)
if (USE_XCB_WSI)
    message("Using XCB extension...")
    find_package(XCB REQUIRED)
    add_compile_definitions(VK_USE_PLATFORM_XCB_KHR)
endif ()

set(RESOURCE_INSTALL_DIR "" CACHE PATH "Path to install resources to (leave empty for running uninstalled)")

if (NOT RUNTIME_ASSET_PATH)
    set(RUNTIME_ASSET_PATH "${CMAKE_SOURCE_DIR}/assets/")
endif()
