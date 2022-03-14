#include <raylib.h>

typedef struct {
    double x, y;
} position;

typedef struct {
    double x, y;
} velocity;

typedef struct {
    double radius;
} circle;

#ifdef DECLARE_COMPONENTS
ECS_COMPONENT_DECLARE(position);
ECS_COMPONENT_DECLARE(velocity);
ECS_COMPONENT_DECLARE(circle);
#endif
