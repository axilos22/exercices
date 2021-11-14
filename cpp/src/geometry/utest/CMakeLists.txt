project(geometry_tester)

add_executable(${PROJECT_NAME}
    position_tester.cpp
)

target_link_libraries(${PROJECT_NAME} position)

add_test(OneD_int_create ${PROJECT_NAME} 1)
add_test(OneD_int_increase ${PROJECT_NAME} 2)
add_test(OneD_int_decrease ${PROJECT_NAME} 3)
add_test(OneD_int_distance ${PROJECT_NAME} 4)
add_test(OneD_int_absDistance ${PROJECT_NAME} 5)
add_test(OneD_double_distance ${PROJECT_NAME} 6)
