#ifndef TELUMO_CPP_ENTITY_H
#define TELUMO_CPP_ENTITY_H

#include "Table.h"
#include <ncurses.h>


namespace telumo {
    class Entity {
    public:
        int x;
        int y;
        size_t layer;
        Table<chtype> charTable;

        explicit Entity(int x = 0, int y = 0, size_t layer = 1, const Table<chtype>& charTable = Table<chtype>()) :
            x(x), y(y), layer(layer), charTable(charTable) {}

        size_t height();

        size_t width();
    };
}


#endif //TELUMO_CPP_ENTITY_H
