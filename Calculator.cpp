#include "Calculator.hpp"

Calculator::Calculator(){}

std::string Calculator::getResult(){return result;}

void Calculator::setInput(const std::string& input){this->input = input;}



std::string Calculator::setOrder(std::string parsedInput){

    std::size_t closingP = parsedInput.find_first_of(')');
    
    if(closingP != std::string::npos){
        std::size_t openingP = parsedInput.find_last_of('(', closingP);
        return parsedInput.substr(openingP, closingP);
    }
    else{//no parenthesis
        return parsedInput;
    }
}

//numbers are between operators
double Calculator::getNumber(std::string substring){
    bool isNegative = false;

    auto toggle = [](bool toToggle){toToggle = !toToggle;};
    auto getOperators = [this](){ std::string toReturn;
                             for(auto c : this->operators){toReturn.push_back(c);} 
                             return toReturn;};

    std::string operatorsString = getOperators();

    std::size_t currentOp = substring.find_first_of(operatorsString);
    std::size_t previousOp = 0;

    //TODO preveri od kje dela .substr()
    if(currentOp == 0){
        toggle(isNegative);
        previousOp = currentOp+1;
        currentOp = substring.find_first_of(operatorsString, previousOp);
    }

    while(currentOp != std::string::npos){   
        if(substring[currentOp] == '-'){
            //if the character to the left of the '-' is a number that means the '-' is an operator.
            if(std::find(this->numbers.begin(),this->numbers.end(),substring[currentOp-1]) != this->numbers.end()){
                
                double number = std::stod(substring.substr(previousOp,currentOp));
                
                return (isNegative) ? ((-1)*number) : number;
            }
            else{
                toggle(isNegative);
            }
            previousOp = currentOp;
            currentOp = substring.find_first_of(operatorsString, previousOp);
        }
    }

    //if there is no operator
    return std::stod(substring);
}

void Calculator::getOperator(std::string substring){

}


void Calculator::parse(){
    Expression expression;

    std::string parsedInput = this->input;
    std::string toEvaluate;

    toEvaluate = setOrder(parsedInput);
    getNumber(toEvaluate);
    getOperator(toEvaluate);

    //this->calculations.emplace_back(setOrder(parsedInput));


    
}

void Calculator::calculate(){

}

