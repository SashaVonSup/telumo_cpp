/** @file
 * @brief Declaration of `Entity` class
 */

#ifndef TELUMO_CPP_ENTITY_H
#define TELUMO_CPP_ENTITY_H

#include "Table.h"
#include <ncurses.h>


namespace telumo {
    /// Entity (aka sprite) acting at scene
    class Entity {
    public:
        int x; ///< X coordinate of entity's position
        int y; ///< Y coordinate of entity's position
        size_t layer; ///< Layer where entity is located
        Table<chtype> charTable; ///< Image of sprite

        /**
         * Constructor for `Entity`
         * @param x X coordinate of entity's position
         * @param y Y coordinate of entity's position
         * @param layer Layer where entity is located
         * @param charTable Image of sprite
         */
        explicit Entity(int x = 0, int y = 0, size_t layer = 1, const Table<chtype>& charTable = Table<chtype>()) :
            x(x), y(y), layer(layer), charTable(charTable) {}

        /**
         * @brief Height of the sprite
         * @return Height of the sprite
         */
        size_t height();

        /**
         * @brief Width of the sprite
         * @return  Width of the sprite
         */
        size_t width();
    };
}


#endif //TELUMO_CPP_ENTITY_H
