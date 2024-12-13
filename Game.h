#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"
#include "GeometryRenderingSystem.h"
#include "MovementSystem.h"

class Game
{
    Game() = default;
    ~Game() = default;

public:
    GeometryRenderingSystem renderer{};
    MovementSystem movementSystem{};

    static Game& Instance();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void Update(EntityManager& entityManager);
    void Draw(const EntityManager& entityManager) const;
};

#endif // GAME_H
