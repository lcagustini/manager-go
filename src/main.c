#include <raylib.h>
#include <flecs.h>
#include <stdlib.h>

#define DECLARE_COMPONENTS
#include <ecs/components.h>
#include <ecs/systems.h>

#define TARGET_FPS 60
#define MAX_SCENE_COUNT 10

ecs_world_t *scenes[MAX_SCENE_COUNT];
int scenesCount = 0;

int createBaseScene() {
    if (scenesCount >= MAX_SCENE_COUNT) return -1;

    ecs_world_t *world = ecs_init();

    ECS_TAG(world, EcsInputGather);
    ECS_TAG(world, EcsInputProcess);
    ECS_TAG(world, EcsPreRender);
    ECS_TAG(world, EcsOnRender);
    ECS_TAG(world, EcsPostRender);
    ECS_PIPELINE(world, CustomPipeline, EcsInputGather, EcsInputProcess, EcsPreUpdate, EcsOnUpdate, EcsOnValidate, EcsPostUpdate, EcsPreRender, EcsOnRender, EcsPostRender);
    ecs_set_pipeline(world, CustomPipeline);

    ECS_COMPONENT_DEFINE(world, position);
    ECS_COMPONENT_DEFINE(world, velocity);
    ECS_COMPONENT_DEFINE(world, circle);

    ECS_SYSTEM(world, move, EcsOnUpdate, position, velocity);
    ECS_SYSTEM(world, drawCircle, EcsOnRender, position, circle);
    ECS_SYSTEM(world, beginDraw, EcsPreRender);
    ECS_SYSTEM(world, endDraw, EcsPostRender);

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

#include "scenes.c"

int main(int argc, char *argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "manager-go");
    SetTargetFPS(TARGET_FPS);

    createScene("Test");

    while (!WindowShouldClose()) {
        for (int i = 0; i < scenesCount; i++) {
            ecs_progress(scenes[i], 0);
        }
    }

    for (int i = 0; i < scenesCount; i++) {
        ecs_fini(scenes[i]);
    }
    CloseWindow();

    return 0;
}
