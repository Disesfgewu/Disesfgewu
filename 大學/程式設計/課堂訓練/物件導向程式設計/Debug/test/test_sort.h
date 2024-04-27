#include "../src/sort.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;

TEST(SortTestCase, ComposeSortTest1){
    Pencil p1(18, "H"); //55.8
    Pencil p2(15, "2B"); //30
    Pencil p3(12, "2H"); //31.2
    Eraser e1("Large", "MUJI"); //116
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);

    ASSERT_EQ(items.at(0)->price(), 30 ); //30
    ASSERT_NEAR((items.at(1))->price(), 31.2, 0.001); //31.2
    ASSERT_NEAR((items.at(2))->price(), 55.8, 0.001); //0
    ASSERT_EQ((items.at(3))->price(), 116);
}

TEST(SortTestCase, PencilSortTest){
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");

    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items);
    
    ASSERT_EQ((items.at(0))->price(), 30 );
    ASSERT_NEAR((items.at(1))->price(), 31.2, 0.001);
    ASSERT_NEAR((items.at(2))->price(), 55.8, 0.001);
}
