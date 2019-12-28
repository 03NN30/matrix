#include "GUI_ImGui_ContextMenu.h"

namespace MX
{
  ImGui_ContextMenu::ImGui_ContextMenu(const char* name, const Action& action) :
    m_flags(ImGuiWindowFlags_AlwaysAutoResize |
          ImGuiWindowFlags_NoMove |
          ImGuiWindowFlags_NoResize |
          ImGuiWindowFlags_NoCollapse |
          ImGuiWindowFlags_NoTitleBar),
    m_action(action),
    m_update_mouse(true),
    m_show(false),
    m_mouse_pos(ImGui::GetMousePos()),
    m_name(name),
    m_invoked_begin(false),
    m_force_focus(true) { }

  /* 
    Every call of begin() requires call of end().
    Write the actual content of this menu in between
    both calls.
  */
  bool ImGui_ContextMenu::begin()
  {
    switch (m_action)
    {
      case E_LEFT_CLICK:
      {
        if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
          m_show = true;
        break;
      }
      case E_RIGHT_CLICK:
      {
        if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(1))
          m_show = true;
        break;
      }
      case E_DOUBLE_CLICK:
      {
        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0))
          m_show = true;
        break;
      }
      case E_NONE:
      {
        m_show = true;
        break;
      }
    }

    if (m_show)
    {
      // make sure the window always appears where you right clicked at 
      if (m_update_mouse)
      {
        m_mouse_pos = ImGui::GetMousePos();
        m_update_mouse = false;
      }

      if (ImGui::Begin(m_name, NULL, m_flags))
      {
        m_invoked_begin = true;
        
        // move window to where you clicked
        ImGui::SetWindowPos(m_mouse_pos);

        // on first right click on header set window to being focused to avoid it being deactivated
        if (m_force_focus)
        {
          ImGui::SetWindowFocus();
          m_force_focus = false;
        }

        if (!ImGui::IsWindowFocused())
        {
          m_show = false;
          m_force_focus = true;
          m_update_mouse = true;
        }

        return true;
      }
    }

    return false;
  }

  bool ImGui_ContextMenu::begin(bool& show)
  {
    if (show)
    {
      // make sure the window always appears where you right clicked at 
      if (m_update_mouse)
      {
        m_mouse_pos = ImGui::GetMousePos();
        m_update_mouse = false;
      }

      if (ImGui::Begin(m_name, NULL, m_flags))
      {
        m_invoked_begin = true;

        // move window to where you clicked
        ImGui::SetWindowPos(m_mouse_pos);

        // on first right click on header set window to being focused to avoid it being deactivated
        if (m_force_focus)
        {
          ImGui::SetWindowFocus();
          m_force_focus = false;
        }

        if (!ImGui::IsWindowFocused())
        {
          show = false;
          m_show = false;
          m_force_focus = true;
          m_update_mouse = true;
        }

        return true;
      }
    }

    return false;
  }

  void ImGui_ContextMenu::end()
  {
    /*
      only calls end() if begin() succeeded 
      (this fix is not necessary if user works according to imgui standards)
    */
    if (m_invoked_begin)
    {
      m_invoked_begin = false;
      ImGui::End();
    }
  }
}