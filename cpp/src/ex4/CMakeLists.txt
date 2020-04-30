project(ex4 VERSION 0.1.0)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    common
)

add_test(NAME ${PROJECT_NAME}_empty_run
    COMMAND ${PROJECT_NAME}
)

add_test(NAME ${PROJECT_NAME}_1int_param
    COMMAND ${PROJECT_NAME} 12345
)