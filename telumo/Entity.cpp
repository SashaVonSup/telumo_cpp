#include "Entity.h"


namespace telumo {
    size_t Entity::height() {
        return charTable.height();
    }

    size_t Entity::width() {
        return charTable.width();
    }
}
