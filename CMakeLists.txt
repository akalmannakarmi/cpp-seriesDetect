cmake_minimum_required(VERSION 3.27.1)
project(runner)
add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/output/libSequence.dll")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output"
)