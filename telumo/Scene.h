/** @file
 * @brief Declaration of `Scene` class
 */

#ifndef TELUMO_CPP_SCENE_H
#define TELUMO_CPP_SCENE_H

#include <vector>

#include "Entity.h"


namespace telumo {
    /// Scene where entities are located
    class Scene {
    public:
        std::vector<Entity> entities; ///< Vector (list) of entities at scene

        /**
         * @brief Constructor for `Scene`
         * @param height Height of the scene
         * @param width Width of the scene
         */
        explicit Scene(size_t height, size_t width) :
            entities(std::vector<Entity>()), charTable(height, width), layerTable(height, width) {}

        /**
         * @brief Height of the scene
         * @return Height of the scene
         */
        size_t height();

        /**
         * @brief Width of the scene
         * @return Width of the scene
         */
        size_t width();

        /**
         * @brief Add entity to scene
         * @param entity Entity to add
         * @return Reference to the added entity in `entities` vector
         */
        Entity& addEntity(const Entity& entity);

        /// Draw all entities to scene's tables: `charTable` and `layerTable`
        void render();

        /**
         * @brief Draw scene at the screen
         * @param window Pointer to `ncurses`' window
         */
        void flush(WINDOW *window = stdscr);

    private:
        Table<chtype> charTable;  ///< Full picture of scene
        /**
         * @brief Table of numbers of the top layer at each position
         *
         * Entities of higher layer are in front of entities of lower one.
         * `layer` = 0 to hide sprite
         */
        Table<size_t> layerTable;

        /**
         * @brief Draw entity to the scene's tables
         * @param entity Entity to draw
         */
        void renderEntity(Entity& entity);
    };
}


#endif //TELUMO_CPP_SCENE_H
