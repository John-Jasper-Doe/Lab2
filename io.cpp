#include "io.h"
#include "utils.h"
#include <iostream>


/* ------------------------------------------------------------------------- */
bool get_from_stream(std::vector<ipaddr_t> &data)
{
  for(std::string line; std::getline(std::cin, line);) {
    std::vector<std::string> tmp_vec = split(line, '\t');
    std::vector<std::string> tmp_vec_ip(split(tmp_vec.at(0), '.'));

    if (tmp_vec_ip.size() != 4)
      return false;

    try {
      ipaddr_t tmp_ip = std::make_tuple(
                    static_cast<uint16_t>(std::stoi(tmp_vec_ip.at(0))),
                    static_cast<uint16_t>(std::stoi(tmp_vec_ip.at(1))),
                    static_cast<uint16_t>(std::stoi(tmp_vec_ip.at(2))),
                    static_cast<uint16_t>(std::stoi(tmp_vec_ip.at(3))));
//      auto/*ip_addr_t*/ tmp = to_tuple(tmp_vec);
      data.push_back(tmp_ip);
    }
    catch(std::invalid_argument) {
      return false;
    }
  }
  return true;
}

/* ------------------------------------------------------------------------- */
void ip_print(std::vector<ipaddr_t> &data)
{
  for (const auto &ip : data) {
    std::vector<uint16_t> tmp_vec = to_vector(ip);

    auto ip_part_it = tmp_vec.cbegin();
    for (; ip_part_it != tmp_vec.cend(); ++ip_part_it) {
      if (ip_part_it != tmp_vec.cbegin())
        std::cout << ".";

      std::cout << *ip_part_it;
    }
    std::cout << std::endl;
  }
}
