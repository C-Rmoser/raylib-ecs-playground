#ifndef GEOMETRYRENDERINGSYSTEM_H
#define GEOMETRYRENDERINGSYSTEM_H

#include <unordered_map>
#include <vector>

#include "raylib.h"
#include "types.h"
#include "components/GeometryRenderingComponent.h"

class GeometryRenderingSystem
{
public:
    GeometryRenderingSystem() = delete;
    ~GeometryRenderingSystem() = delete;
    GeometryRenderingSystem(const GeometryRenderingSystem&) = delete;
    GeometryRenderingSystem& operator=(const GeometryRenderingSystem&) = delete;

    static void Render(
        const std::vector<Entity>& entities,
        const std::unordered_map<unsigned int, Vector2>& positions,
        const std::unordered_map<Entity, Vector2>& directions,
        const std::unordered_map<unsigned int, GeometryComponent>& geometryComponents,
        float cellSize);
};

#endif //GEOMETRYRENDERINGSYSTEM_H
