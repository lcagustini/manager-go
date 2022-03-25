#include <flecs.h>

#define DECLARE_COMPONENTS
#include <ecs/components.h>
#include <ecs/scenes.h>
#define DECLARE_TAGS
#include <ecs/systems.h>

ecs_world_t *scenes[MAX_SCENE_COUNT];
int scenesCount;

int createBaseScene() {
    if (scenesCount >= MAX_SCENE_COUNT) return -1;

    ecs_world_t *world = ecs_init();

    ECS_TAG_DEFINE(world, EcsInputGather);
    ECS_TAG_DEFINE(world, EcsInputProcess);
    ECS_TAG_DEFINE(world, EcsPreRender);
    ECS_TAG_DEFINE(world, EcsOnRender);
    ECS_TAG_DEFINE(world, EcsPostRender);
    ECS_PIPELINE(world, CustomPipeline, EcsInputGather, EcsInputProcess, EcsPreUpdate, EcsOnUpdate, EcsOnValidate, EcsPostUpdate, EcsPreRender, EcsOnRender, EcsPostRender);
    ecs_set_pipeline(world, CustomPipeline);

    ECS_COMPONENT_DEFINE(world, transform);
    ECS_COMPONENT_DEFINE(world, rectTransform);
    ECS_COMPONENT_DEFINE(world, velocity);
    ECS_COMPONENT_DEFINE(world, sprite);
    ECS_COMPONENT_DEFINE(world, splashSprite);

    ecs_set_target_fps(world, TARGET_FPS);

    int currentIndex = scenesCount;
    scenes[currentIndex] = world;
    scenesCount++;

    return currentIndex;
}

int deleteScene(int i) {
    ecs_fini(scenes[i]);

    scenesCount--;
    for (; i < scenesCount; i++) {
        scenes[i] = scenes[i+1];
    }
}

#include "scenes/splash.c"
#include "scenes/test.c"

struct {
    char *name;
    int (*function)(void);
} sceneDefinitions[] = {
    { "Splash", createSceneSplash },
    { "Test", createSceneTest },
};
int sceneDefinitionsCount = 1;

int createScene(char *name) {
    for (int i = 0; i < sceneDefinitionsCount; i++) {
        if (strcmp(sceneDefinitions[i].name, name) == 0) {
            return sceneDefinitions[i].function();
        }
    }
}
