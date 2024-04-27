#include <gtest/gtest.h>
#include "phone_test.h"
#include "tablet_test.h"
#include "find_test.h"
#include "laptop_test.h"

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
