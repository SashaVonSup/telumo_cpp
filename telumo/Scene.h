#ifndef TELUMO_CPP_SCENE_H
#define TELUMO_CPP_SCENE_H

#include <vector>

#include "Entity.h"


namespace telumo {
    class Scene {
    public:
        std::vector<Entity> entities;

        explicit Scene(size_t height, size_t width) :
            entities(std::vector<Entity>()), charTable(height, width), layerTable(height, width) {}

        size_t height();

        size_t width();

        Entity& addEntity(const Entity& entity);

        void render();

        void flush(WINDOW *window = stdscr);

    private:
        Table<chtype> charTable;
        Table<size_t> layerTable;

        void renderEntity(Entity& entity);
    };
}


#endif //TELUMO_CPP_SCENE_H
