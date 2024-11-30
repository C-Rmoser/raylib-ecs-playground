#ifndef GEOMETRYRENDERINGSYSTEM_H
#define GEOMETRYRENDERINGSYSTEM_H

#include "EntityManager.h"
#include "raylib.h"

class GeometryRenderingSystem
{
    float cellSize{40.0};

public:
    void Render(const std::vector<unsigned int>& entities,
                const std::unordered_map<unsigned int, Vector2>& positions,
                const std::unordered_map<unsigned int, GeometryComponent>& geometryComponents);
};

#endif //GEOMETRYRENDERINGSYSTEM_H
