#ifndef CAMERA_H
#define CAMERA_H

#include "matrix/src/pch/stdafx.h"

namespace MX
{
  class Camera
  {
  public:
    MX_API Camera()
      : m_Position(glm::vec3(0.0f, 0.0f, 3.0f)),
        m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
        m_worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
        m_Yaw(-90.0f),
        m_Pitch(0.0f),
        m_Sensitivity(0.06f),
        m_Fov(45.0f),
        m_ScreenWidth(initial_window_width),
        m_ScreenHeight(initial_window_height)
    {
      updateVectors();
    }

    MX_API ~Camera() = default;

    MX_API Camera(const Camera&) = default;
    MX_API Camera &operator=(const Camera&) = default;
  
    MX_API void processKeyboard(); 
    MX_API void processMouse(float xoffset, float yoffset);

    MX_API void update();

    MX_API inline glm::mat4 getViewMatrix() { return glm::lookAt(m_Position, m_Position + m_Front, m_worldUp); }
    MX_API inline glm::mat4 getProjectionMatrix() { return glm::perspective(glm::radians(m_Fov), m_ScreenWidth / m_ScreenHeight, 0.1f, 100.0f); }

    MX_API inline glm::fvec3 getPosition() { return m_Position; }

    MX_API void setScreenDimensions(int width, int height);

  private:
    glm::fvec3 m_Position;
    glm::fvec3 m_Front;
    glm::fvec3 m_worldUp;
    glm::fvec3 m_Up;
    glm::fvec3 m_Right;

    float m_Yaw;
    float m_Pitch;
    float m_Sensitivity;
    float m_Fov;

    float m_ScreenWidth;
    float m_ScreenHeight;

    MX_API void updateVectors();
  };
}

#endif // CAMERA_H