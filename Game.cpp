#include "Game.h"
#include "EntityManager.h"

Game& Game::Instance()
{
    static Game instance;
    return instance;
}


void Game::Update(EntityManager& entityManager)
{
    movementSystem.Update(entityManager.aliveEntities,
                          entityManager.positions,
                          entityManager.rotations,
                          entityManager.velocity
    );
}

void Game::Draw(const EntityManager& entityManager) const
{
    renderer.Render(entityManager.aliveEntities,
                    entityManager.positions,
                    entityManager.rotations,
                    entityManager.geometryComponents);
}
