#include "GeometryRenderingSystem.h"
#include "raymath.h"

void GeometryRenderingSystem::Render(
    const std::vector<Entity>& entities,
    const std::unordered_map<Entity, Vector2>& positions,
    const std::unordered_map<Entity, Vector2>& rotations,
    const std::unordered_map<Entity, GeometryComponent>& geometryComponents) const
{
    for (Entity entity : entities)
    {
        if (positions.contains(entity) && geometryComponents.contains(entity))
        {
            const auto [posX, posY] = positions.at(entity);

            const Vector2 circlePos{
                posX * cellSize + cellSize / 2,
                posY * cellSize + cellSize / 2
            };
            const Vector2 scaledRotation{
                Vector2Multiply(rotations.at(entity), Vector2{cellSize / 2, cellSize / 2})
            };
            auto [directionIndicatorX, directionIndicatorY] = Vector2Add(circlePos, scaledRotation);

            DrawCircle(circlePos.x, circlePos.y, cellSize / 2 - 1, MAROON);
            DrawCircle(directionIndicatorX, directionIndicatorY, 3.0f, BLUE);
        }
    }
}
