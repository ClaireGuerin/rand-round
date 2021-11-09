cmake_minimum_required(VERSION 3.0.0)
project(randround VERSION 0.1.0)

set(CXX_STANDARD 20)

add_executable(randround main.cpp src/Round.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
