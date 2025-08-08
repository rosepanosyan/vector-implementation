#include <iostream>
#include "vector.h"

int main() {
    Vector<int> v1;
    std::cout << "v1 size: " << v1.get_size() << ", capacity: " << v1.get_capacity() << "\n";

    Vector<int> v2(5);
    std::cout << "v2 size: " << v2.get_size() << ", capacity: " << v2.get_capacity() << "\n";

    Vector<int> v3(5, 42);
    std::cout << "v3 elements: ";
    for (auto x : v3) std::cout << x << " ";
    std::cout << "\n";

    Vector<int> v4{1, 2, 3, 4, 5};
    std::cout << "v4 elements: ";
    for (size_t i = 0; i < v4.get_size(); ++i)
        std::cout << v4[i] << " ";
    std::cout << "\n";

    Vector<int> v5(v4);
    std::cout << "v5 (copy of v4) elements: ";
    for (auto x : v5) std::cout << x << " ";
    std::cout << "\n";

    Vector<int> v6(std::move(v5));
    std::cout << "v6 (moved from v5) elements: ";
    for (auto x : v6) std::cout << x << " ";
    std::cout << "\n";
    std::cout << "v5 size after move: " << v5.get_size() << "\n";

    Vector<int> v7;
    for (int i = 1; i <= 10; ++i) {
        v7.push_back(i * 10);
    }
    std::cout << "v7 after push_back: ";
    for (auto x : v7) std::cout << x << " ";
    std::cout << "\n";

    v7.pop_back();
    std::cout << "v7 after pop_back: ";
    for (auto x : v7) std::cout << x << " ";
    std::cout << "\n";

    v7.resize(15);
    std::cout << "v7 after resize(15): ";
    for (auto x : v7) std::cout << x << " ";
    std::cout << "\n";

    v7.resize(5);
    std::cout << "v7 after resize(5): ";
    for (auto x : v7) std::cout << x << " ";
    std::cout << "\n";

    v7.reserve(20);
    std::cout << "v7 capacity after reserve(20): " << v7.get_capacity() << "\n";

    v7.shrink_to_fit();
    std::cout << "v7 capacity after shrink_to_fit: " << v7.get_capacity() << "\n";

    try {
        std::cout << "Accessing v7.at(10): ";
        std::cout << v7.at(10) << "\n";
    } catch (std::out_of_range &e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    v7.clear();
    std::cout << "v7 after clear, size: " << v7.get_size() << ", capacity: " << v7.get_capacity() << "\n";

    Vector<int> v8{1, 2, 4, 5};
    auto it = v8.emplace(v8.begin() + 2, 3);
    std::cout << "v8 after emplace(3 at position 2): ";
    for (auto x : v8) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
