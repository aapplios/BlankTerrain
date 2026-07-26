# Blank Terrain In-dev
# Works in every operating system (macOS, Windows, Linux)

Running it in all machines : 

``` 
./bin/Engine
```

![Platform](https://img.shields.io/badge/platform-macOS%20%7C%20Windows%20%7C%20Linux-blue)
![Graphics API](https://img.shields.io/badge/API-Vulkan-red)

# About the game:

Made with Little Vulkan Engine by 
https://github.com/blurrypiano/littleVulkanEngine/

Movement Modified Up and down movements from Q and E to, Left Shift and Space, Sky modified from gray to light blue.

# Goals of game code:

1. Basics & Interaction      ➜ Crosshair, Block Placing/Breaking
2. Voxel Data & Rendering    ➜ Chunk Manager, Per-Chunk Mesh Generation, Noise (Terrain)
3. Physics & World State     ➜ AABB Collisions, World Saving (Saveloading chunk files)
4. Game Loop & UI            ➜ UI Menu, Game Settings, Audio
5. Entities & VFX            ➜ AI Mobs, Animations, Particle Effects
6. Polish & Lighting         ➜ Custom Voxel/PBR Shader Lighting, Threading Optimizations
