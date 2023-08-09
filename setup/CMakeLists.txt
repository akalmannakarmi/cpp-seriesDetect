cmake_minimum_required(VERSION 3.10)

project(Sequence)

add_library(Sequence SHARED sequence.cpp number.cpp)

set(BUILD_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(DESIRED_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/../../output)

add_custom_target(CopyDLL ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${BUILD_OUTPUT_DIR}/$<TARGET_FILE_NAME:Sequence>
        ${DESIRED_OUTPUT_DIR}/$<TARGET_FILE_NAME:Sequence>
    DEPENDS Sequence
)