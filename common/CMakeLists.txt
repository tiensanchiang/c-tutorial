add_subdirectory(adt)

add_library(registry registry.c)
target_link_libraries(registry adt)
