/***
 * This file contains an implementation of std::vector wrapper. 
***/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

template<typename T>
class my_container{
    public:
        my_container(const std::initializer_list<T>& list){
            for(const auto& elem: list){
                m_data.emplace_back(elem); // add elements without copying
            }
        }

        void append(const std::initializer_list<T>& list){
            for(const auto& elem: list){
                m_data.emplace_back(elem); // add elements without copying
            }
        }

        void print(std::ostream& os) const{
            std::copy(m_data.begin(), m_data.end(), std::ostream_iterator<T>(os, " "));
        }

        template<typename Predicate>
        void print_if(std::ostream& os, Predicate pred) const{
            std::copy_if(m_data.begin(), m_data.end(), std::ostream_iterator<T>(os, " "), pred);
        }


    private:
        std::vector<T> m_data;
};

int main(){
    my_container<int> cnt = {1,2,3,4,5}; // copy list-initialization
    cnt.append({6,7,8,9,10}); // list-initialization in function call
    
    // print all numbers
    std::cout << "All numbers: ";
    cnt.print(std::cout);

    // print only even numbers
    std::cout << "\nEven numbers: ";
    cnt.print_if(std::cout, [](int i){return i%2 == 0;});
    std::cout << "\n";

    // print greater than 3
    std::cout << "Greater than 3: ";
    cnt.print_if(std::cout, [](int i){return i>3;});

    return 0;
}