project(geometry_tester)

add_executable(${PROJECT_NAME}
    geometry_tester.cpp
)

target_link_libraries(${PROJECT_NAME} position)

add_test(OneD_int_create ${PROJECT_NAME} 1)
add_test(OneD_int_distance ${PROJECT_NAME} 2)
