cmake_minimum_required(VERSION 3.24)
project(yandex_console)

set(CMAKE_CXX_STANDARD 14)

add_executable(yandex_console main.cpp yandex_contest.cpp leet_code.cpp coursera.cpp)
