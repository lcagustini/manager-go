#include <flecs.h>

#define ADD_MOVE_TO_WORLD(when) ECS_SYSTEM(currentScene, move, when, transform, velocity)
void move(ecs_iter_t *it);

#define ADD_BEGIN_DRAW_TO_WORLD(when) ECS_SYSTEM(currentScene, beginDraw, when)
void beginDraw(ecs_iter_t *it);

#define ADD_END_DRAW_TO_WORLD(when) ECS_SYSTEM(currentScene, endDraw, when)
void endDraw(ecs_iter_t *it);

#define ADD_DRAW_SPRITE_TO_WORLD(when) ECS_SYSTEM(currentScene, drawSprite, when, rectTransform, sprite)
void drawSprite(ecs_iter_t *it);

#define ADD_UPDATE_SPLASH_SPRITE_TO_WORLD(when) ECS_SYSTEM(currentScene, updateSplashSprite, when, splashSprite, sprite)
void updateSplashSprite(ecs_iter_t *it);
