#include "Game.h"

#include <iostream>
#include <raylib.h>

#include "EntityManager.h"

int main()
{
    InitWindow(800, 450, "Raylib");
    SetTargetFPS(60);
    auto game = Game();
    auto entityManager = EntityManager();
    Entity entity = entityManager.createEntity();

    while (!WindowShouldClose())
    {
        game.Update();

        BeginDrawing();

        ClearBackground(SKYBLUE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
