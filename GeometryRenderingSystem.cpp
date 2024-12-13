#include "GeometryRenderingSystem.h"

#include "raymath.h"

void GeometryRenderingSystem::Render(
    const std::vector<unsigned int>& entities,
    const std::unordered_map<unsigned int, Vector2>& positions,
    const std::unordered_map<unsigned int, GeometryComponent>
    & geometryComponents) const
{
    for (unsigned int entity : entities)
    {
        if (positions.contains(entity) && geometryComponents.contains(entity))
        {
            const auto [posX, posY] = positions.at(entity);
            GeometryComponent geometryComponent = geometryComponents.at(entity);

            const Vector2 circlePos{
                posX * cellSize + cellSize / 2,
                posY * cellSize + cellSize / 2
            };
            const Vector2 scaledRotation{
                Vector2Multiply(geometryComponent.rotation, Vector2{cellSize / 2, cellSize / 2})
            };
            auto [directionIndicatorX, directionIndicatorY] = Vector2Add(circlePos, scaledRotation);

            DrawCircle(circlePos.x, circlePos.y, cellSize / 2 - 1, MAROON);
            DrawCircle(directionIndicatorX, directionIndicatorY, 3.0f, BLUE);
        }
    }
}
