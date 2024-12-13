#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "EntityManager.h"
#include "raylib.h"

#include <unordered_map>

class MovementSystem
{
public:
    void Update(
        const std::vector<Entity>& entities,
        std::unordered_map<Entity, Vector2>& positions,
        const std::unordered_map<Entity, Vector2>& rotations,
        const std::unordered_map<Entity, float>& velocity
    );
};

#endif //MOVEMENTSYSTEM_H
