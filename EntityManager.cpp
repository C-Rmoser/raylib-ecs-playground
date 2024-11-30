#include "EntityManager.h"

EntityManager::EntityManager()
{
    for (uint32_t i = 0; i < 100000; ++i)
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
}
