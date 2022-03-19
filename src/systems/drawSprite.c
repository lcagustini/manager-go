#include <flecs.h>
#include <ecs/components.h>

void drawSprite(ecs_iter_t *it) {
    position *p = ecs_term(it, position, 1);
    rotation *r = ecs_term(it, rotation, 2);
    scale *s = ecs_term(it, scale, 3);
    sprite *t = ecs_term(it, sprite, 4);

    for (int i = 0; i < it->count; i ++) {
        Vector2 pos = { p[i].x, p[i].y };
        DrawTextureEx(t[i].texture, pos, r[i].angle, s[i].amount, t[i].tint);
    }
}
