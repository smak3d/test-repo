#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

int main()
{
  initTests();
  return launchTests();
}
