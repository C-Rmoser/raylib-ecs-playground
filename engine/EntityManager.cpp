#include "EntityManager.h"

EntityManager::EntityManager(const unsigned int maxEntities)
{
    for (Entity i = 0; i < maxEntities; ++i)
    {
        availableEntities.push(i);
    }
}

EntityManager& EntityManager::Instance(const unsigned int maxEntities)
{
    static EntityManager instance(maxEntities);
    return instance;
}

Entity EntityManager::createEntity()
{
    const Entity entity = availableEntities.front();
    availableEntities.pop();
    aliveEntities.push_back(entity);

    return entity;
}

void EntityManager::DestroyEntity(Entity entity)
{
    aliveEntities.erase(std::ranges::find(aliveEntities, entity));
    availableEntities.push(entity);

    positions.erase(entity);
    directions.erase(entity);
    geometryComponents.erase(entity);
}
