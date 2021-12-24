project(batman VERSION 0.1.0)

add_executable(${PROJECT_NAME}
    main.cpp
)

add_test(NAME ${PROJECT_NAME}_empty_run
    COMMAND ${PROJECT_NAME}
)

add_test(NAME ${PROJECT_NAME}_nb_param
    COMMAND ${PROJECT_NAME} 12345
)