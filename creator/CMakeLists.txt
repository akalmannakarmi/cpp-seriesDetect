cmake_minimum_required(VERSION 3.10)

project(Sequences)


add_library(Arthmetic SHARED arthmetic.cpp)
add_library(Fibonacci SHARED fibonacci.cpp)
add_library(Geometric SHARED geometric.cpp)
add_library(Harmonic SHARED harmonic.cpp)
add_library(Power SHARED power.cpp)
add_library(Prime SHARED prime.cpp)
add_library(Quadratic SHARED quadratic.cpp)
add_library(Triangular SHARED triangular.cpp)

set(BUILD_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(DESIRED_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/../../output/sequences)

foreach(lib Arthmetic Fibonacci Geometric Harmonic Power Prime Quadratic Triangular)
    target_link_libraries(${lib} ${DESIRED_OUTPUT_DIR}/../libSequence.dll)
endforeach()

add_custom_target(CopyDLL ALL)
foreach(lib Arthmetic Fibonacci Geometric Harmonic Power Prime Quadratic Triangular)
    add_custom_command(TARGET CopyDLL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${BUILD_OUTPUT_DIR}/$<TARGET_FILE_NAME:${lib}>
            ${DESIRED_OUTPUT_DIR}/$<TARGET_FILE_NAME:${lib}>
        DEPENDS ${lib}
    )
endforeach()