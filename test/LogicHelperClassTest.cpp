#include <gtest/gtest.h>
#include "../include/Include.hpp"
#include "../include/LogicHelperClass.hpp"


TEST(LogicHelperClass, isNumber)
{
    LogicHelperClass toTest;

    const std::vector<NumbersEnum> argVec = {NumbersEnum::ZERO,
                                             NumbersEnum::ONE,
                                             NumbersEnum::TWO,
                                             NumbersEnum::THREE,
                                             NumbersEnum::FOUR,
                                             NumbersEnum::FIVE,
                                             NumbersEnum::SIX,
                                             NumbersEnum::SEVEN,
                                             NumbersEnum::EIGHT,
                                             NumbersEnum::NINE,
                                             NumbersEnum::DOT};

    EXPECT_EQ(toTest.isNumber('0', argVec), true);
    EXPECT_EQ(toTest.isNumber('1', argVec), true);
    EXPECT_EQ(toTest.isNumber('2', argVec), true);
    EXPECT_EQ(toTest.isNumber('3', argVec), true);
    EXPECT_EQ(toTest.isNumber('4', argVec), true);
    EXPECT_EQ(toTest.isNumber('5', argVec), true);
    EXPECT_EQ(toTest.isNumber('6', argVec), true);
    EXPECT_EQ(toTest.isNumber('7', argVec), true);
    EXPECT_EQ(toTest.isNumber('8', argVec), true);
    EXPECT_EQ(toTest.isNumber('9', argVec), true);
    EXPECT_EQ(toTest.isNumber('.', argVec), true);

    EXPECT_NE(toTest.isNumber('j', argVec), true);
    EXPECT_NE(toTest.isNumber('&', argVec), true);
}

///
// REWRITE TEST WHEN EXCEPTION HANDLING IS IMPLEMENTED.
///
TEST(LogicHelperClass, charToOperator)
{
    LogicHelperClass toTest;

    EXPECT_EQ(toTest.charToOperator('+'), OperatorsEnum::PLUS);
    EXPECT_EQ(toTest.charToOperator('-'), OperatorsEnum::MINUS);
    EXPECT_EQ(toTest.charToOperator('*'), OperatorsEnum::TIMES);
    EXPECT_EQ(toTest.charToOperator('/'), OperatorsEnum::DIVIDED_BY);

    EXPECT_NE(toTest.charToOperator('+'), OperatorsEnum::MINUS);
    EXPECT_NE(toTest.charToOperator('*'), OperatorsEnum::DIVIDED_BY);

    //ADD FOR OTHER CHARS WHEN EXCEPTION HANDLING IS IMPLEMENTED.
}

TEST(LogicHelperClass, minusIsOperator)
{
    LogicHelperClass toTest;

    const std::vector<NumbersEnum> argVec = {NumbersEnum::ZERO,
                                             NumbersEnum::ONE,
                                             NumbersEnum::TWO,
                                             NumbersEnum::THREE,
                                             NumbersEnum::FOUR,
                                             NumbersEnum::FIVE,
                                             NumbersEnum::SIX,
                                             NumbersEnum::SEVEN,
                                             NumbersEnum::EIGHT,
                                             NumbersEnum::NINE,
                                             NumbersEnum::DOT};
    
    EXPECT_EQ(toTest.minusIsOperator("4+5-3", 3, argVec), true);
    EXPECT_EQ(toTest.minusIsOperator("4+5--3", 3, argVec), true);
    EXPECT_EQ(toTest.minusIsOperator("4+5--3", 4, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 3, argVec), true);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 4, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 5, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 6, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 7, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 8, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 9, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4+5-------3", 10, argVec), false);
    EXPECT_EQ(toTest.minusIsOperator("4-5--3", 1, argVec), true);

}