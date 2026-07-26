#pragma once

#include "mve_device.hpp"

// std
#include <memory>
#include <unordered_map>
#include <vector>

namespace lve {

class MveDescriptorSetLayout {
 public:
  class Builder {
   public:
    Builder(MveDevice &lveDevice) : lveDevice{lveDevice} {}

    Builder &addBinding(
        uint32_t binding,
        VkDescriptorType descriptorType,
        VkShaderStageFlags stageFlags,
        uint32_t count = 1);
    std::unique_ptr<MveDescriptorSetLayout> build() const;

   private:
    MveDevice &lveDevice;
    std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings{};
  };

  MveDescriptorSetLayout(
      MveDevice &lveDevice, std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings);
  ~MveDescriptorSetLayout();
  MveDescriptorSetLayout(const MveDescriptorSetLayout &) = delete;
  MveDescriptorSetLayout &operator=(const MveDescriptorSetLayout &) = delete;

  VkDescriptorSetLayout getDescriptorSetLayout() const { return descriptorSetLayout; }

 private:
  MveDevice &lveDevice;
  VkDescriptorSetLayout descriptorSetLayout;
  std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings;

  friend class MveDescriptorWriter;
};

class MveDescriptorPool {
 public:
  class Builder {
   public:
    Builder(MveDevice &lveDevice) : lveDevice{lveDevice} {}

    Builder &addPoolSize(VkDescriptorType descriptorType, uint32_t count);
    Builder &setPoolFlags(VkDescriptorPoolCreateFlags flags);
    Builder &setMaxSets(uint32_t count);
    std::unique_ptr<MveDescriptorPool> build() const;

   private:
    MveDevice &lveDevice;
    std::vector<VkDescriptorPoolSize> poolSizes{};
    uint32_t maxSets = 1000;
    VkDescriptorPoolCreateFlags poolFlags = 0;
  };

  MveDescriptorPool(
      MveDevice &lveDevice,
      uint32_t maxSets,
      VkDescriptorPoolCreateFlags poolFlags,
      const std::vector<VkDescriptorPoolSize> &poolSizes);
  ~MveDescriptorPool();
  MveDescriptorPool(const MveDescriptorPool &) = delete;
  MveDescriptorPool &operator=(const MveDescriptorPool &) = delete;

  bool allocateDescriptor(
      const VkDescriptorSetLayout descriptorSetLayout, VkDescriptorSet &descriptor) const;

  void freeDescriptors(std::vector<VkDescriptorSet> &descriptors) const;

  void resetPool();

 private:
  MveDevice &lveDevice;
  VkDescriptorPool descriptorPool;

  friend class MveDescriptorWriter;
};

class MveDescriptorWriter {
 public:
  MveDescriptorWriter(MveDescriptorSetLayout &setLayout, MveDescriptorPool &pool);

  MveDescriptorWriter &writeBuffer(uint32_t binding, VkDescriptorBufferInfo *bufferInfo);
  MveDescriptorWriter &writeImage(uint32_t binding, VkDescriptorImageInfo *imageInfo);

  bool build(VkDescriptorSet &set);
  void overwrite(VkDescriptorSet &set);

 private:
  MveDescriptorSetLayout &setLayout;
  MveDescriptorPool &pool;
  std::vector<VkWriteDescriptorSet> writes;
};

}  // namespace lve
