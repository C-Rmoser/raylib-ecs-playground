#include "MovementSystem.h"

#include <vector>

void MovementSystem::Update(
    const std::vector<Entity>& entities,
    std::unordered_map<Entity, Vector2>& positions,
    const std::unordered_map<Entity, Vector2>& directions,
    const std::unordered_map<Entity, float>& velocity)
{
    for (Entity entity : entities)
    {
        if (positions.contains(entity) && directions.contains(entity) && velocity.contains(entity))
        {
            positions.at(entity).x += directions.at(entity).x * velocity.at(entity) * GetFrameTime();
            positions.at(entity).y += directions.at(entity).y * velocity.at(entity) * GetFrameTime();
        }
    }
}
