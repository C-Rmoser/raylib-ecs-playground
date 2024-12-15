#include "GeometryRenderingSystem.h"

#include <unordered_map>
#include <vector>

#include "raymath.h"
#include "types.h"

void GeometryRenderingSystem::Render(
    const std::vector<Entity>& entities,
    const std::unordered_map<Entity, Vector2>& positions,
    const std::unordered_map<Entity, Vector2>& directions,
    const std::unordered_map<Entity, GeometryComponent>& geometryComponents,
    float cellSize
    )
{
    for (Entity entity : entities)
    {
        if (positions.contains(entity) && geometryComponents.contains(entity))
        {
            const auto [posX, posY] = positions.at(entity);
            const Color color = geometryComponents.at(entity).color;
            const Vector2 center{
                posX * cellSize + cellSize / 2,
                posY * cellSize + cellSize / 2
            };

            switch (geometryComponents.at(entity).shape)
            {
            case circle:
                {
                    DrawCircle(center.x, center.y, cellSize / 2 - 1, color);
                    break;
                }
            case rectangle:
                {
                    const auto rec = Rectangle{
                        center.x, center.y, cellSize, cellSize
                    };

                    const auto [dirX, dirY] = directions.at(entity);

                    DrawRectanglePro(rec, {cellSize / 2.0f, cellSize / 2.0f}, atan2(dirY, dirX) * (180.0f / PI), color);
                    break;
                }
            }

            const Vector2 scaledDirection{
                Vector2Multiply(directions.at(entity), Vector2{cellSize / 2, cellSize / 2})
            };

            auto [directionIndicatorX, directionIndicatorY] = Vector2Add(center, scaledDirection);
            DrawCircle(directionIndicatorX, directionIndicatorY, 3.0f, BLUE);
        }
    }
}
