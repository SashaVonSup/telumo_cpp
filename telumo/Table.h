#ifndef TELUMO_CPP_TABLE_H
#define TELUMO_CPP_TABLE_H

#include <vector>

namespace telumo {
    template<typename T>
    class Table {
    public:
        std::vector<std::vector<T>> vector;

        explicit Table(std::vector<std::vector<T>> vector = std::vector<std::vector<T>>()) : vector(vector) {}

        Table(size_t height, size_t width) : vector(std::vector<std::vector<T>>(height, std::vector<T>(width))) {}

        size_t height() {
            return vector.size();
        }

        size_t width() {
            return vector.size() ? vector[0].size() : 0;
        }

        std::vector<T>& operator[](size_t i) {
            return vector[i];
        }
    };
}


#endif //TELUMO_CPP_TABLE_H
