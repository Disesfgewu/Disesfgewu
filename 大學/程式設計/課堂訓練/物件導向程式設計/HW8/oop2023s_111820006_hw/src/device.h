#include <string>
#pragma once

class Device {
protected:
    int _size;
    std::string _os;

public:
    // Default constructor
    Device() {}

    // Constructor that accepts the size and the OS of the deivce
    Device(int size, std::string os): _size(size), _os(os) {
    }

    // Return size of the device
    int size() const {
        return _size;
    }

    // Return OS of the device
    std::string os() const {
        return _os;
    }

    // To be overridden by derived class
    virtual std::string name_of_type() const = 0;

    // Returns a string with device information
    std::string information() {
        return "A " + std::to_string(_size) + "-inch " + name_of_type() + " loaded with " + _os;
    }
};