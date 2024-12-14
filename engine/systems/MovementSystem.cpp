#include "MovementSystem.h"

#include <vector>

void MovementSystem::Update(
    const std::vector<Entity>& entities,
    std::unordered_map<Entity, Vector2>& positions,
    const std::unordered_map<Entity, Vector2>& rotations,
    const std::unordered_map<Entity, float>& velocity)
{
    for (Entity entity : entities)
    {
        if (positions.contains(entity) && rotations.contains(entity) && velocity.contains(entity))
        {
            positions.at(entity).x += rotations.at(entity).x * velocity.at(entity) * GetFrameTime();
            positions.at(entity).y += rotations.at(entity).y * velocity.at(entity) * GetFrameTime();
        }
    }
}
