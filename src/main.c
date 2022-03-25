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

    createScene("Splash");

    while (!WindowShouldClose()) {
        if (currentScene == NULL) break;

        ecs_progress(currentScene, 0);

        processSceneSwitch();
    }

    if (currentScene != NULL) {
        deleteScene();
    }
    CloseWindow();

    return 0;
}
