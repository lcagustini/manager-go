#include <flecs.h>
#include <ecs/components.h>

void beginDraw(ecs_iter_t *it) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}
