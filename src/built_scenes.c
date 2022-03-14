#include "scenes.c"
typedef struct {
char *name;
int (*function)(void);
} sceneDefinition;

int createSceneTest() {
int id = createBaseScene();
ecs_entity_t obj1 = ecs_new(scenes[id], 0);
ecs_set_name(scenes[id], obj1, "MyEntity");
ecs_set(scenes[id], obj1, position, { 500, 10 });
ecs_set(scenes[id], obj1, velocity, { -20, 5 });
ecs_set(scenes[id], obj1, circle, { 10 });

return id;
}

sceneDefinition sceneDefinitions[] = {
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

