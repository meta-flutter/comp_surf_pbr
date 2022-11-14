
#pragma once

#include "VulkanExampleBase.h"
#include "VulkanTexture.hpp"
#include "VulkanglTFModel.h"
#include "ui.hpp"


#include <map>

//static constexpr char kRuntimeAssetPath[] = RUNTIME_ASSET_PATH;

class VulkanPbr : public VulkanExampleBase {
public:
    struct Textures {
        vks::TextureCubeMap environmentCube;
        vks::Texture2D empty;
        vks::Texture2D lutBrdf;
        vks::TextureCubeMap irradianceCube;
        vks::TextureCubeMap prefilteredCube;
    } textures;

    struct Models {
        vkglTF::Model scene;
        vkglTF::Model skybox;
    } models;

    struct UniformBufferSet {
        Buffer scene;
        Buffer skybox;
        Buffer params;
    };

    struct UBOMatrices {
        glm::mat4 projection;
        glm::mat4 model;
        glm::mat4 view;
        glm::vec3 camPos;
    } shaderValuesScene, shaderValuesSkybox;

    struct shaderValuesParams {
        glm::vec4 lightDir;
        float exposure = 4.5f;
        float gamma = 2.2f;
        float prefilteredCubeMipLevels;
        float scaleIBLAmbient = 1.0f;
        float debugViewInputs = 0;
        float debugViewEquation = 0;
    } shaderValuesParams;

    VkPipelineLayout pipelineLayout;

    struct Pipelines {
        VkPipeline skybox;
        VkPipeline pbr;
        VkPipeline pbrDoubleSided;
        VkPipeline pbrAlphaBlend;
    } pipelines;
    VkPipeline boundPipeline = VK_NULL_HANDLE;

    struct DescriptorSetLayouts {
        VkDescriptorSetLayout scene;
        VkDescriptorSetLayout material;
        VkDescriptorSetLayout node;
    } descriptorSetLayouts;

    struct DescriptorSets {
        VkDescriptorSet scene;
        VkDescriptorSet skybox;
    };
    std::vector<DescriptorSets> descriptorSets;

    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<UniformBufferSet> uniformBuffers;

    std::vector<VkFence> waitFences;
    std::vector<VkSemaphore> renderCompleteSemaphores;
    std::vector<VkSemaphore> presentCompleteSemaphores;

    const uint32_t renderAhead = 2;
    uint32_t frameIndex = 0;

    int32_t animationIndex = 0;
    float animationTimer = 0.0f;
    bool animate = true;

    bool displayBackground = true;

    struct LightSource {
        glm::vec3 color = glm::vec3(1.0f);
        glm::vec3 rotation = glm::vec3(75.0f, 40.0f, 0.0f);
    } lightSource;

    UI *ui;

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    const std::string assetpath = "";
#else
    std::string assetpath;
#endif

    bool rotateModel = false;
    glm::vec3 modelrot = glm::vec3(0.0f);
    glm::vec3 modelPos = glm::vec3(0.0f);

    enum PBRWorkflows {
        PBR_WORKFLOW_METALLIC_ROUGHNESS = 0, PBR_WORKFLOW_SPECULAR_GLOSINESS = 1
    };

    struct PushConstBlockMaterial {
        glm::vec4 baseColorFactor;
        glm::vec4 emissiveFactor;
        glm::vec4 diffuseFactor;
        glm::vec4 specularFactor;
        float workflow;
        int colorTextureSet;
        int PhysicalDescriptorTextureSet;
        int normalTextureSet;
        int occlusionTextureSet;
        int emissiveTextureSet;
        float metallicFactor;
        float roughnessFactor;
        float alphaMask;
        float alphaMaskCutoff;
    } pushConstBlockMaterial;

    std::map<std::string, std::string> environments;
    std::string selectedEnvironment = "papermill";

#if !defined(_WIN32)
    std::map<std::string, std::string> scenes;
    std::string selectedScene = "DamagedHelmet";
#endif

    int32_t debugViewInputs = 0;
    int32_t debugViewEquation = 0;

    VulkanPbr(void *native_window, std::string assetPath, uint32_t width, uint32_t height);

    ~VulkanPbr();

    void renderNode(vkglTF::Node *node, uint32_t cbIndex, vkglTF::Material::AlphaMode alphaMode);

    void recordCommandBuffers();

    void loadScene(std::string filename);

    void loadEnvironment(std::string filename);

    void loadAssets();

    void setupNodeDescriptorSet(vkglTF::Node *node);

    void setupDescriptors();

    void preparePipelines();

    void generateBRDFLUT();

    void generateCubemaps();

    void prepareUniformBuffers();

    void updateUniformBuffers();

    void updateParams();

    void windowResized() override;

    void prepare() override;

    void updateOverlay();

    void render() override;

    void fileDropped(std::string filename) override;
};
