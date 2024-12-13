#include "EntityManager.h"

#include <algorithm>

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
    aliveEntities[entity] = true;

    return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
    aliveEntities[entity] = false;
    availableEntities.push(entity);

    positions.erase(entity);
    geometryComponents.erase(entity);
}
