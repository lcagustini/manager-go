#include <ecs/systems.h>
#include <ecs/scenes.h>

int createSceneMainMenu() {
    ADD_BEGIN_DRAW_TO_WORLD(EcsPreRender);
    ADD_DRAW_SPRITE_TO_WORLD(EcsOnRender);
    ADD_END_DRAW_TO_WORLD(EcsPostRender);

    ECS_ENTITY(currentScene, Logo);
    ecs_set(currentScene, Logo, rectTransform, { 200, 50, 0, 1 });
    ecs_set(currentScene, Logo, sprite, { LoadTexture("assets/menu.png"), WHITE });
}
