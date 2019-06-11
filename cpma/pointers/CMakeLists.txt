add_executable(max_min max_min.c)
add_executable(project1 project1.c)
add_executable(project2 project2.c)
add_executable(project3 project3.c)
add_executable(project4 project4.c)
add_executable(list_test list_test.c)
set_property(TARGET max_min PROPERTY C_STANDARD 90)

target_link_libraries(list_test adt)
