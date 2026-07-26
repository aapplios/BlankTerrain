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
class PointLightSystem {
 public:
  PointLightSystem(
      MveDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~PointLightSystem();

  PointLightSystem(const PointLightSystem &) = delete;
  PointLightSystem &operator=(const PointLightSystem &) = delete;

  void update(FrameInfo &frameInfo, GlobalUbo &ubo);
  void render(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  MveDevice &lveDevice;

  std::unique_ptr<MvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace lve
