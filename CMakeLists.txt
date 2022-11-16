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

add_executable(week4_ex1 week04/ex1.c)
add_executable(week4_ex2 week04/ex2.c)
add_executable(week4_ex3 week04/ex3.c)
add_executable(week4_ex4 week04/ex4.c)

add_executable(week5_ex1_1 week05/channel.c)
add_executable(week5_ex1_2 week05/publisher.c)
add_executable(week5_ex1_3 week05/subscriber.c)
add_executable(week5_ex2 week05/ex2.c)
add_executable(week5_ex3 week05/ex3.c)
add_executable(week5_ex4 week05/ex4.c)

add_executable(week6_ex1 week06/ex1.c)
add_executable(week6_ex2 week06/ex2.c)
add_executable(week6_ex3 week06/ex3.c)

add_executable(week7_ex2 week07/ex2.c)
add_executable(week7_ex3 week07/ex3.c)
add_executable(week7_ex4 week07/ex4.c)
add_executable(week7_ex5 week07/ex5.c)

add_executable(week8_ex2 week08/ex2.c)
add_executable(week8_ex4 week08/ex4.c)

add_executable(week9_ex1 week09/ex1.c)

add_executable(week10_ex4 week10/ex4.c)

add_executable(week11_ex2 week11/ex2.c)