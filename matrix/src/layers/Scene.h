#ifndef SCENE_H
#define SCENE_H

#include "matrix/src/platform/api/Model.h"
#include "matrix/src/platform/api/Model_Handler.h"

#include "matrix/src/Camera.h"
#include "matrix/src/layers/SceneGraph.h"

namespace MX
{
  class Scene
  {
  public:
    MX_API Scene() {}
    MX_API Scene(const std::string &name)
      : m_Name(name) {}
    MX_API ~Scene() {}

    MX_API void initialize();
    MX_API void update();
    MX_API void render();

    // return 1 if name is unique, searches the entire scene's scenegraph
    MX_API bool addItemEntry(const std::string &name);
    
    MX_API bool push(const std::string &name);
    MX_API bool push(const std::string &object_name, const std::string &file_name, const std::string &node_to_attach_to);
    MX_API bool push(std::shared_ptr<Node> node, std::shared_ptr<Node> node_to_attach_to);
    MX_API bool pop(const std::string &name);
  
  private:
    MX_API bool object_already_exists(const std::string &name);

  public:
    Camera m_Cam;
    SceneGraph m_Sg;
    std::string m_Name;
    
    std::vector<std::string> m_ExistingObjects;
  };
}

#endif // SCENE_H