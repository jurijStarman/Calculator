///
//Includes
///
#include <gtest/gtest.h>

#ifndef INC_H
#define INC_H
#include "../include/Include.hpp"
#endif

#include "../include/CalculatorClass.hpp"


///
//Global variable containing all classes and functions to be tested. 
///
using detailMapType = std::map<std::string, std::vector<std::string>>;

detailMapType testDetailsGlobal = {
                                    {"LogicHelperClass", {"isNumber", "charToOperator", "minusIsOperator"}},
                                    {"LogicClass", {"setOrder", "getExpression", "calculate"}},
                                    {"CalculatorHelperClass", {"replaceSubstrings", "getMaxKey"}},
                                    {"CalculatorClass", {"getResult", "setInput", "compute"}}
                                   };


///
//Test classes
///
class LogicHelperUnitTestClass
{
    public:
        LogicHelperUnitTestClass() = default;
        ~LogicHelperUnitTestClass() = default;

        void runLogicHelperClassTests();
        void testIsNumber();
        void testCharToOperator();
        void testMinusIsOperator();
};

class CalculatorHelperUnitTestClass
{
    public:
        CalculatorHelperUnitTestClass()= default;
        ~CalculatorHelperUnitTestClass() = default;

        void runCalculatorHelperClassTests();
        void testReplaceSubstrings();
        void testGetMaxKey();
};

class LogicUnitTestClass
{
    public:
        LogicUnitTestClass()= default;
        ~LogicUnitTestClass() = default;

        void runLogicClassTests();
        void testSetOrder();
        void testGetExpression();
        void testCalculate();
};

class CalculatorUnitTestClass
{
    public:
        CalculatorUnitTestClass()= default;
        ~CalculatorUnitTestClass() = default;

        void runCalculatorClassTests();
        void testGetResult();
        void testSetInput();
        void testCompute();
};


class UnitTestClass
{
    public:
        UnitTestClass() = default;
        ~UnitTestClass() = default;

        void runAllTests();

    private:
        LogicHelperUnitTestClass LHUTC;
        CalculatorHelperUnitTestClass CHUTC;
        LogicUnitTestClass LUTC;
        CalculatorUnitTestClass CUTC;

        
};

