#include "Game.h"
#include "EntityManager.h"
#include "GeometryRenderingSystem.h"
#include "MovementSystem.h"

#include <raylib.h>

int main()
{
    InitWindow(1500, 1000, "Raylib");
    SetTargetFPS(60);
    auto game = Game();
    auto entityManager = EntityManager();

    const Entity extractor = entityManager.createEntity();
    entityManager.positions[extractor] = Vector2(10, 10);
    entityManager.rotations[extractor] = Vector2(0, -1);
    entityManager.velocity[extractor] = 1.0f;
    GeometryComponent geometryComponent = {1, 1};
    entityManager.geometryComponents[extractor] = geometryComponent;

    const Entity extractor2 = entityManager.createEntity();
    entityManager.positions[extractor2] = Vector2(20, 15);
    entityManager.rotations[extractor2] = Vector2(1, 0);
    entityManager.velocity[extractor2] = 1.0f;
    entityManager.geometryComponents[extractor2] = geometryComponent;

    auto renderer = GeometryRenderingSystem();
    auto movementSystem = MovementSystem();

    while (!WindowShouldClose())
    {
        game.Update();
        movementSystem.Update(entityManager.aliveEntities,
                              entityManager.positions,
                              entityManager.rotations,
                              entityManager.velocity
        );

        BeginDrawing();

        ClearBackground(SKYBLUE);
        renderer.Render(entityManager.aliveEntities,
                        entityManager.positions,
                        entityManager.rotations,
                        entityManager.geometryComponents);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
