#ifndef EDITOR_EXPLORER_H
#define EDITOR_EXPLORER_H

#include "GUI_ImGui_Window.h"

namespace MX
{
  class Editor_Explorer : public ImGui_Window
  {
  public:
    MX_API Editor_Explorer() = default;
    MX_API Editor_Explorer(const std::string& name, ImGuiWindowFlags flags = 0);

    MX_API bool initialize(const std::string& name, ImGuiWindowFlags flags = 0) override;
    MX_API bool update() override;
    MX_API void render() override; 
  };
}

#endif // EDITOR_EXPLORER_H