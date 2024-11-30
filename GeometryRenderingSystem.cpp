#include "GeometryRenderingSystem.h"

#include "raymath.h"

void GeometryRenderingSystem::Render(const std::vector<unsigned int>& entities,
                                     const std::unordered_map<unsigned int, Vector2>& positions,
                                     const std::unordered_map<unsigned int, GeometryComponent>& geometryComponents)
{
    for (int i = 0; i < entities.size(); ++i)
    {
        auto entity = entities[i];
        if (positions.contains(entity) && geometryComponents.contains(entity))
        {
            Vector2 position = positions.at(entity);
            GeometryComponent geometryComponent = geometryComponents.at(entity);

            Vector2 circlePos{position.x * cellSize + cellSize / 2, position.y * cellSize + cellSize / 2};
            Vector2 scaledRotation{Vector2Multiply(geometryComponent.rotation, Vector2{cellSize / 2, cellSize / 2})};
            Vector2 directionIndicatorPos = Vector2Add(circlePos, scaledRotation);

            DrawCircle(circlePos.x, circlePos.y, cellSize / 2 - 1, MAROON);
            DrawCircle(directionIndicatorPos.x, directionIndicatorPos.y, 3.0f, BLUE);
        }
    }
}
