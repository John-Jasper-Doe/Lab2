#include "common.h"


template <typename... Args>
std::vector<ipaddr_t> filter(const std::vector<ipaddr_t> &addr, Args... args)
{
  std::vector<int> a{args...};
  static_assert(sizeof...(Args) <= 4,
                "filter gets 4 parameters max + ip_pool");

  std::vector<ipaddr_t> ip_filtered;
  for (const auto &ip : addr) {
    auto tmp_vec = to_vector(ip);

    if (std::equal(a.begin(), a.end(), tmp_vec.begin()))
      ip_filtered.push_back(ip);
  }

  return ip_filtered;
}

std::vector<ipaddr_t> filter_any(const std::vector<ipaddr_t> &addr,
                                 uint16_t val);

