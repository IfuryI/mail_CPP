cmake_minimum_required(VERSION 3.17)
project(main_cpp)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "--coverage -pthread")

FILE(GLOB SOURCES src/*.c)
include_directories("include/*.h")

# Статическая библиотека
add_library(${PROJECT_NAME}_static_lib STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_static_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Динамическая библиотека
add_library(${PROJECT_NAME}_shared_lib SHARED ${SOURCES} ${HEADERS})
add_library(${PROJECT_NAME}_module MODULE ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_shared_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC main_cpp_shared_lib)