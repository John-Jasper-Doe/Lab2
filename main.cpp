#include "io.h"
#include "filter.h"
#include <algorithm>
#include <iostream>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
int main()
{
  std::vector<ipaddr_t> addr_list;

  if (!get_from_stream(addr_list))
    std::cout << "[ERR]: Error in input stream!" << std::endl;

  /* Sorting */
  std::sort(addr_list.begin(), addr_list.end(), std::greater<ipaddr_t>());
  ip_print(addr_list);

  /* Filtration */
  std::vector<ipaddr_t> filtered_list;
  filtered_list = filter(addr_list, 1);
  ip_print(filtered_list);

  filtered_list.clear();
  filtered_list = filter(addr_list, 46, 70);
  ip_print(filtered_list);

  filtered_list.clear();
  filtered_list = filter_any(addr_list, 46);
  ip_print(filtered_list);

  return 0;
}
