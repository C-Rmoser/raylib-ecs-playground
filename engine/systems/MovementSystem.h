#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "raylib.h"

#include <unordered_map>
#include <vector>

#include "GeometryRenderingSystem.h"

class MovementSystem
{

public:
    MovementSystem() = delete;
    ~MovementSystem() = delete;
    MovementSystem(const MovementSystem&) = delete;
    MovementSystem& operator=(const MovementSystem&) = delete;

    static void Update(
        const std::vector<Entity>& entities,
        std::unordered_map<Entity, Vector2>& positions,
        const std::unordered_map<Entity, Vector2>& directions,
        const std::unordered_map<Entity, float>& velocity
    );
};

#endif //MOVEMENTSYSTEM_H
