int createSceneSplash() {
    int id = createBaseScene();

    ECS_ENTITY(scenes[id], MainLogo);
    ecs_set(scenes[id], MainLogo, position, { 200, 75 });
    ecs_set(scenes[id], MainLogo, rotation, { 0 });
    ecs_set(scenes[id], MainLogo, scale, { 1 });
    ecs_set(scenes[id], MainLogo, sprite, { LoadTexture("assets/logo.png"), WHITE });

    return id;
}
