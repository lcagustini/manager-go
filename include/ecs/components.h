#include <raylib.h>

typedef struct {
    Vector3 position;
    Quaternion rotation;
    Vector3 scale;
} transform;

typedef struct {
    Vector2 position;
    float rotation;
    float scale;
} rectTransform;

typedef Vector3 velocity;

typedef struct {
    Texture2D texture;
    Color tint;
} sprite;

typedef struct {
    int index;
    float time;
    float timer;
} splashSprite;

#ifdef DECLARE_COMPONENTS
ECS_COMPONENT_DECLARE(transform);
ECS_COMPONENT_DECLARE(rectTransform);
ECS_COMPONENT_DECLARE(velocity);
ECS_COMPONENT_DECLARE(sprite);
ECS_COMPONENT_DECLARE(splashSprite);
#endif
