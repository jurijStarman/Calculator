#include "Calculator.hpp"

Calculator::Calculator(){}

std::string Calculator::getResult(){

    return result;
}

void Calculator::setInput(const std::string input){
    
    this->input = input;
}


///
//The function takes an input string and returns a vector which contains
//the location of the parenthesis and the level(order) in which the expression
//inbetween the parenthesis should be solved.
//
//
//How to define on which level an expression lies?
//
//Levels are defined by how many parenthesis are inside a 
//pair of parenthesis.
//
//Solution ideas:
//
//the locations of the parenthesis are stored
//in a vector where  a -loc represents a closing p and a loc 
//represents an opening p.
//
//how to pair the right ones together?
//How to level them?
//the number of positive numbers before a negative
//corresponds to their level.
///


//this wont work on (5-4)+(5*5-4/(5+7*(457-8)))
//                  [0 -4 6      13   18  -24 -25 -26]
std::map<unsigned int, std::pair<unsigned int,unsigned int>> Calculator::setOrder(std::string parsedInput){ 
    
    std::map<unsigned int, std::pair<unsigned int,unsigned int>> leveledExpressions;
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
//The function returns the first number
///
double Calculator::getNumbers(std::string substring){

}

void Calculator::getOperators(std::string substring){

}


void Calculator::parse(){

    std::string input = this->input;
    
    std::map<unsigned int, std::pair<unsigned int,unsigned int>> inputOrder = setOrder(input);


    
}

void Calculator::calculate(){

}

