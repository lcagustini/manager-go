#include <raylib.h>
#include <flecs.h>

typedef struct {
    double x, y;
} position, velocity;

typedef struct {
    double radius;
    Color color;
} circle;

void move(ecs_iter_t *it) {
    position *p = ecs_term(it, position, 1);
    velocity *v = ecs_term(it, velocity, 2);

    for (int i = 0; i < it->count; i ++) {
        p[i].x += v[i].x * (double)it->delta_time;
        p[i].y += v[i].y * (double)it->delta_time;

        printf("%s moved to {.x = %f, .y = %f}\n", ecs_get_name(it->world, it->entities[i]), p[i].x, p[i].y);
    }
}

void drawCircle(ecs_iter_t *it) {
    position *p = ecs_term(it, position, 1);
    circle *c = ecs_term(it, circle, 2);

    for (int i = 0; i < it->count; i ++) {
        DrawCircle(p[i].x, p[i].y, c[i].radius, c[i].color);
    }
}

void beginDraw(ecs_iter_t *it) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void endDraw(ecs_iter_t *it) {
    EndDrawing();
}

int main(int argc, char *argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

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

    ecs_set_target_fps(world, 60);

    while (!WindowShouldClose()) {
        ecs_progress(world, 0);
    }

    ecs_fini(world);
    CloseWindow();

    return 0;
}
