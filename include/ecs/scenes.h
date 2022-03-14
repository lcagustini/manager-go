#include <flecs.h>

#define MAX_SCENE_COUNT 10
#define TARGET_FPS 60

extern ecs_world_t *scenes[MAX_SCENE_COUNT];
extern int scenesCount;

int createScene(char *name);
