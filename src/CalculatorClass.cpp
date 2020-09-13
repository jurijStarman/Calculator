/*
TODO
add priority solving for +,-,*,/ !!!!
*/
#include "../include/CalculatorClass.hpp"


///
//TODO
//add explanation.
///
CalculatorClass::CalculatorClass(){}

///
//Description:
//  Returns the contents of the 'result' member,
//  which contains the result of a given calculation.
///
std::string CalculatorClass::getResult(){

    return this->result;
}

///
//Description:
//  Stores/sets the specified value in the 'input' member
//  to the value received from the user.
///
void CalculatorClass::setInput(const std::string input){
    
    this->input = input;
}


///
//TODO:
//
//Rename Location location when the struct name is changed.
//Should implement a mutex on the vector.
///
void CalculatorClass::solve(std::string input, unsigned int first, unsigned int second, std::vector<LocationStruct>& resultVector)
{
    std::mutex mtx;

    mtx.lock();
        std::string substring = input.substr(first, second);
    mtx.unlock();

    ExpressionStruct expression = this->logicFuncClass.getExpression(substring, this->numbers);
    std::string result = this->logicFuncClass.calculate(expression);
    
    LocationStruct location(first, second, result);

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
void CalculatorClass::compute(){

    std::string input = this->input;
    std::vector<LocationStruct> resultVector;

    locationMultimapType inputOrder = this->logicFuncClass.setOrder(input);
    unsigned int currentKey = this->helperFunctClass.getMaxKey(inputOrder);
    unsigned int first;
    unsigned int second;
    std::vector<std::thread> threadVector;

    ExpressionStruct expression;
    std::string result;

    while((currentKey > 0) && (!inputOrder.empty())){//keys start with '1'.

        //1.get elements with same key(high to low)
        std::pair<lMMIterType, lMMIterType> sameKeyElem = inputOrder.equal_range(currentKey);
        
        //2.construct threads with different inputs(for each element with same key)
        for(lMMIterType iter = sameKeyElem.first; iter != sameKeyElem.second; ++iter){
            first = iter->second.first;
            second = iter->second.second;

            threadVector.emplace_back(solve, input, first, second, resultVector);
        }
        //3.wait for threads to finish
        for(auto& elem : threadVector){
            elem.join();
        }
        
        //4.repeat for other keys until all of them are covered.
        this->helperFunctClass.replaceSubstrings(resultVector);
        currentKey--;
    }

    
    //5.calculate Expression Without Parenthesis
    expression = this->logicFuncClass.getExpression(input, this->numbers);
    result = this->logicFuncClass.calculate(expression);

    //6.store the result
    this->result = result;
    
}


