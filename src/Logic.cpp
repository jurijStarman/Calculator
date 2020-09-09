#include "../include/Logic.hpp"

///
//Description:
//  Takes an input string and returns a map which contains
//  the location of the parenthesis(value) and the level/order(key) in which the expression
//  inbetween the parenthesis should be solved. The higher the number the quicker
//  it should be solved.
//  If the input string does not contain parenthesis, it returns an empty map.
/// 
locationMultimap Logic::setOrder(std::string parsedInput){ 
    
    locationMultimap leveledExpressions;
    std::stack<unsigned int> stack;


    //check for parenthesis
    std::size_t firstP = parsedInput.find_first_of(static_cast<char>(Parenthesis::OPEN));

    if(firstP == std::string::npos){
        return leveledExpressions;
    }

    for(unsigned int i = 0; i < parsedInput.length(); ++i){
        if(parsedInput[i] == static_cast<char>(Parenthesis::OPEN)){
            stack.push(i);
        }
        else if(parsedInput[i] == static_cast<char>(Parenthesis::CLOSE)){
            
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
Expression Logic::getExpression(const std::string substring)
{
    Expression expression;
    bool isNegative = false;
    std::string sNumber;

    auto toggle = [](bool isNegative){ isNegative = !isNegative;};
    auto getNumber = [](bool isNegative, std::string sNumber){
                        double dNumber;
                       (isNegative) ? (dNumber = (-1)*std::stod(sNumber)) : (dNumber = std::stod(sNumber));
                       return dNumber;};

    for(std::size_t i = 0; i < substring.length(); ++i){
        
        char elem = substring[i];

        if(isNumber(elem)){
            sNumber.push_back(elem);
        }
        else if(elem == static_cast<char>(Operators::MINUS)){
            if(minusIsOperator(substring, i)){
                expression.operators.push_back(Operators::MINUS);               
                expression.numbers.push_back(getNumber(isNegative, sNumber));
                sNumber.clear();
                isNegative = false;
            }
            else{
                toggle(isNegative);
            }
        }
        else{
            expression.operators.push_back(charToOperator(elem));
            expression.numbers.push_back(getNumber(isNegative, sNumber));
            sNumber.clear();
            isNegative = false;
        }
    }
}