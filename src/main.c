#include <raylib.h>
#include <flecs.h>
#include <stdlib.h>

#include <ecs/components.h>
#include <ecs/systems.h>
#include <ecs/scenes.h>

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
