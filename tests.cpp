#include "tests.h"

//body_contains
bool testBodyContainsGreen() {}
bool testBodyContainsGreenBoundary(){}
bool testBodyContainsRed(){}

//contains
bool testContainsInsideBounds(){}
bool testContainsOnBounds(){}
bool testContainsOutsideBounds(){}

//full_size
bool testFullSizePositive(){}
bool testFullSizeNegative(){}
bool testFullSizeZero(){}

//body_size
bool testBodySizeGreen(){}
bool testBodySizeRed(){}
bool testBodySizeZero(){}

//is_red
bool testIsRedTrue(){}
bool testIsRedFalse(){}
bool testIsRedZeroBody(){}

//is_green
bool testIsGreenTrue(){}
bool testIsGreenFalse(){}
bool testIsGreenZeroBody(){}

//

void initTests()
{
     tests = {
        testBodyContainsGreen,
        testBodyContainsGreenBoundary,
        testBodyContainsRed,
        testContainsInsideBounds,
        testContainsOnBounds,
        testContainsOutsideBounds,
        testFullSizePositive,
        testFullSizeNegative,
        testFullSizeZero,
        testBodySizeGreen,
        testBodySizeRed,
        testBodySizeZero,
        testIsRedTrue,
        testIsRedFalse,
        testIsRedZeroBody,
        testIsGreenTrue,
        testIsGreenFalse,
        testIsGreenZeroBody
    };

    auto addTests = [&]() {
        for (const auto& testFunc : tests)
        {
            tests.push_back(testFunc);
        }
    };

    addTests();
}

int launchTests()
{
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
    {
        std::cout << "test #" << (total + 1);
        if (test())
        {
            passed += 1;
            std::cout << " passed\n";
        }
        else
        {
            std::cout << " failed\n";
        }
        total += 1;
    }

    std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

    //0 = success
    return total - passed;
}