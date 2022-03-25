#include <flecs.h>
#include <ecs/components.h>

void drawSprite(ecs_iter_t *it) {
    rectTransform *t = ecs_term(it, rectTransform, 1);
    sprite *s = ecs_term(it, sprite, 2);

    for (int i = 0; i < it->count; i ++) {
        DrawTextureEx(s[i].texture, t[i].position, t[i].rotation, t[i].scale, s[i].tint);
    }
}
