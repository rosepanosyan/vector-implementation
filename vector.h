#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <utility> 

template<typename T>
class Vector {
private:
    size_t size;
    size_t capacity;
    T* data;

public:
    Vector();
    Vector(size_t sz);
    Vector(size_t sz, T vl);
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    T& operator[](const size_t position);
   

    ~Vector();

    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;

    bool empty() const noexcept;

    void push_back(const T& value);
    void pop_back();
    T& at(const size_t index);
    const T& at(const size_t index) const;

    T* begin() noexcept;
    const T* begin() const noexcept;
    T* end() noexcept;
    const T* end() const noexcept;

    void clear() noexcept;


    template <class... Args>
    T* emplace(T* position, Args&&... args);

    void resize(const size_t newSize);
    void reserve(const size_t reservSize);
    void shrink_to_fit();

};

#include "vector.cpp"

#endif