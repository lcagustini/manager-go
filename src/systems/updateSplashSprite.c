#include <flecs.h>
#include <ecs/components.h>
#include <ecs/scenes.h>

void updateSplashSprite(ecs_iter_t *it) {
    splashSprite *ss = ecs_term(it, splashSprite, 1);
    sprite *s = ecs_term(it, sprite, 2);

    int current_index = -1;
    for (int i = 0; i < it->count; i ++) {
        if (ss[i].timer < ss[i].time && (current_index == -1 || ss[i].index < ss[current_index].index)) {
            current_index = i;
        }
    }

    if (current_index != -1) {
        ss[current_index].timer += it->delta_time;
        s[current_index].tint = Fade(s[current_index].tint, (-4 * ss[current_index].timer * ss[current_index].timer)/(ss[current_index].time * ss[current_index].time) + (4 * ss[current_index].timer)/ss[current_index].time);
    }
    else {
        switchScene("MainMenu");
    }
}
