#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <memory>
#include <queue>
#include <unordered_map>

#include "Event.h"

class EventManager
{
    std::queue<std::unique_ptr<Event>> eventQueue{};
    std::unordered_map<std::string, std::vector<std::any>> eventSubscriptions;

    EventManager() = default;

public:
    static EventManager& Instance();
    void Publish(std::unique_ptr<Event> event);
    void Subscribe(Event& event, const std::any& func);
    void Update();
};

#endif //EVENTMANAGER_H
