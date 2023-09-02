/***
 * My implementation of std::stable_partition based on: https://en.cppreference.com/w/cpp/algorithm/stable_partition
 * my_stable_partition Reorders the elements in the range [first, last) in such a way that all elements for which 
 * the predicate p returns true precede the elements for which predicate p returns false. 
 * Relative order of the elements is preserved.
***/

#include <iostream>
#include <vector>
#include <deque>
#include <functional>

template <typename T, template<typename U=T, typename Allocator=std::allocator<U>> class Container=std::deque, typename Predicate>
Container<T> my_stable_partition(const Container<T>& cnt, Predicate f) {
    Container<T> result;
    Container<T> temp;

    for(const auto& i : cnt) {
        if (f(i)) {
            result.push_back(i);
        } else {
            temp.push_back(i);
        }
    }

    result.insert(result.end(), temp.begin(), temp.end());
    
    return result;
}

int main() {
    std::vector<int> v{-10, -5, -1, 2, 3, 0, 0, 4, 5, 0, 6, 7, 8, 0, -9};
    std::cout << "Before partitioning: " << std::endl;
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    auto result = my_stable_partition(v, [](int x) { return x > 0; });
    std::cout << "After partitioning (x > 0): " << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    result = my_stable_partition(v, std::negate<int>());
    std::cout << "After partitioning (std::negate<int>()): " << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;


    std::vector<double> chars{'w', 'o', 'H', 'r', 'E', 'L', 'l', 'L', 'd', 'O'};

    std::cout << "Before partitioning: " << std::endl;
    for(const char& i : chars) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto result2 = my_stable_partition(chars, [](char x) { return x>='A' && x<='Z'; });

    std::cout << "After uppercase/lowercase partitioning: " << std::endl;

    for(const char& i : result2) {
        std::cout << i << " ";
    }

    std::cout << std::endl;


    return 0;
}
