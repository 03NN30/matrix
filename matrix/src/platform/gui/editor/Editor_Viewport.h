#ifndef EDITOR_VIEWPORT_H
#define EDITOR_VIEWPORT_H

#include "GUI_ImGui_Window.h"

namespace MX
{
  class Editor_Viewport : public ImGui_Window
  {
  public:
    MX_API Editor_Viewport();

    MX_API void initialize();
    MX_API void update();
    MX_API void render();

    // ID and dimensions of framebuffer
    ImTextureID m_id;
    float m_width;
    float m_height;
  };
}

#endif // EDITOR_VIEWPORT_H