#version 450

layout(location = 0) out float outDepth;

void main() {
  // Normalize depth to [0, 1] range for shadow map
  outDepth = gl_FragCoord.z;
}
