#pragma once

#include "mve_model.hpp"

// libs
#include <glm/gtc/matrix_transform.hpp>

// std
#include <memory>
#include <unordered_map>

namespace lve {

struct TransformComponent {
  glm::vec3 translation{};
  glm::vec3 scale{1.f, 1.f, 1.f};
  glm::vec3 rotation{};

  // Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
  // Rotations correspond to Tait-bryan angles of Y(1), X(2), Z(3)
  // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
  glm::mat4 mat4();

  glm::mat3 normalMatrix();
};

struct PointLightComponent {
  float lightIntensity = 1.0f;
};

class MveGameObject {
 public:
  using id_t = unsigned int;
  using Map = std::unordered_map<id_t, MveGameObject>;

  static MveGameObject createGameObject() {
    static id_t currentId = 0;
    return MveGameObject{currentId++};
  }

  static MveGameObject makePointLight(
      float intensity = 10.f, float radius = 0.1f, glm::vec3 color = glm::vec3(1.f));

  MveGameObject(const MveGameObject &) = delete;
  MveGameObject &operator=(const MveGameObject &) = delete;
  MveGameObject(MveGameObject &&) = default;
  MveGameObject &operator=(MveGameObject &&) = default;

  id_t getId() { return id; }

  glm::vec3 color{};
  TransformComponent transform{};

  // Optional pointer components
  std::shared_ptr<MveModel> model{};
  std::unique_ptr<PointLightComponent> pointLight = nullptr;

 private:
  MveGameObject(id_t objId) : id{objId} {}

  id_t id;
};
}  // namespace lve
