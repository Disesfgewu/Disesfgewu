#include "../src/stationery.h"
#include "../src/eraser.h"
#include "../src/pencil.h"
#include "../src/sort.h"

#include <vector>

using namespace std;

TEST(StationeryTestCase, StationeryPencilTest)
{
    Pencil p1(18, "H");
    Stationery *s1 = &p1;
    ASSERT_EQ(s1->number(), 3.1);
    ASSERT_EQ(s1->price(), 3.1 * 18);
    ASSERT_EQ(s1->name(), "H Pencil");
}

TEST(StationeryTestCase, StationeryEraserTest)
{
    Eraser e1("Large", "MUJI");
    Stationery *s1 = &e1;
    ASSERT_EQ(s1->number(), 29);
    ASSERT_EQ(s1->price(), 4 * 29);
    ASSERT_EQ(s1->size(), 4);
}

TEST(StationeryTestCase, StationeryVectorCreateTest)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");
    Eraser e1("Large", "MUJI");

    vector<Stationery *> items = {&p1, &p2, &p3, &e1};

    ASSERT_EQ(items[0]->price(), 3.1 * 18);
    ASSERT_EQ(items[1]->price(), 2.0 * 15);
    ASSERT_EQ(items[2]->price(), 2.6 * 12);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST(StationeryTestCase, StationerySortTest)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");
    Eraser e1("Large", "MUJI");

    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST(PencilSortCase, PencilSortByPrice)
{
    Pencil p1(18, "H");
    Pencil p2(15, "2B");
    Pencil p3(12, "2H");
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
}

TEST(EraserSortCase, EraserSortByPrice)
{
    Eraser e1("Large", "MUJI");
    Eraser e2("Medium", "MUJI");
    Eraser e3("Small", "MUJI");
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[2]->price(), 4 * 29);
}