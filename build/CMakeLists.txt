cmake_minimum_required(VERSION 3.7)
project(ctl)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES pqueue.h templates.h pqueue_test.c main.c pqueue_test.h vector.h)
add_executable(ctl ${SOURCE_FILES})