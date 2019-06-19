#ifndef WORLD_H
#define WORLD_H

#define MX_GET_SHADER(name) MX::MX_WORLD.getShader(name)
#define MX_GET_MODEL(name) MX::MX_WORLD.getModel(name)
#define MX_GET_TEXTURE(name) MX::MX_WORLD.getTexture(name)

#include "matrix/src/pch/stdafx.h"
#include "matrix/src/layers/Scene.h"

#include "matrix/src/platform/api/Shader.h"
#include "matrix/src/platform/api/Model.h"
#include "matrix/src/platform/api/Texture.h"
#ifdef MX_OPENGL_ACTIVE
  #include "matrix/src/platform/api/Model_OpenGL.h"
  #include "matrix/src/platform/api/Shader_OpenGL.h"
  #include "matrix/src/platform/api/Texture_OpenGL.h"
#elif MX_DIRECTX_ACTIVE
  #include "matrix/src/platform/api/Model_DirectX.h"
  #include "matrix/src/platform/api/Shader_DirectX.h"
  #include "matrix/src/platform/api/Texture_DirectX.h"
#endif

namespace MX
{
  class World
  {
  public:
    MX_API World() = default;
    MX_API ~World();

    MX_API void initialize();
    MX_API void update();
    MX_API void render();

    MX_API void push(std::shared_ptr<Scene> scene);
    MX_API void pop(const std::string &name);

    MX_API std::shared_ptr<MX_MODEL> getModel(const std::string &name);
    MX_API std::shared_ptr<MX_SHADER> getShader(const std::string &name);
    MX_API std::shared_ptr<MX_TEXTURE> getTexture(const std::string &name);

  public:
    std::shared_ptr<Scene> m_ActiveScene;
    std::vector<std::shared_ptr<Scene>> m_ExistingScenes;
  
    std::vector<std::shared_ptr<Model>> m_Models;
    std::vector<std::shared_ptr<Shader>> m_Shaders;
    std::vector<std::shared_ptr<Texture>> m_Textures;
  };
}

#endif // WORLD_H