#include "Scene.h"


namespace telumo {
    size_t Scene::height() {
        return charTable.height();
    }

    size_t Scene::width() {
        return charTable.width();
    }

    Entity& Scene::addEntity(const Entity &entity) {
        entities.push_back(entity);
        return entities.at(entities.size() - 1);
    }

    void Scene::renderEntity(Entity& entity) {
        chtype ch;
        for (size_t x = std::max(0, entity.x), i = x - entity.x;
             x < height() && i < entity.height(); ++x, ++i)
            for (size_t y = std::max(0, entity.y), j = y - entity.y;
                 y < width() && j < entity.width(); ++y, ++j)
                if (layerTable[x][y] < entity.layer && (ch = entity.charTable[i][j])) {
                    charTable[x][y] = ch;
                    layerTable[x][y] = entity.layer;
                }
    }

    void Scene::render() {
        charTable = Table<chtype>(height(), width());
        layerTable = Table<size_t>(height(), width());
        for (auto& entity : entities)
            renderEntity(entity);
    }

    void Scene::flush(WINDOW *window) {
        for (int x = 0; x < height(); ++x) {
            wmove(window, x, 0);
            for (auto ch : charTable[x])
                waddch(window, ch ? ch : ' ');
        }
        wrefresh(window);
    }
}
