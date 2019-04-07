#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

#include <tuple>
#include <algorithm>

//typedef std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> ipaddr_t;



template <typename... Args>
//ip_pool_t filter(const ip_pool_t &ip_pool, Args... args)
//bool filter(const ipaddr_t &addr, Args... args)
//{
//    std::vector<int> a{args...};
//    static_assert(sizeof...(Args) <= 4, "filter gets 4 parameters max + ip_pool");

////    ip_pool_t ipf;  // filtered
//    std::vector<uint16_t> vec = to_vector(addr);

////    for (auto ip : ip_pool)
//    {
//        if (std::equal(a.begin(), a.end(), vec.begin()))
//            return true;//ipf.push_back(ip);
//    }

//    return false;//ipf;
//}

//bool f_any(const ipaddr_t &addr, uint16_t val)
//{
//  std::vector<uint16_t> vec = to_vector(addr);

//  if (vec.cend() != std::find(vec.cbegin(), vec.cend(), val))
//    return true;
//  else
//    return false;
//}

#include "io.h"

int main()
{
  std::vector<ipaddr_t> addr_list;

  if (!get_from_stream(addr_list))
    std::cout << "[ERR]: Error in input stream!" << std::endl;
//  std::string f("192.168.0.1");
//  get_from_stream1(f);

//  ip_liststr pool {{"192", "168", "10", "100"}};
//  ip_print(pool);

//  addr_list.push_back(std::make_tuple(192, 168, 10, 100));
//  addr_list.push_back(std::make_tuple(10, 4, 20, 100));
//  addr_list.push_back(std::make_tuple(10, 4, 21, 100));
//  addr_list.push_back(std::make_tuple(10, 4, 21, 101));


  std::sort(addr_list.begin(), addr_list.end(), std::greater<ipaddr_t>());
  ip_print(addr_list);
//  std::cout << "Input:" << std::endl;
//  for(auto &ip: addr_list) {
//    std::cout << "[" << std::get<0>(ip) <<
//                 "." << std::get<1>(ip) <<
//                 "." << std::get<2>(ip) <<
//                 "." << std::get<3>(ip) <<
//                 "]" << std::endl;
//  }


//  std::cout << "Output:" << std::endl;
//  for(auto &ip: addr_list) {
//    std::cout << "[" << std::get<0>(ip) <<
//                 "." << std::get<1>(ip) <<
//                 "." << std::get<2>(ip) <<
//                 "." << std::get<3>(ip) <<
//                 "]" << std::endl;
//  }


//  std::vector<uint16_t> vec = to_vector(addr_list[0]);
////  for (auto &ip: addr_list) {
////    vec.clear();

////    vec.push_back(std::get<0>(ip));
////    vec.push_back(std::get<1>(ip));
////    vec.push_back(std::get<2>(ip));
////    vec.push_back(std::get<3>(ip));

//    std::cout << "Vector:" << std::endl;
//    std::cout << "{ ";
//    for (auto &val : vec)
//      std::cout << val << " ";
//    std::cout << "}" << std::endl;
////  }

//  if (filter(addr_list[0], 10))
//    std::cout << "True" << std::endl;
//  else
//    std::cout << "False" << std::endl;

//  if (filter(addr_list[0], 100))
//    std::cout << "True" << std::endl;
//  else
//    std::cout << "False" << std::endl;

//  if (f_any(addr_list[0], 46))
//    std::cout << "True" << std::endl;
//  else
//    std::cout << "False" << std::endl;

//  if (f_any(addr_list[0], 100))
//    std::cout << "True" << std::endl;
//  else
//    std::cout << "False" << std::endl;

  return 0;
}

/*
int main(int argc, char const *argv[])
{
  try {
    std::vector<std::vector<std::string>> ip_pool;


    // TODO reverse lexicographically sort


    // 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
    // ...
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

    // TODO filter by first byte and output
    // ip = filter(1)

    // 1.231.69.33
    // 1.87.203.225
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

    // TODO filter by first and second bytes and output
    // ip = filter(46, 70)

    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76

    // TODO filter by any byte and output
    // ip = filter_any(46)

    // 186.204.34.46
    // 186.46.222.194
    // 185.46.87.231
    // 185.46.86.132
    // 185.46.86.131
    // 185.46.86.131
    // 185.46.86.22
    // 185.46.85.204
    // 185.46.85.78
    // 68.46.218.208
    // 46.251.197.23
    // 46.223.254.56
    // 46.223.254.56
    // 46.182.19.219
    // 46.161.63.66
    // 46.161.61.51
    // 46.161.60.92
    // 46.161.60.35
    // 46.161.58.202
    // 46.161.56.241
    // 46.161.56.203
    // 46.161.56.174
    // 46.161.56.106
    // 46.161.56.106
    // 46.101.163.119
    // 46.101.127.145
    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76
    // 46.55.46.98
    // 46.49.43.85
    // 39.46.86.85
    // 5.189.203.46
  }
  catch(const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
*/
