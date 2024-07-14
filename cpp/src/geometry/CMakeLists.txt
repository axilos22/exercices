project(geometry VERSION 0.1.0)

add_library(position INTERFACE position.cpp)

target_include_directories(position INTERFACE
	${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(utest)
