#include <initializer_list>
#include <iostream>

template <class T>
struct MyStruct {
    MyStruct(std::initializer_list<T> l) {
        for (const T e : l) {
            std::cout << e << ", ";
        }
        std::cout << "constructed!\n";
    }
};

int main() {
    // MyStruct<int> a = {1, 2, 3};
    MyStruct<int>  b{4, 5};
    return 0;
}