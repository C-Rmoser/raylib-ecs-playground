#ifndef SPAWNORE_H
#define SPAWNORE_H

#include <any>
#include <string>
#include <vector>

#include "Event.h"
#include "raylib.h"

class SpawnOre : public Event
{
public:
    std::string eventName{"spawnOre"};
    Vector2 position{0, 0};

    explicit SpawnOre(Vector2 position);
    void Subscribe(std::vector<std::any>& callbackFunctions, const std::any& func) override;
    void Execute(std::vector<std::any>& callbackFunctions) const override;
    SpawnOre() = default;
};

#endif //SPAWNORE_H
