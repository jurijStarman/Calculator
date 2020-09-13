#include "Calculator_test.hpp"

///
//class LogicHelperUnitTestClass function definition.
///

void LogicHelperUnitTestClass::testIsNumber(){}
void LogicHelperUnitTestClass::testCharToOperator(){}
void LogicHelperUnitTestClass::testMinusIsOperator(){}

void LogicHelperUnitTestClass::runLogicHelperClassTests()
{
    testIsNumber();
    testCharToOperator();
    testMinusIsOperator();
}

///
//class CalculatorHelperUnitTestClass function definition.
///

void CalculatorHelperUnitTestClass::testReplaceSubstrings(){}
void CalculatorHelperUnitTestClass::testGetMaxKey(){}

void CalculatorHelperUnitTestClass::runCalculatorHelperClassTests()
{
    testReplaceSubstrings();
    testGetMaxKey();
}

///
//class LogicUnitTestClass function definition.
///

void LogicUnitTestClass::testSetOrder(){}
void LogicUnitTestClass::testGetExpression(){}
void LogicUnitTestClass::testCalculate(){}

void LogicUnitTestClass::runLogicClassTests()
{
    testSetOrder();
    testGetExpression();
    testCalculate();
}

///
//class CalculatorUnitTestClass function definition.
///
   
void CalculatorUnitTestClass::testGetResult(){}
void CalculatorUnitTestClass::testSetInput(){}
void CalculatorUnitTestClass::testCompute(){}

void CalculatorUnitTestClass::runCalculatorClassTests()
{
    testGetResult();
    testSetInput();
    testCompute();
}

///
//class UnitTestClass function definition.
///

void UnitTestClass::runAllTests()
{
    this->LHUTC.runLogicHelperClassTests();
    this->LUTC.runLogicClassTests();
    this->CHUTC.runCalculatorHelperClassTests();
    this->CUTC.runCalculatorClassTests();
}
