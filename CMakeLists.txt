cmake_minimum_required(VERSION 3.18.1)

project(Calculator VERSION 1.0.0)

include_directories(src include test)


set(MAIN_SRC 
    src/LogicHelperClass.cpp
    src/LogicClass.cpp
    src/CalculatorHelperClass.cpp
    src/CalculatorClass.cpp
    src/main.cpp
    )

set(INCLUDES
    include/Include.hpp
    include/LogicHelperClass.hpp
    include/LogicClass.hpp
    include/CalculatorHelperClass.hpp
    include/CalculatorClass.hpp
    )

##WHEN TESTS PASS
#add_executable(calc ${MAIN_SRC} ${INCLUDES})

enable_testing()

set(TEST_SRC
    src/LogicHelperClass.cpp
    src/LogicClass.cpp
    src/CalculatorHelperClass.cpp
    src/CalculatorClass.cpp
#    test/LogicHelperClassTest.cpp
#    test/LogicClassTest.cpp
#    test/CalculatorHelperTest.cpp
     test/CalculatorClassTest.cpp
    )

add_executable(testCalc ${TEST_SRC} ${INCLUDES})
target_link_libraries(testCalc gtest gtest_main pthread)
