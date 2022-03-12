#include <raylib.h>
#include <flecs.h>

#include <ecs/components.h>
#include <ecs/systems.h>

#define TARGET_FPS 60

int main(int argc, char *argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "manager-go");
    SetTargetFPS(TARGET_FPS);

    ecs_world_t *world = ecs_init_w_args(argc, argv);

    ECS_TAG(world, EcsInputGather);
    ECS_TAG(world, EcsInputProcess);
    ECS_TAG(world, EcsPreRender);
    ECS_TAG(world, EcsOnRender);
    ECS_TAG(world, EcsPostRender);
    ECS_PIPELINE(world, CustomPipeline, EcsInputGather, EcsInputProcess, EcsPreUpdate, EcsOnUpdate, EcsOnValidate, EcsPostUpdate, EcsPreRender, EcsOnRender, EcsPostRender);
    ecs_set_pipeline(world, CustomPipeline);

    ECS_COMPONENT(world, position);
    ECS_COMPONENT(world, velocity);
    ECS_COMPONENT(world, circle);

    ECS_SYSTEM(world, move, EcsOnUpdate, position, velocity);
    ECS_SYSTEM(world, drawCircle, EcsOnRender, position, circle);
    ECS_SYSTEM(world, beginDraw, EcsPreRender);
    ECS_SYSTEM(world, endDraw, EcsPostRender);

    ECS_ENTITY(world, MyEntity, position, velocity);

    ecs_set(world, MyEntity, position, {0, 0});
    ecs_set(world, MyEntity, velocity, {10, 10});
    ecs_set(world, MyEntity, circle, {20, RED});

    ecs_set_target_fps(world, TARGET_FPS);

    while (!WindowShouldClose()) {
        ecs_progress(world, 0);
    }

    ecs_fini(world);
    CloseWindow();

    return 0;
}
