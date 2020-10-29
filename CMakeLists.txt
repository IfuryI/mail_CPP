cmake_minimum_required(VERSION 3.17)
project(main_cpp)

set(CMAKE_C_STANDARD 99)

add_executable(main_cpp main.c src/proccesing.c include/proccesing.h src/consistently.c include/consistently.h src/parallel.c include/parallel.h include/error_codes.h include/type_definitions.h src/utils.c include/utils.h)
target_link_libraries(main_cpp pthread)
