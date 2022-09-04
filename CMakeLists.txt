cmake_minimum_required(VERSION 3.0.0)
project(CMakelists.txt VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CMakelists.txt main.c list.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
