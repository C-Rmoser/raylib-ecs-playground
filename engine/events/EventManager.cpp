#include "EventManager.h"

#include <iostream>

EventManager& EventManager::Instance()
{
    static EventManager INSTANCE;
    return INSTANCE;
}

void EventManager::Publish(std::unique_ptr<Event> event)
{
    eventQueue.emplace(std::move(event));
}

void EventManager::Subscribe(Event& event, const std::any& func)
{
    event.Subscribe(eventSubscriptions[event.eventName], func);
}

void EventManager::Update()
{
    while (!eventQueue.empty())
    {
        std::unique_ptr<Event> event = std::move(eventQueue.front());
        std::cout << "Handling event: " << event->eventName << std::endl;
        event->Execute(eventSubscriptions[event->eventName]);

        eventQueue.pop();
    }
}
