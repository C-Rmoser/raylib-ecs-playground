#ifndef EVENT_H
#define EVENT_H

#include <any>
#include <string>
#include <vector>

class Event
{
public:
    std::string eventName{};

    virtual void Subscribe(std::vector<std::any>& callbackFunctions, const std::any& func) = 0;
    virtual void Execute(std::vector<std::any>& callbackFunctions) const = 0;
    virtual ~Event() = default;
};

#endif //EVENT_H
