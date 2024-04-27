#pragma once
#include "./stationery.h"
#include "./pencil.h"
#include "./eraser.h"
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void sortByPrice(vector<T> &items)
{
    sort(items.begin(), items.end(), [](T s1, T s2)
         { return s1->price() < s2->price(); });
}

template <typename T, typename F>
void sortByPrice(vector<T> &items, F cmp )
{
    sort(items.begin(), items.end(), cmp );
}