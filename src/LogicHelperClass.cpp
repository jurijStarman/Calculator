#include "../include/LogicHelperClass.hpp"

///
//Description:
//  Checks and returns 'true' if a given character is a valid number
//  located in the 'numbers' member vector. 
///
bool LogicHelperClass::isNumber(char toCompare, const std::vector<NumbersEnum> numbers)
{
    for(auto elem : numbers){
        if(static_cast<char>(elem) == toCompare){
            return true;
        }

        return false;
    }
}

///
//Description:
//  Converts a character into an Operator and returns that Operator.
//  WARNING: No default value is specified, because the input character
//  should be a valid when this function is called.
//
//NOTE: EXCEPTION HANDLING SHOULD BE IMPLEMENTED.
///
OperatorsEnum LogicHelperClass::charToOperator(char c)
{
    switch(c){
        case static_cast<char>(OperatorsEnum::PLUS):
            return OperatorsEnum::PLUS;
        case static_cast<char>(OperatorsEnum::MINUS):
            return OperatorsEnum::MINUS;
        case static_cast<char>(OperatorsEnum::TIMES):
            return OperatorsEnum::TIMES;
        case static_cast<char>(OperatorsEnum::DIVIDED_BY):
            return OperatorsEnum::DIVIDED_BY;
    }
}


///
//Description:
//  Checks if a 'minus' is an operator or a sign.
//  List of checked possibilities:
//      - 'minus' is located in the first position -> Sign.
//      - A number is located to the left of the 'minus' -> Operator.
//      - Otherwise -> Sign.
//
//WARNING: No error handling is implemented for possible negative value of 'pos'.
//NOTE: EXCEPTION HANDLING SHOULD BE IMPLEMENTED.
///
bool LogicHelperClass::minusIsOperator(const std::string substring, const std::size_t pos, const std::vector<NumbersEnum> numbers)
{
    if(pos == 0){//minus is the first character so it is a sign
        return false;
    }
    else if(isNumber(substring[pos-1], numbers)){//minus is an operator
        return true;
    }
    else{//minus is a sign
        return false;
    }
}