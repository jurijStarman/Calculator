#include "Calculator_test.cpp"

char displayClassChoices()
{
    int counter = 0;
    char choice;

    std::cout << "Choose what to test: " << std::endl;
    std::cout << std::endl;
    
    for(auto elem : testDetailsGlobal){
        std::cout << counter << ". " << elem.first << std::endl;
        counter++;
    }

    std::cin >> choice;

    return choice;

}

bool testClass(char choice)
{
    LogicHelperUnitTestClass LHtestClass;
    LogicUnitTestClass LtestClass;
    CalculatorHelperUnitTestClass CHtestClass;
    CalculatorUnitTestClass CtestClass;

    switch(choice){
        case '0':
            LHtestClass.runLogicHelperClassTests();
        return false;
        case '1':
            LtestClass.runLogicClassTests();
        return false;
        case '2':
            CHtestClass.runCalculatorHelperClassTests();
        return false;
        case '3':
            CtestClass.runCalculatorClassTests();
        return false;
        default:
        return true;
    }
}

char displayFunctionChoices(char choice)
{
    int counter = 0;
    char funcChoice;
    int intChoice = choice - '0';
    detailMapType::iterator DMTIter = testDetailsGlobal.begin();
    std::advance(DMTIter,intChoice);

    std::cout << "Choose what to test: " << std::endl;
    std::cout << std::endl;
    for(auto elem : DMTIter->second){
        std::cout << counter << ". " << elem << std::endl;
        counter++;
    }

    std::cin >> funcChoice;

    return funcChoice;
}

/*
{"LogicHelperClass", {"isNumber", "charToOperator", "minusIsOperator"}},
{"LogicClass", {"setOrder", "getExpression", "calculate"}},
{"CalculatorHelperClass", {"replaceSubstrings", "getMaxKey"}},
{"CalculatorClass", {"getResult", "setInput", "co                                   
*/

bool testFunction(char choice, char functionChoice)
{
    LogicHelperUnitTestClass LHtestClass;
    LogicUnitTestClass LtestClass;
    CalculatorHelperUnitTestClass CHtestClass;
    CalculatorUnitTestClass CtestClass;

    switch(choice){
        case '0':
                switch(functionChoice){
                    case '0':
                        LHtestClass.testIsNumber();
                    return false;
                    case '1':
                        LHtestClass.testCharToOperator();
                    return false;
                    case '2':
                        LHtestClass.testMinusIsOperator();
                    return false;
                    default:
                    return true;
                }
        case '1':
            switch(functionChoice){
                    case '0':
                        LtestClass.testSetOrder();
                    return false;
                    case '1':
                        LtestClass.testGetExpression();
                    return false;
                    case '2':
                        LtestClass.testCalculate();
                    return false;
                    default:
                    return true;
                }
        case '2':
            switch(functionChoice){
                    case '0':
                        CHtestClass.testReplaceSubstrings();
                    return false;
                    case '1':
                        CHtestClass.testGetMaxKey();
                    return false;
                    default:
                    return true;
                }
        case '3':
                switch(functionChoice){
                    case '0':
                        CtestClass.testGetResult();
                    return false;
                    case '1':
                        CtestClass.testSetInput();
                    return false;
                    case '2':
                        CtestClass.testCompute();
                    return false;
                    default:
                    return true;
                }
        default:
        return true;
    }
}

int main(){

    char choice;
    char functionChoice;
    int testNum;
    bool quit = false;
    UnitTestClass UtestClass;


    while(!quit){
        std::cout << "Choose what to test: " << std::endl;
        std::cout << std::endl;
        std::cout << "1. Run all tests." << std::endl;
        std::cout << "2. Test single class." << std::endl;
        std::cout << "3. Test single function." << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Press 'q' to quit..." << std::endl;
        std::cin >> choice;

        switch(choice){
            case '1':
                UtestClass.runAllTests();
            break;
            case '2':
                choice = displayClassChoices();
                quit = testClass(choice);
            break;
            case '3':
                choice = displayClassChoices();
                functionChoice = displayFunctionChoices(choice);
                quit = testFunction(choice, functionChoice);
            break;
            case 'q':
                quit = true;
            break;
            default:
            break;
        }

    }


    return 0;
}
