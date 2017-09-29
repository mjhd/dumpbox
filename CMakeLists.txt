cmake_minimum_required(VERSION 3.6)
project(shitbox)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        aa.c
        bb.c
        dd.c
        ee.c
        ff.c
        gg.c
        read_args_short.c)

add_executable(shitbox ${SOURCE_FILES})