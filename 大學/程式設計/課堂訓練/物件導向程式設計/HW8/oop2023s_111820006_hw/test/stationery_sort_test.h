#include "../src/stationery.h"
#include "../src/eraser.h"
#include "../src/pencil.h"
#include "../src/sort.h"

#include <vector>

using namespace std;

class SortCase : public ::testing ::Test
{
protected:
    void SetUp() override {}
    Pencil p1{"Willison", 18, "H"};
    Pencil p2{"Wilson", 15, "2B"};
    Pencil p3{"Oscar", 12, "2H"};
    Eraser e1{"Lieshen", "Large", "MUJI"};
    Eraser e2{"Andy", "Medium", "MUJI"};
    Eraser e3{"Harrison", "Small", "MUJI"};
};

TEST_F(SortCase, StationeryPencilTest)
{
    Stationery *s1 = &p1;
    ASSERT_EQ(s1->name(), "H Pencil");
}

TEST_F(SortCase, StationeryEraserTest)
{
    Stationery *s1 = &e1;
    ASSERT_EQ(s1->price(), 4 * 29);
}

TEST_F(SortCase, StationeryVectorCreateTest)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};

    ASSERT_EQ(items[0]->price(), 3.1 * 18);
    ASSERT_EQ(items[1]->price(), 2.0 * 15);
    ASSERT_EQ(items[2]->price(), 2.6 * 12);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST_F(SortCase, StationerySortTest)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST_F(SortCase, PencilSortByPrice)
{
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
}

TEST_F(SortCase, EraserSortByPrice)
{
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items);
    ASSERT_EQ(items[0]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[2]->price(), 4 * 29);
}

TEST_F(SortCase, StationerySortByPriceAscLambda)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, [](Stationery *a, Stationery *b)
                { return a->price() < b->price(); });
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST_F(SortCase, StationerySortByPriceDesLambda)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, [](Stationery *a, Stationery *b)
                { return a->price() > b->price(); });
    ASSERT_EQ(items[3]->price(), 2.0 * 15);
    ASSERT_EQ(items[2]->price(), 2.6 * 12);
    ASSERT_EQ(items[1]->price(), 3.1 * 18);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}

bool DecFunction(Stationery *a, Stationery *b)
{
    return a->price() > b->price();
}

TEST_F(SortCase, StationerySortByPriceDescFunction)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, DecFunction);
    ASSERT_EQ(items[3]->price(), 2.0 * 15);
    ASSERT_EQ(items[2]->price(), 2.6 * 12);
    ASSERT_EQ(items[1]->price(), 3.1 * 18);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}

bool AscFunction(Stationery *a, Stationery *b)
{
    return a->price() < b->price();
}

TEST_F(SortCase, StationerySortByPriceAscFunction)
{
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, AscFunction);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST_F(SortCase, StationerySortByPriceDescClass)
{
    class cmp
    {
    public:
        bool operator()(Stationery *a, Stationery *b)
        {
            return a->price() > b->price();
        }
    };
    cmp lambda;
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, lambda);
    ASSERT_EQ(items[3]->price(), 2.0 * 15);
    ASSERT_EQ(items[2]->price(), 2.6 * 12);
    ASSERT_EQ(items[1]->price(), 3.1 * 18);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}

TEST_F(SortCase, StationerySortByPriceAcsClass)
{
    class cmp
    {
    public:
        bool operator()(Stationery *a, Stationery *b)
        {
            return a->price() < b->price();
        }
    };
    vector<Stationery *> items = {&p1, &p2, &p3, &e1};
    sortByPrice(items, cmp());
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
    ASSERT_EQ(items[3]->price(), 4 * 29);
}

TEST_F(SortCase, PencilSortByPriceAscClass)
{
    class cmp
    {
    public:
        bool operator()(Pencil *a, Pencil *b)
        {
            return a->price() < b->price();
        }
    };
    cmp lambda;
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, lambda);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
}

TEST_F(SortCase, PencilSortByPriceDeclass)
{
    class cmp
    {
    public:
        bool operator()(Pencil *a, Pencil *b)
        {
            return a->price() > b->price();
        }
    };
    cmp lambda;
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, lambda);
    ASSERT_EQ(items[2]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[0]->price(), 3.1 * 18);
}

bool PencilAscFunc(Pencil *a, Pencil *b)
{
    return a->price() < b->price();
}

TEST_F(SortCase, PencilSortByPriceAscFunc)
{
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, PencilAscFunc);
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
}

bool PencilDecFunc(Pencil *a, Pencil *b)
{
    return a->price() > b->price();
}

TEST_F(SortCase, PencilSortByPriceDecFunc)
{
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, PencilDecFunc);
    ASSERT_EQ(items[2]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[0]->price(), 3.1 * 18);
}

TEST_F(SortCase, PencilSortByPriceAscLambda)
{
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, [](Pencil *a, Pencil *b)
                { return a->price() < b->price(); });
    ASSERT_EQ(items[0]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[2]->price(), 3.1 * 18);
}

TEST_F(SortCase, PencilSortByPriceDecLambda)
{
    vector<Pencil *> items = {&p1, &p2, &p3};
    sortByPrice(items, [](Pencil *a, Pencil *b)
                { return a->price() > b->price(); });
    ASSERT_EQ(items[2]->price(), 2.0 * 15);
    ASSERT_EQ(items[1]->price(), 2.6 * 12);
    ASSERT_EQ(items[0]->price(), 3.1 * 18);
}

TEST_F(SortCase, EraserSortByPriceAscClass)
{
    class cmp
    {
    public:
        bool operator()(Eraser *a, Eraser *b)
        {
            return a->price() < b->price();
        }
    };
    cmp lambda;
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, lambda);
    ASSERT_EQ(items[0]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[2]->price(), 4 * 29);
}

TEST_F(SortCase, EraserSortByPriceDeclass)
{
    class cmp
    {
    public:
        bool operator()(Eraser *a1, Eraser *a2)
        {
            return a1->price() > a2->price();
        }
    };
    // cmp lambda;
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, cmp());
    ASSERT_EQ(items[2]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}

bool EraserAscFunc(Eraser *a, Eraser *b)
{
    return a->price() < b->price();
}

TEST_F(SortCase, EraserSortByPriceAscFunc)
{
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, EraserAscFunc);
    ASSERT_EQ(items[0]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[2]->price(), 4 * 29);
}

bool EraserDecFunc(Eraser *a, Eraser *b)
{
    return a->price() > b->price();
}

TEST_F(SortCase, EraserSortByPriceDecFunc)
{
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, EraserDecFunc);
    ASSERT_EQ(items[2]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}

TEST_F(SortCase, EraserSortByPriceAscLambda)
{
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, [](Eraser *a, Eraser *b)
                { return a->price() < b->price(); });
    ASSERT_EQ(items[0]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[2]->price(), 4 * 29);
}

TEST_F(SortCase, Erase3rSortByPriceDecLambda)
{
    vector<Eraser *> items = {&e1, &e2, &e3};
    sortByPrice(items, [](Eraser *a, Eraser *b)
                { return a->price() > b->price(); });
    ASSERT_EQ(items[2]->price(), 29);
    ASSERT_EQ(items[1]->price(), 2 * 29);
    ASSERT_EQ(items[0]->price(), 4 * 29);
}
