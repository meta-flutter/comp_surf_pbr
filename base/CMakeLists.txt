
add_library(base STATIC
        camera.hpp
        keycodes.hpp
        ui.hpp
        VulkanDevice.hpp
        VulkanExampleBase.cpp
        VulkanglTFModel.cpp
        VulkanSwapChain.hpp
        VulkanTexture.hpp
        VulkanUtils.hpp
        )

target_include_directories(base
        PUBLIC
        ../third_party
        ../third_party/gli
        ../third_party/glm
        ../third_party/tinygltf
        )
