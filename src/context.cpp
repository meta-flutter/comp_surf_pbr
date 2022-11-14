/*
 * Copyright 2022 Toyota Connected North America
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "context.h"

#include <cassert>


uint32_t CompSurfContext::version() {
    return 0x00010000;
}

CompSurfContext::CompSurfContext(const char *accessToken,
                                 int width,
                                 int height,
                                 void *nativeWindow,
                                 const char *assetsPath,
                                 const char *cachePath,
                                 const char *miscPath)
        : mAccessToken(accessToken),
          mAssetsPath(assetsPath),
          mCachePath(cachePath),
          mMiscPath(miscPath) {
    std::cout << "[comp_surf_pbr]" << std::endl;
    std::cout << "assetsPath: " << mAssetsPath << std::endl;
    std::cout << "cachePath: " << mCachePath << std::endl;
    std::cout << "miscPath: " << mMiscPath << std::endl;

    mVulkanPbr = std::make_unique<VulkanPbr>(nativeWindow, mAssetsPath, width, height);

    mVulkanPbr->initVulkan();
    mVulkanPbr->prepare();
}

void CompSurfContext::de_initialize() {

  if(mVulkanPbr) {
    mVulkanPbr.release();
  }
}

void CompSurfContext::run_task() {
}

void CompSurfContext::resize(int width, int height) {}

void CompSurfContext::draw_frame(CompSurfContext *ctx, uint32_t time) {
    mVulkanPbr->renderLoop();
}
