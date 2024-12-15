#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"

class Game
{
    Game() = default;
    ~Game() = default;

public:
    float cellSize = 40.0f;

    static Game& Instance();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static void Update(EntityManager& entityManager);
    void Draw(const EntityManager& entityManager) const;
};

#endif // GAME_H
