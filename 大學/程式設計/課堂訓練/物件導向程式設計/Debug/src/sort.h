#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include "../src/eraser.h"
#include "../src/pencil.h"
#include "../src/stationery.h"

void sortByPrice(std::vector <Stationery *> & items){
    sort(items.begin(), items.end(), [](Stationery * a,Stationery * b){ //從小排到大
                                        return a->price() < b->price();
                                        });

}

void sortByPrice(std::vector<Pencil *> & items){
    sort(items.begin(), items.end(), [](Pencil * a,Pencil * b){ //從小排到大
                                        return a->price() < b->price();
                                        });
}

void sortByPrice(std::vector<Eraser *> & items){
    sort(items.begin(), items.end(), [](Eraser * a,Eraser * b){ //從小排到大
                                        return a->price() < b->price();
                                        });
}




