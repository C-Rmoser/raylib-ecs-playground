#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "raylib.h"

#include <queue>
#include <unordered_map>

#include "types.h"
#include "components/GeometryRenderingComponent.h"

class EntityManager
{
    explicit EntityManager(unsigned int maxEntities);
    ~EntityManager() = default;

public:
    std::queue<Entity> availableEntities{};
    std::vector<Entity> aliveEntities{};
    std::unordered_map<Entity, Vector2> positions{};
    std::unordered_map<Entity, Vector2> directions{};
    std::unordered_map<Entity, float> velocity;
    std::unordered_map<Entity, GeometryComponent> geometryComponents;

    static EntityManager& Instance(unsigned int maxEntities);
    Entity createEntity();
    void DestroyEntity(Entity entity);
};

#endif //ENTITYMANAGER_H
