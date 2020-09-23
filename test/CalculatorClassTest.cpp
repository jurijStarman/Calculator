#include <gtest/gtest.h>
#include "../include/Include.hpp"
#include "../include/CalculatorClass.hpp"
///
//All functions of the CalculatorClass will 
//be tested indirectly within the compute
//function tests.
///
TEST(CalculatorClassTest, compute)
{
    CalculatorClass toTest;

    toTest.setInput("1+1");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "2.000000");

    toTest.setInput("1+1/3*4+77--3.4576+7---3*4");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "77.790933");

    toTest.setInput("(1+1)+1");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "3.000000");

    toTest.setInput("(1+1)+(1+1)+1");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "5.000000");

    toTest.setInput("(1+(1+1)+1)");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "4.000000");

    toTest.setInput("(1+(-1)+1)");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "1.000000");

    toTest.setInput("(1+(1)+1)");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "3.000000");

    toTest.setInput("(1+(((-----------1)))+1)");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "1.000000");
    
    toTest.setInput("34.567--(4.6*(7+0.09/3---5)+4-3*(9.7/4)+(-4))+(3.5*6)");
    toTest.compute();
    EXPECT_EQ(toTest.getResult(), "57.630000");
}