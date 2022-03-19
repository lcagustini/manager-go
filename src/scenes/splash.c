int createSceneSplash() {
    int id = createBaseScene();

    ECS_ENTITY(scenes[id], MainLogo);
    ecs_set(scenes[id], MainLogo, position, { 500, 10 });
    ecs_set(scenes[id], MainLogo, velocity, { -20, 5 });

    return id;
}
