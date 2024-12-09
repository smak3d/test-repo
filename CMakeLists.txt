cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

# Указываем, что мы будем использовать стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл и указываем исходные файлы
add_executable(${PROJECT_NAME} main.cpp candle.cpp tests.cpp)

# Указываем, что candle.h является заголовочным файлом
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})