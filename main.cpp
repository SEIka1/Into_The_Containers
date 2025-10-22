#include "prefix_sum/include/prefix_sum.h"

#include <vector>
#include <iostream>
#include <list>

template <typename Container>
void prefixSum(const Container& arr, size_t l, size_t r);

template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<
        typename T::value_type,
        typename T::iterator,
        typename T::const_iterator,
        decltype(std::declval<T>().begin()),
        decltype(std::declval<T>().end())
        >> : std::true_type {};

template<typename T>
inline constexpr bool is_container_v = is_container<T>::value;

int main() {

    std::list<long long> arr0{1, 2, 3, 4, 5};
    std::vector<long long> arr1{1, 2, 3, 4, 5};

    prefixSum(arr0, 0, 4);
    prefixSum(arr1, 0, 4);

    return 0;
}


template <typename Container>
void prefixSum(const Container& arr, size_t l, size_t r)
{
    using ValueType = typename Container::value_type;

    static_assert(is_container_v<Container>, "Container must be a container type");
    static_assert(std::is_arithmetic_v<ValueType>, "Value type must be arithmetic");

    PrefixSum<Container> ps(arr);

    std::cout << "Sum [" << l << ", " << r << "]: " << ps.query(l, r) << '\n';
}
