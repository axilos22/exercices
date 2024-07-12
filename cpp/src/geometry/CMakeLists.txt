project(geometry VERSION 0.1.0)

add_library(position position.cpp)

target_include_directories(position
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(utest)
