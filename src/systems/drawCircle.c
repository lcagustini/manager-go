#include <flecs.h>
#include <ecs/components.h>

void drawCircle(ecs_iter_t *it) {
    position *p = ecs_term(it, position, 1);
    circle *c = ecs_term(it, circle, 2);

    for (int i = 0; i < it->count; i ++) {
        DrawCircle(p[i].x, p[i].y, c[i].radius, RED);
    }
}
