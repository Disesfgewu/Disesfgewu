#pragma once
class Shape {
public:
    // pointer to function area equal zero
    virtual double area() const = 0;

    std::string name() const
    {
        return _name + "(" + name_of_type() + ")";
    }

protected:
    Shape(std::string name = "")
    : _name(name) {}
    virtual std::string name_of_type() const = 0;

private:
    const std::string _name;
};