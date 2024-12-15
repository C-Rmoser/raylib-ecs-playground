#include "Game.h"
#include "EntityManager.h"
#include "systems/MovementSystem.h"

Game& Game::Instance()
{
    static Game instance;
    return instance;
}


void Game::Update(EntityManager& entityManager)
{
    MovementSystem::Update(entityManager.aliveEntities,
                          entityManager.positions,
                          entityManager.directions,
                          entityManager.velocity
    );
}

void Game::Draw(const EntityManager& entityManager) const
{
    GeometryRenderingSystem::Render(entityManager.aliveEntities,
                                    entityManager.positions,
                                    entityManager.directions,
                                    entityManager.geometryComponents,
                                    cellSize);
}
