#include <flecs.h>

#define MAX_SCENE_COUNT 10
#define TARGET_FPS 60

extern ecs_world_t *currentScene;

void createScene(char *name);
void switchScene(char *name);
void processSceneSwitch();
void deleteScene();

#ifdef DECLARE_TAGS
ECS_TAG_DECLARE(EcsInputGather);
ECS_TAG_DECLARE(EcsInputProcess);
ECS_TAG_DECLARE(EcsPreRender);
ECS_TAG_DECLARE(EcsOnRender);
ECS_TAG_DECLARE(EcsPostRender);
#else
ECS_TAG_EXTERN(EcsInputGather);
ECS_TAG_EXTERN(EcsInputProcess);
ECS_TAG_EXTERN(EcsPreRender);
ECS_TAG_EXTERN(EcsOnRender);
ECS_TAG_EXTERN(EcsPostRender);
#endif
