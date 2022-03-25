#include <ecs/systems.h>
#include <ecs/scenes.h>

int createSceneSplash() {
    ADD_UPDATE_SPLASH_SPRITE_TO_WORLD(EcsOnUpdate);
    ADD_BEGIN_DRAW_TO_WORLD(EcsPreRender);
    ADD_DRAW_SPRITE_TO_WORLD(EcsOnRender);
    ADD_END_DRAW_TO_WORLD(EcsPostRender);

    ECS_ENTITY(currentScene, FirstLogo);
    ecs_set(currentScene, FirstLogo, rectTransform, { 200, 75, 0, 1 });
    ecs_set(currentScene, FirstLogo, sprite, { LoadTexture("assets/logo.png"), WHITE });
    ecs_set(currentScene, FirstLogo, splashSprite, { 0, 5, 0 });
}
