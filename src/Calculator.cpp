#include "../include/Calculator.hpp"
///
//TODO
//add explanation.
///
Calculator::Calculator(){}

///
//Description:
//  Returns the contents of the 'result' member,
//  which contains the result of a given calculation.
///
std::string Calculator::getResult(){

    return this->result;
}

///
//Description:
//  Stores/sets the specified value in the 'input' member
//  to the value received from the user.
///
void Calculator::setInput(const std::string input){
    
    this->input = input;
}


///
//Description:
//  Takes an input string and returns a map which contains
//  the location of the parenthesis(value) and the level/order(key) in which the expression
//  inbetween the parenthesis should be solved. The higher the number the quicker
//  it should be solved.
//  If the input string does not contain parenthesis, it returns an empty map.
/// 
locationMultimap Calculator::setOrder(std::string parsedInput){ 
    
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
//  Checks and returns 'true' if a given character is a valid number
//  located in the 'numbers' member vector. 
///
bool Calculator::isNumber(char toCompare)
{
    for(auto elem : this->numbers){
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
Operators Calculator::charToOperator(char c){
    switch(c){
        case static_cast<char>(Operators::PLUS):
            return Operators::PLUS;
        case static_cast<char>(Operators::MINUS):
            return Operators::MINUS;
        case static_cast<char>(Operators::TIMES):
            return Operators::TIMES;
        case static_cast<char>(Operators::DIVIDED_BY):
            return Operators::DIVIDED_BY;
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
bool Calculator::minusIsOperator(const std::string substring, const std::size_t pos){
    if(pos == 0){//minus is the first character so it is a sign
        return false;
    }
    else if(isNumber(substring[pos-1])){//minus is an operator
        return true;
    }
    else{//minus is a sign
        return false;
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
Expression Calculator::getExpression(const std::string substring)
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

///
//Description:
//  The function iterates through an expression operators vector and calculates
//  the expressions along the way.
//  Its stores the first two values of the numbers array into 'firstNum' and 'secondNum'
//  and the first operator in 'op'. It then calculates the expression that these two numbers
//  and operator form, saving the result into the location of the second number.
//  It continues this operation until it reaches the end of an expression.
///
std::string Calculator::calculate(Expression expression)
{
    double result;
    double firstNum;
    double secondNum;
    Operators op;

    for(std::size_t i = 0; i < expression.operators.size(); ++i){
        firstNum = expression.numbers[i];
        secondNum = expression.numbers[i+1];
        op = expression.operators[i];

        switch(op){
        case Operators::PLUS:
             result = firstNum + secondNum;
             expression.numbers[i+1] = result;
             break;
        case Operators::MINUS:
             result = firstNum - secondNum;
             expression.numbers[i+1] = result;
             break;
        case Operators::TIMES:
             result = firstNum * secondNum;
             expression.numbers[i+1] = result;
             break;
        case Operators::DIVIDED_BY:
             result = firstNum / secondNum;
             expression.numbers[i+1] = result;
             break;
        }
    }

    return std::to_string(result);
}

///
//TODO
//change input parameter when Location name is changed.
//
//Description:
//  This function returns a newly formed input string, in which the solved expressions
//  have been replaced by their results.
///
std::string Calculator::replaceSubstrings(std::vector<Location>& resultVector)
{
    std::string input;

    for(auto elem : resultVector){

        unsigned int size = elem.second - elem.first;

        input.replace(elem.first, size, elem.result);
    }

    return input;
}
///
//TODO:
//Add explanation.
//Add implementation.
///
unsigned int Calculator::getMaxKey(locationMultimap& inputOrder){
    unsigned int maxKey = 0;

    for(auto elem : inputOrder){
        if(elem.first > maxKey){
            maxKey = elem.first;
        }
    }

    return maxKey;
}

///
//TODO:
//
//Rename Location location when the struct name is changed.
//Should implement a mutex on the vector.
///
void Calculator::solve(std::string input, unsigned int first, unsigned int second, std::vector<Location>& resultVector)
{
    std::mutex mtx;

    mtx.lock();
        std::string substring = input.substr(first, second);
    mtx.unlock();

    Expression expression = getExpression(substring);
    std::string result = calculate(expression);
    
    Location location(first, second, result);

    mtx.lock();
        resultVector.push_back(location);
    mtx.unlock();

}


///
//TODO
//
//add explanation
//
//Create a mutex for the following data structures.
//  recourses shared by threads:
//  -   input, 
//  -   resultVector!!!
//  -   
///
void Calculator::parse(){

    std::string input = this->input;
    std::vector<Location> resultVector;

    locationMultimap inputOrder = setOrder(input);  
    unsigned int currentKey = getMaxKey(inputOrder);
    unsigned int first;
    unsigned int second;
    std::vector<std::thread> threadVector;

    Expression expression;
    std::string result;

    while((currentKey > 0) && (!inputOrder.empty())){//keys start with '1'.

        //1.get elements with same key(high to low)
        std::pair<lMMIter, lMMIter> sameKeyElem = inputOrder.equal_range(currentKey);
        
        //2.construct threads with different inputs(for each element with same key)
        for(lMMIter iter = sameKeyElem.first; iter != sameKeyElem.second; ++iter){
            first = iter->second.first;
            second = iter->second.second;

            threadVector.emplace_back(solve, input, first, second, resultVector);
        }
        //3.wait for threads to finish
        for(auto& elem : threadVector){
            elem.join();
        }
        
        //4.repeat for other keys until all of them are covered.
        replaceSubstrings(resultVector);
        currentKey--;
    }

    
    //5.calculate Expression Without Parenthesis
    expression = getExpression(input);
    result = calculate(expression);

    //6.store the result
    this->result = result;
    
}


