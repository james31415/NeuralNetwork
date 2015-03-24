cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project("Neural Network")

enable_testing()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings} -std=c++11"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(BOOST_ROOT "../boost_1_57_0"
        CACHE PATH "Location of the Boost directory")
endif()

include_directories(SYSTEM ${BOOST_ROOT})

add_executable(main main.cpp NeuralNetwork.cpp)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")

