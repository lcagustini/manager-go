#include <raylib.h>
#include <flecs.h>

typedef struct {
    double x, y;
} Position, Velocity;

void Move(ecs_iter_t *it) {
    Position *p = ecs_term(it, Position, 1);
    Velocity *v = ecs_term(it, Velocity, 2);

    for (int i = 0; i < it->count; i ++) {
        /* Use delta_time to update the entity proportionally to the amount of
         * time that has passed inbetween frames. */
        p[i].x += v[i].x * (double)it->delta_time;
        p[i].y += v[i].y * (double)it->delta_time;

        printf("%s moved to {.x = %f, .y = %f}\n",
            ecs_get_name(it->world, it->entities[i]),
            p[i].x, p[i].y);
    }
}

int main(int argc, char *argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    ecs_world_t *world = ecs_init_w_args(argc, argv);

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ECS_SYSTEM(world, Move, EcsOnUpdate, Position, Velocity);

    ECS_ENTITY(world, MyEntity, Position, Velocity);

    ecs_set(world, MyEntity, Position, {0, 0});
    ecs_set(world, MyEntity, Velocity, {1, 1});

    ecs_set_target_fps(world, 60);

    while (!WindowShouldClose()) {
        ecs_progress(world, 0);

        BeginDrawing();

	ClearBackground(RAYWHITE);
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    ecs_fini(world);
    CloseWindow();

    return 0;
}
