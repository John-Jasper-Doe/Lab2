#include "utils.h"


/* ------------------------------------------------------------------------- */
std::vector<std::string> split(const std::string &str, char div)
{
  std::vector<std::string> result;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(div);

  while(stop != std::string::npos) {
    result.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(div, start);
  }

  result.push_back(str.substr(start));

  return result;
}

/* ------------------------------------------------------------------------- */
