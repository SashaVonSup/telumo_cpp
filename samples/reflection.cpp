#include "../telumo.h"

#include <unistd.h>

using namespace telumo;

int main() {
    size_t scene_h, scene_w, nFrames, speed;
    printf("Scene height: ");
    scanf("%zu", &scene_h);
    printf("Scene width: ");
    scanf("%zu", &scene_w);
    printf("# of frames: ");
    scanf("%zu", &nFrames);
    printf("Speed: ");
    scanf("%zu", &speed);
    int vel_x = speed, vel_y = speed;

    Entity entity0;
    entity0.charTable = Table<chtype>({{0, 'o', 0}, {'/', '|', '\\'}, {'/', 0, '\\'}});
    Scene scene(scene_h, scene_w);
    Entity& entity = scene.addEntity(entity0);
    initscr();
    curs_set(0);

    for (size_t i = 0; i < nFrames; ++i) {
        entity.x += vel_x;
        entity.y += vel_y;
        if (entity.x <= 0 || entity.x + entity.height() >= scene_h)
            vel_x = -vel_x;
        if (entity.y <= 0 || entity.y + entity.width() >= scene_w)
            vel_y = -vel_y;
        scene.render();
        scene.flush();
        sleep(1);
    }

    endwin();
    return 0;
}
