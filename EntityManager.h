#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <array>
#include <cstdint>
#include <queue>
#include <unordered_map>

#include "raylib.h"

using Entity = uint32_t;

struct GeometryComponent
{
    float width;
    float height;
    Vector2 rotation;
};

class EntityManager
{
public:
    const unsigned int maxEntities = 100000;

    std::queue<Entity> availableEntities{};
    bool aliveEntities[100000]{};
    std::unordered_map<Entity, Vector2> positions{};
    std::unordered_map<Entity, GeometryComponent> geometryComponents;

    EntityManager();
    Entity createEntity();
    void DestroyEntity(Entity entity);
};

#endif //ENTITYMANAGER_H
