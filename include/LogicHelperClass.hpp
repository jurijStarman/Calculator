#ifndef INC_H
#define INC_H
#include "Include.hpp"
#endif


///
//TODO
//add description
///
class LogicHelperClass
{
    public:
        LogicHelperClass() = default;
        ~LogicHelperClass() = default;

        bool isNumber(char toCompare, const std::vector<NumbersEnum> numbers);
        OperatorsEnum charToOperator(char c);
        bool minusIsOperator(const std::string substring, const std::size_t pos, const std::vector<NumbersEnum> numbers);
};