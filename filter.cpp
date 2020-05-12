#include "filter.h"
#include <algorithm>


std::vector<ipaddr_t> filter_any(const std::vector<ipaddr_t> &addr,
                                 uint16_t val)
{
  std::vector<ipaddr_t> ip_filtered;
  for (const auto &ip : addr) {
    auto tmp_vec = to_vector(ip);

    if (tmp_vec.cend() != std::find(tmp_vec.cbegin(), tmp_vec.cend(), val))
      ip_filtered.push_back(ip);
  }

  return ip_filtered;
}

