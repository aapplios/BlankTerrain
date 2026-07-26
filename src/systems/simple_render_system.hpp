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
class SimpleRenderSystem {
 public:
  SimpleRenderSystem(
      MveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~SimpleRenderSystem();

  SimpleRenderSystem(const SimpleRenderSystem &) = delete;
  SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

  void renderGameObjects(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  MveDevice &lveDevice;

  std::unique_ptr<MvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace lve
