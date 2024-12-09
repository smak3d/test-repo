#include "tests.h"

static std::vector<std::function<bool()>> tests;

//body_contains
//price in green candle body
bool testBodyContainsGreen()
{
    Candle candle(100.0, 110.0, 90.0, 105.0);
    return candle.body_contains(102.0);
}
//price meanings in bouds of candle
bool testBodyContainBounds()
{
    Candle candle(100.0, 110.0, 90.0, 105.0);
    return candle.body_contains(100.0) && candle.body_contains(105);
}
//price in red candle body
bool testBodyContainsRed()
{
    Candle candle(105.0, 110.0, 90.0, 100.0);
    return candle.body_contains(102.0);
}

//contains
bool testContainsInsideBounds()
{
    Candle candle(100.0, 110.0, 90.0, 105.0);
    return candle.contains(90.0) && candle.contains(95.0);
}
bool testContainsOnBounds()
{
    return false;
}
bool testContainsOutsideBounds()
{
    return false;
}

//full_size
bool testFullSizePositive()
{
    return false;
}
bool testFullSizeNegative()
{
    return false;
}
bool testFullSizeZero()
{
    return false;
}

//body_size
bool testBodySizeGreen()
{
    return false;
}
bool testBodySizeRed()
{
    return false;
}
bool testBodySizeZero()
{
    return false;
}

//is_red
bool testIsRedTrue()
{
    return false;
}
bool testIsRedFalse()
{
    return false;
}
bool testIsRedZeroBody()
{
    return false;
}

//is_green
bool testIsGreenTrue()
{
    return false;
}
bool testIsGreenFalse()
{
    return false;
}
bool testIsGreenZeroBody()
{
    return false;
}

//

void initTests()
{
    std::vector<std::function<bool()>> testFunctions = {
       testBodyContainsGreen,
       testBodyContainBounds,
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
        for (const auto& testFunc : testFunctions)
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