cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(c-tutorial LANGUAGES C)

include_directories(include)

add_subdirectory(common)
add_subdirectory(test)
add_subdirectory(cpma)

add_executable(main main.c)
target_link_libraries(main adt registry
  -Wl,--whole-archive cpma -Wl,--no-whole-archive)
