#include "EntityManager.h"

#include <algorithm>

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
    aliveEntities.push_back(entity);

    return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
    aliveEntities.erase(std::ranges::find(aliveEntities, entity));
    availableEntities.push(entity);
}
