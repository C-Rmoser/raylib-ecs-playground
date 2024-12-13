#ifndef GEOMETRYRENDERINGSYSTEM_H
#define GEOMETRYRENDERINGSYSTEM_H

#include "EntityManager.h"
#include "raylib.h"

class GeometryRenderingSystem
{
    float cellSize{40.0};

public:
    void Render(bool(&entities)[100000],
                const std::unordered_map<unsigned int, Vector2>& positions,
                const std::unordered_map<unsigned int, GeometryComponent>& geometryComponents) const;
};

#endif //GEOMETRYRENDERINGSYSTEM_H
