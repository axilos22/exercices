project(common VERSION 0.1.0)

add_library(${PROJECT_NAME}
    abstractTypes.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(test)