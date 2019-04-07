#include <string>
#include <vector>
#include <tuple>
#include <cassert>


using ipaddr_str_t = std::vector<std::string>;
using ip_liststr_t = std::vector<std::vector<std::string>>;
using ipaddr_t = std::tuple<uint16_t, uint16_t, uint16_t, uint16_t>;


/* index sequence only */
template <std::size_t ...>
struct index_sequence
{ };

template <std::size_t N, std::size_t ... Next>
struct index_sequence_helper :
    public index_sequence_helper<N-1U, N-1U, Next...>
{ };

template <std::size_t ... Next>
struct index_sequence_helper<0U, Next ... >
{
  using type = index_sequence<Next ... >;
};

template <std::size_t N>
using make_index_sequence = typename index_sequence_helper<N>::type;


/** Convert tuple to vector */
template<typename first_type, typename tuple_type, size_t ...index>
auto to_vector_helper(const tuple_type &t, index_sequence<index...>)
{
    return std::vector<first_type>{std::get<index>(t)...};
}

template<typename first_type, typename ...others>
auto to_vector(const std::tuple<first_type, others...> &t)
{
    typedef typename std::remove_reference<decltype(t)>::type tuple_type;

    constexpr auto s = std::tuple_size<tuple_type>::value;

    return to_vector_helper<first_type, tuple_type>
        (t, make_index_sequence<s>{});
}


/** Convert vector to tuple */
//template <typename T, std::size_t... index>
//auto to_tuple_helper(const std::vector<T>& v, index_sequence<index...>)
//{
//  return std::make_tuple(static_cast<uint16_t>(v[index])...);
//}

template <std::size_t... index>
auto to_tuple_helper(const std::vector<std::string> &v,
                     index_sequence<index...>)
{
  return std::make_tuple(static_cast<uint16_t>(std::stoi(v[index]))...);
}


template <std::size_t N = 0>
auto to_tuple(const std::vector<std::string> &v) {
  assert(v.size() >= N);
  return to_tuple_helper(v, make_index_sequence<N>());
}
