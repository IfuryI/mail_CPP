cmake_minimum_required(VERSION 3.17)
project(unit_tests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage -pthread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -pthread")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

FILE(GLOB SOURCES

FILE(GLOB SOURCES src/*.c *.cpp))
include_directories("include/*.h")

# Статическая библиотека
add_library(${PROJECT_NAME}_static_lib STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_static_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Динамическая библиотека
add_library(${PROJECT_NAME}_shared_lib SHARED ${SOURCES} ${HEADERS})
add_library(${PROJECT_NAME}_module MODULE ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_shared_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
