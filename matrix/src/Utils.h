#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <chrono>

namespace MX
{
  const int initial_window_width = 1400;
  const int initial_window_height = 800;

  const std::string default_root_name = "Root";
  const std::string glsl_version = "#version 460";

  std::string parseFile(const std::string &path);
  std::string tokenizeLine(const std::string &delimiter);
  std::string f_str(float num);
  std::string f_str(float num, float num_decimals);
  std::string remove_file_ending(const std::string &name);
  // const char* str_c(const std::string &str);

#ifdef MX_PLATFORM_WINDOWS_X64
  extern std::chrono::time_point<std::chrono::steady_clock> current_time;
#elif MX_PLATFORM_UNIX_X64
  extern std::chrono::_V2::system_clock::time_point current_time;
#endif
}

#endif // UTILS_H