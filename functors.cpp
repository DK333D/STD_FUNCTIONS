/***
 * This file is an example of using functors. 
 * A functor is a class that overloads the function call operator.
***/

#include<iostream>

class my_functor_is_first_greater_than_second{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};
class my_functor_is_first_less_than_second{
    public:
        bool operator()(int a, int b){
            return a<b;
        }
};
class my_functor_is_first_equal_to_second{
    public:
        bool operator()(int a, int b){
            return a==b;
        }
};

template<typename T, typename Predicate>
void compare_two_variables(T a, T b, Predicate pred, std::string info){
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << info << std::endl;
    std::cout << std::boolalpha << pred(a,b) << std::endl;

}

int main(){
    int a = 5, b = 10;
    compare_two_variables(a, b, my_functor_is_first_greater_than_second(), "a>b");
    std::cout << std::endl;
    compare_two_variables(a, b, my_functor_is_first_less_than_second(), "a<b");
    std::cout << std::endl;
    compare_two_variables(a, b, my_functor_is_first_equal_to_second(), "a==b");
    std::cout << std::endl;
    return 0;

}

