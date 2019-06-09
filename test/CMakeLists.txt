add_executable(testadt testadt.c)
target_link_libraries(testadt adt)

add_executable(testregistry testregistry.c)
target_link_libraries(testregistry adt registry)
