#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <cstdint>
#include <queue>

using Entity = uint32_t;

class EntityManager
{
public:
    std::queue<Entity> availableEntities;
    bool aliveEntities[100000]{};

    EntityManager();
    Entity createEntity();
    void DestroyEntity(Entity entity);
};

#endif //ENTITYMANAGER_H
