project(ex2 VERSION 0.1.0)

add_executable(${PROJECT_NAME}
    main.cpp
)

add_test(NAME ${PROJECT_NAME}_empty_run
    COMMAND ${PROJECT_NAME}
)

add_test(NAME ${PROJECT_NAME}_1int_param
    COMMAND ${PROJECT_NAME} 12345
)

add_test(NAME ${PROJECT_NAME}_2int_param
    COMMAND ${PROJECT_NAME} 12345 6789
)

add_test(NAME ${PROJECT_NAME}_1flt_param
    COMMAND ${PROJECT_NAME} 12.345
)

add_test(NAME ${PROJECT_NAME}_2flt_param
    COMMAND ${PROJECT_NAME} 12.345 67.890
)