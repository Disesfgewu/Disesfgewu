#pragma once
#include <cmath>
#include "./math_vector.h"
#include "./shape.h"
class Circle : public Shape{ //rule 1
public:

    Circle(const MathVector & center, double r, std::string name = "")
    : Shape(name), _center(center), _r(r)
    {}

    double area() const override { //rule 2
        return _r * _r * M_PI;
    }

protected:
    std::string name_of_type() const override
    {
        return "Circle";
    }

private:
    MathVector _center;
    double _r;
};