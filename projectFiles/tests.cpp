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
//price inside bounds
bool testContainsInsideBounds()
{
    Candle candle(100.0, 110.0, 90.0, 105.0);
    return candle.contains(105.0) && candle.contains(95.0);
}
//extreme values
bool testContainsOnBounds()
{
    Candle candle(100.0, 110.0, 90.0, 105.0);
    return candle.contains(90.0) && candle.contains(110.0);
}
//price out of bounds
bool testContainsOutsideBounds()
{
    Candle candle{ 100.0, 110.0, 90.0, 105.0 };
    return !candle.contains(120.0) && !candle.contains(85.0);
}

//full_size
//size positive
bool testFullSizePositive()
{
    Candle candle{ 100.0, 110.0, 90.0, 105.0 };
    return candle.full_size() == 20.0;
}
//zero size of candle 
bool testFullSizeNegative()
{
    Candle candle{ 100.0, 100.0, 100.0, 100.0 };
    return candle.full_size() == 0.0;
}
//size negative
bool testFullSizeZero()
{
    Candle candle{ -10.0, -5.0, -15.0, -8.0 };
    return candle.full_size() == 10.0;
}

//body_size
//green size
bool testBodySizeGreen()
{
    Candle candle{ 100.0, 110.0, 90.0, 105.0 };
    return candle.body_size() == 5.0;
}
//red size
bool testBodySizeRed()
{
    Candle candle{ 105.0, 110.0, 90.0, 100.0 };
    return candle.body_size() == 5.0;
}
//zero size
bool testBodySizeZero()
{
    Candle candle{ 100.0, 100.0, 90.0, 100.0 };
    return candle.body_size() == 0.0;
}

//is_red
//red candle
bool testIsRedTrue()
{
    Candle candle{ 105.0, 110.0, 90.0, 100.0 };
    return candle.is_red();
}
//!red candle
bool testIsRedFalse()
{
    Candle candle{ 100.0, 110.0, 90.0, 105.0 };
    return !candle.is_red();
}
//zero body candle
bool testIsRedZeroBody()
{
    Candle candle{ 100.0, 110.0, 90.0, 100.0 };
    return !candle.is_red();
}

//is_green
//green candle
bool testIsGreenTrue()
{
    Candle candle{ 100.0, 110.0, 90.0, 105.0 };
    return candle.is_green();
}
//!green candle
bool testIsGreenFalse()
{
    Candle candle{ 105.0, 110.0, 90.0, 100.0 };
    return !candle.is_green();
}
//zero body candle
bool testIsGreenZeroBody()
{
    Candle candle{ 100.0, 110.0, 90.0, 100.0 };
    return !candle.is_green();
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