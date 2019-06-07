#include "matrix/src/Utils.h"

#include <sstream>
#include <fstream> 

namespace MX
{
#ifdef MX_PLATFORM_WINDOWS_X64
	std::chrono::time_point<std::chrono::steady_clock> current_time;
#elif MX_PLATFORM_UNIX_X64
	std::chrono::_V2::system_clock::time_point current_time;
#endif
  std::string parseFile(const std::string& path)
  {
    std::ifstream stream(path);
	  std::string line;
	  std::stringstream ss[1];
  
	  while (getline(stream, line))
    {
	  	ss[0] << line << '\n';
	  }     
	  return ss[0].str();
  }

	std::string tokenizeLine(const std::string &delimiter)
	{
		return "";
	}
}

