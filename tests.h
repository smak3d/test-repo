#include <functional>
#include <vector>
#include <iostream>

#include "candle.h"

static std::vector<std::function<bool()>> tests;

//body_contains
bool testBodyContainsGreen();
bool testBodyContainsGreenBoundary();
bool testBodyContainsRed();

//contains
bool testContainsInsideBounds();
bool testContainsOnBounds();
bool testContainsOutsideBounds();

//full_size
bool testFullSizePositive();
bool testFullSizeNegative();
bool testFullSizeZero();

//body_size
bool testBodySizeGreen();
bool testBodySizeRed();
bool testBodySizeZero();

//is_red
bool testIsRedTrue();
bool testIsRedFalse();
bool testIsRedZeroBody();

//is_green
bool testIsGreenTrue();
bool testIsGreenFalse();
bool testIsGreenZeroBody();

//
void initTests();

int launchTests();
