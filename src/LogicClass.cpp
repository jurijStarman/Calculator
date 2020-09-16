#include "../include/LogicClass.hpp"

///
//Description:
//  Takes an input string and returns a map which contains
//  the location of the parenthesis(value) and the level/order(key) in which the expression
//  inbetween the parenthesis should be solved. The higher the number the quicker
//  it should be solved.
//  If the input string does not contain parenthesis, it returns an empty map.
/// 
locationMultimapType LogicClass::setOrder(std::string parsedInput){ 
    
    locationMultimapType leveledExpressions;
    std::stack<unsigned int> stack;


    //check for parenthesis
    std::size_t firstP = parsedInput.find_first_of(static_cast<char>(ParenthesisEnum::OPEN));

    if(firstP == std::string::npos){
        return leveledExpressions;
    }

    for(unsigned int i = 0; i < parsedInput.length(); ++i){
        if(parsedInput[i] == static_cast<char>(ParenthesisEnum::OPEN)){
            stack.push(i);
        }
        else if(parsedInput[i] == static_cast<char>(ParenthesisEnum::CLOSE)){
            
            unsigned int key = stack.size(); 

            std::pair<unsigned int,unsigned int> parenthesis = std::make_pair(stack.top(),i);
            leveledExpressions.emplace(key, parenthesis);
            
            stack.pop();
        }

    }
}

///
//Description:
//  Returns an 'Expression' consctructed from a substring.
//  The function iterates through the substring and locates numbers and operators.
//  If a character is a number or a dot('.') it pushes it to a number string(sNumber).
//  If a character is an operator it checks if that operator is a 'minus'. If it is it
//  checks if that 'minus' is truly an operator using the 'minusIsOperator' function and
//  if it is it converts the contents of 'sNumber' into a double, checking it's sign and
//  storing it in the 'Expression'. Otherwise the 'minus' is a sign and the function therefore
//  toggles the 'isNegative' flag for this number and continues to the next character.
//  If the character is an operator, which is not a 'minus' it does the same thing as when the
//  'minus' is an operator. 
///
ExpressionStruct LogicClass::getExpression(const std::string substring, const std::vector<NumbersEnum> numbers)
{
    ExpressionStruct expression;
    bool isNegative = false;
    std::string sNumber;

    auto toggle = [](bool& isNegative){ isNegative = !isNegative;};
    auto getNumber = [](bool isNegative, std::string sNumber){
                        double dNumber;
                       (isNegative) ? (dNumber = (-1)*std::stod(sNumber)) : (dNumber = std::stod(sNumber));
                       return dNumber;};

    for(std::size_t i = 0; i < substring.length(); i++){
        
        char elem = substring[i];
        
        if(this->helperFunctClass.isNumber(elem, numbers)){
            sNumber.push_back(elem);
            if(i == substring.length()-1){
                expression.numbers.push_back(getNumber(isNegative, sNumber));
            }
        }
        else if(elem == static_cast<char>(OperatorsEnum::MINUS)){
            if(this->helperFunctClass.minusIsOperator(substring, i, numbers)){
                expression.operators.push_back(OperatorsEnum::MINUS);               
                expression.numbers.push_back(getNumber(isNegative, sNumber));
                sNumber.clear();
                isNegative = false;
            }
            else{
                toggle(isNegative);
             }
        }
        else{
            expression.operators.push_back(this->helperFunctClass.charToOperator(elem));
            expression.numbers.push_back(getNumber(isNegative, sNumber));
            sNumber.clear();
            isNegative = false;
        }
    }

    return expression;
}

///
//TODO 
// Implement priority calculation
//add note in workplan that floats displays
//
//Description:
//  The function iterates through an expression operators vector and calculates
//  the expressions along the way.
//  Its stores the first two values of the numbers array into 'firstNum' and 'secondNum'
//  and the first operator in 'op'. It then calculates the expression that these two numbers
//  and operator form, saving the result into the location of the second number.
//  It continues this operation until it reaches the end of an expression.
///
std::string LogicClass::calculate(ExpressionStruct expression)
{
    double result;
    double firstNum;
    double secondNum;
    OperatorsEnum op;

    for(std::size_t i = 0; i < expression.operators.size(); ++i){
        firstNum = expression.numbers[i];
        secondNum = expression.numbers[i+1];
        op = expression.operators[i];

        switch(op){
        case OperatorsEnum::PLUS:
             result = firstNum + secondNum;
             expression.numbers[i+1] = result;
             break;
        case OperatorsEnum::MINUS:
             result = firstNum - secondNum;
             expression.numbers[i+1] = result;
             break;
        case OperatorsEnum::TIMES:
             result = firstNum * secondNum;
             expression.numbers[i+1] = result;
             break;
        case OperatorsEnum::DIVIDED_BY:
             result = firstNum / secondNum;
             expression.numbers[i+1] = result;
             break;
        }
    }

    return std::to_string(result);
}
