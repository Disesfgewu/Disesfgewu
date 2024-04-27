#include <string>
#include <iostream>
#include "./vehicle.h"
class Car : public Vehicle
{
private:
    int *_year = nullptr;

public:
    static Car create(const std::string &brand, int year)
    {
        if (brand != "Porsche" && brand != "McLaren")
            throw std::string("Invalid Brand: " + brand);
        if (year > 2023)
            throw year;

        Car tmp;
        tmp._brand = brand;
        tmp._year = new int(year);

        return tmp;
    }

    Car() {}

    Car(const std::string &brand, int year)
    {
        *this = Car(Car::create(brand, year));

        // this->_brand = brand;
        // this->_year = new int(year);
    }

    ~Car() override
    {
        delete _year;
        _year = nullptr;
        // std::cout << "Check Destrucitor\n";
    }

    Car(const Car &other)
    {
        if (this->year() == nullptr)
            this->_year = new int(*(other.year()));
        else
            *(this->_year) = *(other.year());

        this->_brand = other.brand();
    }

    Car &operator=(const Car &other)
    {
        if (this->year() == nullptr)
            this->_year = new int(*(other.year()));
        else
            *(this->_year) = *(other.year());

        this->_brand = other.brand();

        return *this;
    }

    int *year() const
    {
        return _year;
    }
};