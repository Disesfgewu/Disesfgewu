#pragma once
#include "device.h"

template <class RandomAccessIterator, class Compare>
std::vector<Device *> find_device(RandomAccessIterator begin, RandomAccessIterator end, Compare comp) {
    // an empty vector for the filterd devices.
    std::vector<Device *> result;

    // compare all devices, add devices satisfying the condition to the vector
    for (RandomAccessIterator i = begin; i != end; i++) {
        if (comp(*i)){
            result.push_back(*i);
        }
    }

    return result;
}
