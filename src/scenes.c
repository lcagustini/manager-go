typedef struct {
char *name;
int (*function)(void);
} sceneDefinition;

int createSceneTest() {
int id = createBaseScene();
ecs_entity_t obj1 = ecs_new(scenes[id], 0);
ecs_set_name(scenes[id], obj1, "MyEntity");
ecs_set(scenes[id], obj1, position, { 10, 10 });
ecs_set(scenes[id], obj1, circle, { 20 });

ecs_entity_t obj2 = ecs_new(scenes[id], 0);
ecs_set_name(scenes[id], obj2, "MyEntity2");
ecs_set(scenes[id], obj2, position, { 10, 10 });
ecs_set(scenes[id], obj2, velocity, { 1, 1 });
ecs_set(scenes[id], obj2, circle, { 10 });

return id;
}

int createSceneTest2() {
int id = createBaseScene();
ecs_entity_t obj1 = ecs_new(scenes[id], 0);
ecs_set_name(scenes[id], obj1, "MyEntity2");
ecs_set(scenes[id], obj1, position, { 10, 10 });
ecs_set(scenes[id], obj1, velocity, { 10, 10 });
ecs_set(scenes[id], obj1, circle, { 10 });

return id;
}

sceneDefinition sceneDefinitions[] = {
{ "Test", createSceneTest },
{ "Test2", createSceneTest2 },
};
int sceneDefinitionsCount = 2;

int createScene(char *name) {
for (int i = 0; i < sceneDefinitionsCount; i++) {
if (strcmp(sceneDefinitions[i].name, name) == 0) {
return sceneDefinitions[i].function();
}
}
}

