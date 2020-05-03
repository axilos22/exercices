project(common_testing VERSION 0.1.0)

set(cppTypes "cppTypes_tester")
set(inputParser "inputParser_tester")

add_executable(${cppTypes} cppTypes_tester.cpp)
target_link_libraries(${cppTypes} common)

add_test(NAME ${PROJECT_NAME}_${cppTypes}_empty
    COMMAND ${cppTypes}
)

add_test(NAME ${PROJECT_NAME}_${cppTypes}_allTypes
    COMMAND ${cppTypes} 1
)
# ------------------------------------------------
add_executable(${inputParser} inputParser_tester.cpp)
target_link_libraries(${inputParser} common)

add_test(NAME ${PROJECT_NAME}_${inputParser}_empty
    COMMAND ${inputParser}
)

add_test(NAME ${PROJECT_NAME}_${inputParser}_1int
    COMMAND ${inputParser} 1
)

add_test(NAME ${PROJECT_NAME}_${inputParser}_2int
    COMMAND ${inputParser} 8 9
)