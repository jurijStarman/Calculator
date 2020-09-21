#include <gtest/gtest.h>
#include "../include/Include.hpp"
#include "../include/CalculatorHelperClass.hpp"

TEST(CalculatorHelperClassTest, replaceSubstrings)
{
    CalculatorHelperClass toTest;
    std::vector<LocationStruct> arg1;
    std::string arg2;

    arg2 = "(1+1)+(1+1)+(1+1)+(1+1)";
    arg1 = {{0,4,"2"},
            {12,16,"2"},
            {6,10,"2"},
            {18,22,"2"}};

    EXPECT_EQ(toTest.replaceSubstrings(arg1, arg2), "2+2+2+2");

    arg2 = "1+1+1+(1+1+1)+1+(1+1)+1+(1+1)";
    arg1 = {{6,12,"3"},
            {16,20,"2"},
            {24,28,"2"}};

    EXPECT_EQ(toTest.replaceSubstrings(arg1, arg2), "1+1+1+3+1+2+1+2");

    arg2 = "1+(1/3)+1+(1+1+1)+1";
    arg1 = {{2,6,"0.333333"},
            {10,16,"3"}};

    EXPECT_EQ(toTest.replaceSubstrings(arg1, arg2), "1+0.333333+1+3+1");
}

TEST(CalculatorHelperClassTest, getMaxKey)
{
    CalculatorHelperClass toTest;
    locationMultimapType arg;

    arg = {{1,{6,7}}};
    EXPECT_EQ(toTest.getMaxKey(arg), 1);

    arg = {{1,{6,7}},{1,{5,4}},{2,{6,7}},{1,{6,7}}};
    EXPECT_EQ(toTest.getMaxKey(arg), 2);

    arg = {{1,{6,7}},{100,{5,4}},{2,{6,7}},{101,{6,7}}};
    EXPECT_EQ(toTest.getMaxKey(arg), 101);
    
}       