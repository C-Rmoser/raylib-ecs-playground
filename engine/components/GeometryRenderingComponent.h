#ifndef GEOMETRYRENDERINGCOMPONENT_H
#define GEOMETRYRENDERINGCOMPONENT_H

enum Shape
{
    rectangle,
    circle,
};

struct GeometryComponent
{
    float width;
    float height;
    Shape shape;
    Color color;
};

#endif //GEOMETRYRENDERINGCOMPONENT_H
