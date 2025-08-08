# vector-implementation
A C++ vector class using templates and dynamic memory management
## 🚀 Features

- Template-based vector class (`Vector<T>`)
- Dynamic memory allocation
- Methods like:
  - `push_back`
  - `pop_back`
  - `resize`
  - `reserve`
  - `shrink_to_fit`
  - `clear`
  - `operator[]` and `at()`
  - Iterators (`begin()` / `end()` support)
  - `emplace`

## 📁 Project Structure
vector-implementation/
├── vector.h # Template class declaration and implementation
├── main.cpp # Test file demonstrating usage of Vector<T>
└── README.md # You're reading it :)


## 🧪 Example Usage

```cpp
#include "vector.h"

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.resize(5);
    v.pop_back();

    for (auto val : v) {
        std::cout << val << " ";
    }
    return 0;
}
```
```bash
g++ -std=c++17 main.cpp -o vector_demo
./vector_demo
```
Author
Roza 🌹
A developer passionate about learning C++ and building things from scratch.


