#include <flecs.h>

#define DECLARE_COMPONENTS
#include <ecs/components.h>
#include <ecs/scenes.h>
#define DECLARE_TAGS
#include <ecs/systems.h>

ecs_world_t *currentScene = NULL;

void createBaseScene() {
    currentScene = ecs_init();

    ECS_TAG_DEFINE(currentScene, EcsInputGather);
    ECS_TAG_DEFINE(currentScene, EcsInputProcess);
    ECS_TAG_DEFINE(currentScene, EcsPreRender);
    ECS_TAG_DEFINE(currentScene, EcsOnRender);
    ECS_TAG_DEFINE(currentScene, EcsPostRender);
    ECS_PIPELINE(currentScene, CustomPipeline, EcsInputGather, EcsInputProcess, EcsPreUpdate, EcsOnUpdate, EcsOnValidate, EcsPostUpdate, EcsPreRender, EcsOnRender, EcsPostRender);
    ecs_set_pipeline(currentScene, CustomPipeline);

    ECS_COMPONENT_DEFINE(currentScene, transform);
    ECS_COMPONENT_DEFINE(currentScene, rectTransform);
    ECS_COMPONENT_DEFINE(currentScene, velocity);
    ECS_COMPONENT_DEFINE(currentScene, sprite);
    ECS_COMPONENT_DEFINE(currentScene, splashSprite);

    ecs_set_target_fps(currentScene, TARGET_FPS);
}

#include "scenes/splash.c"
#include "scenes/mainMenu.c"

struct {
    char *name;
    int (*function)(void);
} sceneDefinitions[] = {
    { "Splash", createSceneSplash },
    { "MainMenu", createSceneMainMenu },
};
int sceneDefinitionsCount = 2;

void createScene(char *name) {
    for (int i = 0; i < sceneDefinitionsCount; i++) {
        if (strcmp(sceneDefinitions[i].name, name) == 0) {
            createBaseScene();
            sceneDefinitions[i].function();
            return;
        }
    }
}

char *sceneToSwitchTo = NULL;
void switchScene(char *name) {
    if (currentScene != NULL) {
        sceneToSwitchTo = name;
    }
    else {
        createScene(name);
    }
}

void processSceneSwitch() {
    if (sceneToSwitchTo != NULL) {
        deleteScene();
        createScene(sceneToSwitchTo);
        sceneToSwitchTo = NULL;
    }
}

void deleteScene() {
    ecs_fini(currentScene);

    currentScene = NULL;
}
