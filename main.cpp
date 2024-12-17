#include <functional>
#include <iostream>
#include <raylib.h>

#include "Game.h"
#include "EntityManager.h"

#include "engine/types.h"
#include "events/EventManager.h"
#include "events/SpawnOre.h"

void ReactToSpawnedOre(Vector2 value)
{
    std::cout << "Spawning ore with value: " << value.x << " | " << value.y << std::endl;
}

int main()
{
    InitWindow(1500, 1000, "Raylib");
    SetTargetFPS(60);
    auto& game = Game::Instance();
    auto& entityManager = EntityManager::Instance(100000);
    auto& eventManager = EventManager::Instance();
    std::unique_ptr<Event> spawnOreEvent = std::make_unique<SpawnOre>(Vector2(14, 4));

    auto event = SpawnOre();
    eventManager.Subscribe(event, std::function<void(Vector2)>([](const Vector2 value)
    {
        ReactToSpawnedOre(value);
    }));
    eventManager.Publish(std::move(spawnOreEvent));

    const Entity extractor = entityManager.createEntity();
    entityManager.positions[extractor] = Vector2(10, 10);
    entityManager.directions[extractor] = Vector2(0, -1);
    entityManager.velocity[extractor] = 1.0f;
    GeometryComponent geometryComponent = {1, 1, circle, MAROON};
    entityManager.geometryComponents[extractor] = geometryComponent;

    const Entity extractor2 = entityManager.createEntity();
    entityManager.positions[extractor2] = Vector2(20, 15);
    entityManager.directions[extractor2] = Vector2(1, 0);
    entityManager.velocity[extractor2] = 1.0f;
    geometryComponent = {1, 1, rectangle, YELLOW};
    entityManager.geometryComponents[extractor2] = geometryComponent;


    while (!WindowShouldClose())
    {
        Game::Update(entityManager);
        eventManager.Update();

        BeginDrawing();

        ClearBackground(SKYBLUE);

        game.Draw(entityManager);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
