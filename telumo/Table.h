/** @file
 * @brief Declaration of `Table` class
 */

#ifndef TELUMO_CPP_TABLE_H
#define TELUMO_CPP_TABLE_H

#include <vector>

namespace telumo {
    /// 2-d array (table)
    template<typename T>
    class Table {
    public:
        /**
         * @brief Constructor for `Table`
         * @param vector Vector of vectors with data to store
         */
        explicit Table(std::vector<std::vector<T>> vector =
                std::vector<std::vector<T>>()) : vector(vector) {}

        /**
         * @brief Constructor for `Table`
         * @param height Height of table
         * @param width Width of table
         */
        Table(size_t height, size_t width) :
            vector(std::vector<std::vector<T>>(height, std::vector<T>(width))) {}

        /**
         * @brief Height of table
         * @return Height of table
         */
        size_t height() {
            return vector.size();
        }

        /**
         * @brief Width of table
         * @return Width of table
         */
        size_t width() {
            return vector.size() ? vector[0].size() : 0;
        }

        /**
         * @brief Access to row by index
         * @param i Number of row (0 is the beginning)
         * @return Reference to the i-th row
         */
        std::vector<T>& operator[](size_t i) {
            return vector[i];
        }

    private:
        std::vector<std::vector<T>> vector; ///< Vector of vectors to store data
    };
}


#endif //TELUMO_CPP_TABLE_H
