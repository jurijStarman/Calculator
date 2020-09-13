//includes
#ifndef INC_H
#define INC_H
#include "Include.hpp"
#endif

#include "LogicClass.hpp"

#include "CalculatorHelperClass.hpp"

class CalculatorClass
{
    //methods
    public:  
        CalculatorClass();
        ~CalculatorClass() = default;

        std::string getResult();
        void setInput(const std::string input);
        void compute();

    private:
        void solve(std::string input, unsigned int first, unsigned int second, std::vector<LocationStruct>& resultVector);

        LogicClass logicFuncClass;
        CalculatorHelperClass helperFunctClass;
        

    //members
        std::string input;
        std::string result;

        const std::vector<OperatorsEnum> operators = {OperatorsEnum::PLUS,
                                                      OperatorsEnum::MINUS,
                                                      OperatorsEnum::TIMES,
                                                      OperatorsEnum::DIVIDED_BY};

        const std::vector<NumbersEnum> numbers = {NumbersEnum::ZERO,
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
};