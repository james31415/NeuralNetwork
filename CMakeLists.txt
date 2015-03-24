cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

project("Neural Network")

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

find_package(Boost 1.57.0 REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})

add_executable(main main.cpp NeuralNetwork.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 11)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")

