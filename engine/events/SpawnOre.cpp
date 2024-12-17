#include "SpawnOre.h"

#include <functional>

SpawnOre::SpawnOre(Vector2 position)
{
    this->position = position;
}

void SpawnOre::Subscribe(std::vector<std::any>& callbackFunctions, const std::any& func)
{
    callbackFunctions.emplace_back(func);
}

void SpawnOre::Execute(std::vector<std::any>& callbackFunctions) const
{
    for (auto func : callbackFunctions)
    {
        std::any_cast<std::function<void(Vector2)>>(func)(this->position);
    }
}
