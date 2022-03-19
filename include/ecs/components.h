#include <raylib.h>

typedef struct {
    float x, y;
} position;

typedef struct {
    float angle;
} rotation;

typedef struct {
    float amount;
} scale;

typedef struct {
    float x, y;
} velocity;

typedef struct {
    Texture2D texture;
    Color tint;
} sprite;

#ifdef DECLARE_COMPONENTS
ECS_COMPONENT_DECLARE(position);
ECS_COMPONENT_DECLARE(rotation);
ECS_COMPONENT_DECLARE(scale);
ECS_COMPONENT_DECLARE(velocity);
ECS_COMPONENT_DECLARE(sprite);
#endif
