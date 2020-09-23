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
//should return an element that is pushed back into a vector in the compute func.
//
///
void CalculatorClass::solve(std::string input, unsigned int first, unsigned int second, std::vector<LocationStruct>* resultVector)
{
    std::mutex mtx;

    mtx.lock();
        std::string substring = input.substr(first+1, second-first-1);
    mtx.unlock();

    ExpressionStruct expression = this->logicFuncClass.getExpression(substring, this->numbers);
    
    std::string result = this->logicFuncClass.calculate(expression);
    
    LocationStruct location(first, second, result);

    mtx.lock();
        (*resultVector).push_back(location);
    mtx.unlock();
}


///
//TODO
//
//set order should be updated when input is changed.
// problem: key values will be changed -> can just pop elements from map and
//          call getMaxKey each time as well.
//
//add explanation
//
///
void CalculatorClass::compute(){

    std::string input = this->input;
    std::vector<LocationStruct> resultVector;

    locationMultimapType inputOrder = this->logicFuncClass.setOrder(input);
    unsigned int currentKey = this->helperFunctClass.getMaxKey(inputOrder);
    unsigned int first = 0;
    unsigned int second = 0;
    std::vector<std::thread> threadVector;

    ExpressionStruct expression;
    std::string result;

    while(!inputOrder.empty()){
        //1.get elements with same key(high to low)
        std::pair<lMMIterType, lMMIterType> sameKeyElem = inputOrder.equal_range(currentKey);
        
        //2.construct threads with different inputs(for each element with same key)
        for(lMMIterType iter = sameKeyElem.first; iter != sameKeyElem.second; ++iter){
            first = iter->second.first;
            second = iter->second.second;

            threadVector.emplace_back(&CalculatorClass::solve, this, input, first, second, &resultVector);
        }
        //3.wait for threads to finish
        //joinas threade ki so ze joinani -- samo if joinable
        for(auto& elem : threadVector){
            if(elem.joinable()){
                elem.join();
            }
        }
        
        //4.repeat for other keys until all of them are covered.
        
        input = this->helperFunctClass.replaceSubstrings(resultVector, input);
        resultVector.clear();
        inputOrder = this->logicFuncClass.setOrder(input);
        currentKey = this->helperFunctClass.getMaxKey(inputOrder);
    }

    
    //5.calculate Expression Without Parenthesis
    expression = this->logicFuncClass.getExpression(input, this->numbers);
    
    if(!expression.numbers.empty() && !expression.operators.empty()){
        result = this->logicFuncClass.calculate(expression);
    }
    else{
        result = input;
    }
    //6.store the result
    this->result = result;
    
}