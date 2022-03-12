#include <flecs.h>
#include <ecs/components.h>

void move(ecs_iter_t *it) {
    position *p = ecs_term(it, position, 1);
    velocity *v = ecs_term(it, velocity, 2);

    for (int i = 0; i < it->count; i ++) {
        p[i].x += v[i].x * (double)it->delta_time;
        p[i].y += v[i].y * (double)it->delta_time;
    }
}
