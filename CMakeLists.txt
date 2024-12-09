cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

file(GLOB_RECURSE ProjSrcFiles
	"projectFiles/*.h"
	"projectFiles/*.cpp"
)

add_executable(${PROJECT_NAME} ${ProjSrcFiles})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})