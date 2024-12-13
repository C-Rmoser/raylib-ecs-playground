#include "EntityManager.h"

EntityManager::EntityManager()
{
    for (uint32_t i = 0; i < maxEntities; ++i)
    {
        availableEntities.push(i);
    }
}

Entity EntityManager::createEntity()
{
    Entity entity = availableEntities.front();
    availableEntities.pop();
    aliveEntities.push_back(entity);

    return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
    aliveEntities.erase(std::ranges::find(aliveEntities, entity));
    availableEntities.push(entity);

    positions.erase(entity);
    rotations.erase(entity);
    geometryComponents.erase(entity);
}
