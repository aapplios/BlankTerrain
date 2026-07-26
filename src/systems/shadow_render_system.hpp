#pragma once

#include "mve_camera.hpp"
#include "mve_device.hpp"
#include "mve_frame_info.hpp"
#include "mve_game_object.hpp"
#include "mve_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class ShadowRenderSystem {
 public:
  ShadowRenderSystem(
      MveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~ShadowRenderSystem();

  ShadowRenderSystem(const ShadowRenderSystem &) = delete;
  ShadowRenderSystem &operator=(const ShadowRenderSystem &) = delete;

  void renderGameObjects(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  MveDevice &lveDevice;
  std::unique_ptr<MvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace lve
