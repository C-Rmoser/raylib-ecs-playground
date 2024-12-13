#include "Game.h"
#include "EntityManager.h"

#include <raylib.h>

int main()
{
    InitWindow(1500, 1000, "Raylib");
    SetTargetFPS(60);
    auto& game = Game::Instance();
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

    while (!WindowShouldClose())
    {
        game.Update(entityManager);

        BeginDrawing();

        ClearBackground(SKYBLUE);

        game.Draw(entityManager);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
