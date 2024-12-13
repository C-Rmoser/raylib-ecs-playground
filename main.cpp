#include "Game.h"

#include <iostream>
#include <raylib.h>

#include "EntityManager.h"
#include "GeometryRenderingSystem.h"

int main()
{
    InitWindow(1500, 1000, "Raylib");
    SetTargetFPS(60);
    auto game = Game();
    auto entityManager = EntityManager();

    const Entity extractor = entityManager.createEntity();
    entityManager.positions[extractor] = Vector2(10, 10);
    GeometryComponent geometryComponent = {1, 1, Vector2(0, 1)};
    entityManager.geometryComponents[extractor] = geometryComponent;

    const Entity extractor2 = entityManager.createEntity();
    entityManager.positions[extractor2] = Vector2(20, 15);
    entityManager.geometryComponents[extractor2] = geometryComponent;

    auto renderer = GeometryRenderingSystem();

    while (!WindowShouldClose())
    {
        game.Update();

        BeginDrawing();

        ClearBackground(SKYBLUE);
        renderer.Render(entityManager.aliveEntities, entityManager.positions, entityManager.geometryComponents);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
