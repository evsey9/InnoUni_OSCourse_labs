cmake_minimum_required(VERSION 3.23)
project(InnoUni_OSCourse_labs C)

set(CMAKE_C_STANDARD 99)

add_executable(week1_ex4 week01/main.c)

add_executable(week2_ex1 week02/ex1.c)
add_executable(week2_ex2 week02/ex2.c)
add_executable(week2_ex3 week02/ex3.c)
add_executable(week2_ex4 week02/ex4.c)
add_executable(week2_ex5 week02/ex5.c)

add_executable(week3_ex1 week03/ex1.c)
add_executable(week3_ex2 week03/ex2.c)
target_link_libraries(week3_ex2 m)
add_executable(week3_ex3 week03/ex3.c)
add_executable(week3_ex4 week03/ex4.c)
