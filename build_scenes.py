#!/bin/python

import sys
import os

def getNextLine(file):
    return file.readline().strip()

print("#include \"scenes.c\"")

print("typedef struct {")
print("char *name;")
print("int (*function)(void);")
print("} sceneDefinition;")
print()

filepaths = os.listdir(sys.argv[1])
for filename in filepaths:
    filepath = os.path.join(sys.argv[1], filename)

    with open(filepath, "r") as file:
        print("int createScene" + getNextLine(file) + "() {")
        print("int id = createBaseScene();")
        command = getNextLine(file)

        if command == "entities":
            entities_count = 0
            while True:
                entity_name = getNextLine(file)
                if entity_name == "end":
                    break

                entities_count = entities_count + 1
                entity_var_name = "obj" + str(entities_count)
                print("ecs_entity_t " + entity_var_name + " = ecs_new(scenes[id], 0);")
                print("ecs_set_name(scenes[id], " + entity_var_name + ", \"" + entity_name + "\");")

                while True:
                    component_line = getNextLine(file)
                    if component_line == "end":
                        break
                    component_line_split = component_line.split(" ", 1)
                    print("ecs_set(scenes[id], " + entity_var_name + ", " + component_line_split[0] + ", " + component_line_split[1] + ");")

                print()

        print("return id;")
        print("}")
        print()

print("sceneDefinition sceneDefinitions[] = {")

for filename in filepaths:
    filepath = os.path.join(sys.argv[1], filename)

    with open(filepath, "r") as file:
        sceneName = getNextLine(file)
        print("{ \"" + sceneName + "\", createScene" + sceneName + " },")

print("};")
print("int sceneDefinitionsCount = " + str(len(filepaths)) + ";")
print()

print("int createScene(char *name) {")
print("for (int i = 0; i < sceneDefinitionsCount; i++) {")
print("if (strcmp(sceneDefinitions[i].name, name) == 0) {")
print("return sceneDefinitions[i].function();")
print("}")
print("}")
print("}")
print()
