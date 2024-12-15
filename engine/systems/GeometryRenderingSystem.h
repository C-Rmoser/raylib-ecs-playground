#ifndef GEOMETRYRENDERINGSYSTEM_H
#define GEOMETRYRENDERINGSYSTEM_H

#include <unordered_map>
#include <vector>

#include "raylib.h"
#include "types.h"
#include "components/GeometryRenderingComponent.h"

class GeometryRenderingSystem
{
    float cellSize{40.0};

public:
    void Render(
        const std::vector<Entity>& entities,
        const std::unordered_map<unsigned int, Vector2>& positions,
        const std::unordered_map<Entity, Vector2>& directions,
        const std::unordered_map<unsigned int, GeometryComponent>& geometryComponents) const;
};

#endif //GEOMETRYRENDERINGSYSTEM_H
