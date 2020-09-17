#ifndef LOGCT_H
#define LOGCT_H
#include <gtest/gtest.h>
#include "../include/Include.hpp"
#include "../include/LogicClass.hpp"

///
//Helper functions
///

ExpressionStruct fillExpr(std::vector<double> num, std::vector<OperatorsEnum> op)
{
    ExpressionStruct toReturn;
    toReturn.numbers = num;
    toReturn.operators = op;
    
    return toReturn;
};



TEST(LogicClass, setOrder)
{
    LogicClass toTest;
    locationMultimapType toCompare;


    toCompare = {{1,{0,1}},{1,{2,3}},{1,{4,5}},{1,{6,7}}};
    EXPECT_EQ(toTest.setOrder("()()()()"), toCompare);
    toCompare = {{1,{0,3}},{2,{1,2}}};
    EXPECT_EQ(toTest.setOrder("(())"), toCompare);
    toCompare = {{1,{0,5}},{2,{1,2}},{2,{3,4}}};
    EXPECT_EQ(toTest.setOrder("(()())"), toCompare);
    toCompare = {{1,{0,5}},{1,{6,7}},{2,{1,2}},{2,{3,4}}};
    EXPECT_EQ(toTest.setOrder("(()())()"), toCompare);
    toCompare = {{1,{0,7}},{2,{1,6}},{3,{2,5}},{4,{3,4}}};
    EXPECT_EQ(toTest.setOrder("(((())))"), toCompare);
}

TEST(LogicClass, getExpression)
{
    LogicClass toTest;
    ExpressionStruct toCompare;
    std::vector<NumbersEnum> argVec = {NumbersEnum::ZERO,
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

    
    toCompare = fillExpr({1,1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.getExpression("1+1", argVec), toCompare);

    toCompare = fillExpr({1,1,1,1,1},{OperatorsEnum::PLUS,OperatorsEnum::PLUS,OperatorsEnum::PLUS,OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.getExpression("1+1+1+1+1", argVec), toCompare);

    toCompare = fillExpr({1,1,3,2},{OperatorsEnum::PLUS,OperatorsEnum::MINUS,OperatorsEnum::DIVIDED_BY});
    EXPECT_EQ(toTest.getExpression("1+1-3/2", argVec), toCompare);

    toCompare = fillExpr({1,-1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.getExpression("1+-1", argVec), toCompare);
    
    toCompare = fillExpr({1,-1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.getExpression("1+-----1", argVec), toCompare);

    toCompare = fillExpr({1,1},{OperatorsEnum::MINUS});
    EXPECT_EQ(toTest.getExpression("1-----1", argVec), toCompare);

    toCompare = fillExpr({1.11,1.213},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.getExpression("1.11+1.213", argVec), toCompare);

    toCompare = fillExpr({1.11,1.213,6.7,5,2,3.33},{OperatorsEnum::PLUS,OperatorsEnum::MINUS,OperatorsEnum::PLUS,OperatorsEnum::DIVIDED_BY,OperatorsEnum::TIMES});
    EXPECT_EQ(toTest.getExpression("1.11+1.213---6.7+5/2*3.33", argVec), toCompare);
}

///
//TODO
//fix test no. 4 when priority calculation is implemented.
///
TEST(LogicClass, calculate)
{
    LogicClass toTest;
    ExpressionStruct arg;

    arg = fillExpr({1,1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.calculate(arg), "2.000000");

    arg = fillExpr({1,-1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.calculate(arg), "0.000000");

    arg = fillExpr({1,1,1,1,1},{OperatorsEnum::PLUS,OperatorsEnum::PLUS,OperatorsEnum::PLUS,OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.calculate(arg), "5.000000");

    arg = fillExpr({1.11,1.213,6.7,5,2,3.33},{OperatorsEnum::PLUS,OperatorsEnum::MINUS,OperatorsEnum::PLUS,OperatorsEnum::DIVIDED_BY,OperatorsEnum::TIMES});
    EXPECT_EQ(toTest.calculate(arg), "3.948000");

    arg = fillExpr({1.1111111,1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.calculate(arg), "2.111111");

    arg = fillExpr({1.1111116,1},{OperatorsEnum::PLUS});
    EXPECT_EQ(toTest.calculate(arg), "2.111112");

    arg = fillExpr({1,1,4},{OperatorsEnum::PLUS, OperatorsEnum::TIMES});
    EXPECT_EQ(toTest.calculate(arg), "5.000000");

    arg = fillExpr({1,1,4,5.55,7.0026,9},{OperatorsEnum::DIVIDED_BY,OperatorsEnum::TIMES,OperatorsEnum::TIMES,OperatorsEnum::TIMES,OperatorsEnum::DIVIDED_BY});
    EXPECT_EQ(toTest.calculate(arg), "17.273080");

}


#endif