#ifndef LOGC_H
#define LOGC_H

#include "Include.hpp"
#include "LogicHelperClass.hpp"


class LogicClass
{
    public:
        LogicClass() = default;
        ~LogicClass() = default;

        locationMultimapType setOrder(std::string input);
        ExpressionStruct getExpression(const std::string substring, const std::vector<NumbersEnum> numbers);
        std::string calculate(ExpressionStruct expression);       

    private:
        LogicHelperClass helperFunctClass;
};

#endif