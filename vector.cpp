#include <stdexcept>
#include "vector.h"

template<typename T>
Vector<T>::Vector() : size(0), capacity(0), data(nullptr) {}

template<typename T>
Vector<T>::Vector(size_t sz) : size(sz), capacity(sz) {
    data = new T[sz];
    for(size_t i = 0; i < sz; ++i) {
        data[i] = 0;
    }
}

template<typename T>
Vector<T>::Vector(size_t sz, T vl) : size(sz), capacity(sz) {
    data = new T[sz];
    for(size_t i = 0; i < sz; ++i) {
        data[i] = vl;
    }
}

template<typename T> 
Vector<T>::Vector(std::initializer_list<T> list) {
    size = list.size();
    capacity = size;
    data = new T[capacity];
    size_t i = 0;
    for(const T& item : list) {
        data[i++] = item;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for(size_t i =0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& other) : size(other.size), capacity(other.capacity), data(other.data) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if(this == &other) {
        return *this;
    }

    delete[] data;

    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for(size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    } 

    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
   if(this == &other) {
    return *this;
   } 

   delete[] data;

   size  = other.size;
   capacity = other.capacity;
   data = other.data;

   other.data = nullptr;
   other.size = 0;
   other.capaacity = 0;

   return *this;
}

template<typename T>
T& Vector<T>::operator[](const size_t position) {
   return data[position]; 
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
size_t Vector<T>::get_size() const noexcept {
    return size;
}

template<typename T>
size_t Vector<T>::get_capacity() const noexcept {
    return capacity;
}

template<typename T>
bool Vector<T>::empty() const noexcept {
    return size == 0;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if(size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for(size_t i = 0; i < size; ++i) {
            new_data[i] = data[i]; 
        }
        delete[] data;
        data = new_data;
    }
    data[++size] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if(size > 0) {
        --size;
    }
}

template<typename T>
T& Vector<T>::at(const size_t index) {
   if(index >= size) {
        throw std::out_of_range("Vector index out of range");
   } 
   return data[index];
}

template<typename T>
const T& Vector<T>::at(const size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Vector index out of range");
    }
    return data[index];
}

template<typename T>
T* Vector<T>::begin() noexcept {
   return data; 
}

template<typename T>
const T* Vector<T>::begin() const noexcept {
    return data;
}

template<typename T>
T* Vector<T>::end() noexcept {
    return data + size;
}

template<typename T>
const T* Vector<T>::end() const noexcept {
    return data + size;
}

template<typename T>
void Vector<T>::clear() noexcept {
   size = 0; 
}

template<typename T>
template<typename... Args>
T* Vector<T>::emplace(T* position, Args&&... args) {
    size_t index = position - data;
    if(size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for(size_t i = 0; i < index; ++i) {
            new_data[i] = std::move(data[i]);
        }
        new_data[index] = T(std::forward<Args>(args)...);
        for(int i = index; i < size; ++i) {
            new_data[i + 1] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
    }else {
        for(size_t i = size; i > index; --i) {
            data[i] = std::move(data[i - 1]);
        }
        data[index] = T(std::forward<Args>(args)...);
    }
    ++size;

    return data + index;
}

template<typename T>
void Vector<T>::resize(const size_t newSize) {
   if(newSize < size) {
    size = newSize;
   }else if(newSize > size) {
    if(newSize > capacity) {
       T* new_data = new T[newSize];
       for(size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
       }
       delete[] data;
       data = new_data;
       capacity = newSize;
    }
    for(size_t i = size; i < newSize; ++i) {
        data[i] = T();
    }
    size = newSize;
   }
}

template<typename T>
void Vector<T>::reserve(const size_t reservSize) {
   if(reservSize <= capacity) {
    return;
   } 
   T* new_data = new T[reservSize];
   for(size_t i = 0; i < size; ++i) {
    new_data[i] = data[i];
   }
   delete[] data;
   data = new_data;
   capacity = reservSize;
}

template<typename T>
void Vector<T>::shrink_to_fit() {
    if(size == capacity) {
        return;
    }
    T* new_data = new T[size];
    for(size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = size;
 }