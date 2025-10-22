#ifndef DATA_STRUCTURES_PREFIX_SUM_H
#define DATA_STRUCTURES_PREFIX_SUM_H

#include <vector>
#include <iostream>

template <typename Container>
class PrefixSum {
public:
    using ValueType = typename Container::value_type;

    PrefixSum(const Container& arr) {
        size_t n = arr.size();
        prefix.resize(n + 1, ValueType{0});

        auto it = arr.begin();
        for(size_t i = 0; i < n; ++i, ++it) {
            prefix[i + 1] = prefix[i] + *it;
        }
    }

    ValueType query(size_t l, size_t r) const {
        return prefix[r + 1] - prefix[l];
    }

private:
    std::vector<ValueType> prefix;
};

#endif //DATA_STRUCTURES_PREFIX_SUM_H
