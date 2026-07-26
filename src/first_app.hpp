#pragma once

#include "mve_descriptors.hpp"
#include "mve_device.hpp"
#include "mve_game_object.hpp"
#include "mve_renderer.hpp"
#include "mve_window.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  void run();

 private:
  void loadGameObjects();

  MveWindow lveWindow{WIDTH, HEIGHT, "Blank terrain"};
  MveDevice lveDevice{lveWindow};
  MveRenderer lveRenderer{lveWindow, lveDevice};

  // note: order of declarations matters
  std::unique_ptr<MveDescriptorPool> globalPool{};
  std::shared_ptr<MveModel> lveModel;
  MveGameObject::Map gameObjects;
};
}  // namespace lve
