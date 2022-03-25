#include <flecs.h>
#include <ecs/components.h>
#include <raymath.h>

void move(ecs_iter_t *it) {
    transform *t = ecs_term(it, transform, 1);
    velocity *v = ecs_term(it, velocity, 2);

    for (int i = 0; i < it->count; i ++) {
        t[i].position = Vector3Add(t[i].position, Vector3Scale(v[i], it->delta_time));
    }
}
