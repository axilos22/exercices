project(common_testing VERSION 0.1.0)

add_executable(${PROJECT_NAME}
    testing_cppTypes
)

target_link_libraries(${PROJECT_NAME}
    common
)

add_test(NAME ${PROJECT_NAME}_cppTypes_empty
    COMMAND ${PROJECT_NAME}
)

add_test(NAME ${PROJECT_NAME}_cppTypes_allTypes
    COMMAND ${PROJECT_NAME} 1
)