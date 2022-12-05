cmake_minimum_required(VERSION 3.24)
project(yandex_console)

set(CMAKE_CXX_STANDARD 14)

add_executable(yandex_console src/yandex_contest.cpp src/leet_code.cpp src/coursera/max_pairwise_product.cpp)
