#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "raylib.h"

#include <cstdint>
#include <queue>
#include <unordered_map>

using Entity = uint32_t;

struct GeometryComponent
{
    float width;
    float height;
};

class EntityManager
{
public:
    const unsigned int maxEntities = 100000;

    std::queue<Entity> availableEntities{};
    std::vector<Entity> aliveEntities{};
    std::unordered_map<Entity, Vector2> positions{};
    std::unordered_map<Entity, Vector2> rotations{};
    std::unordered_map<Entity, float> velocity;
    std::unordered_map<Entity, GeometryComponent> geometryComponents;

    EntityManager();
    Entity createEntity();
    void DestroyEntity(Entity entity);
};

#endif //ENTITYMANAGER_H
