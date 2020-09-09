#include <gtest/gtest.h>
#include "../include/Calculator.hpp"

/*
Functions to test:

Simple PRIVATE functions that do not need to be tested in isolation:
-   bool isNumber(char toCompare);
-   Operators charToOperator(char c);
-   minusIsOperator(const std::string substring, const std::size_t pos);
-   replaceSubstrings(std::vector<Location>& resultVector);
-   unsigned int getMaxKey(locationMultimap& inputOrder);

PRIVATE functions that need to be tested in isolation:
-   setOrder(std::string input);
-   getExpression(const std::string substring);
-   std::string calculate(Expression expression);
-   void solve(std::string input, unsigned int first, unsigned int second, std::vector<Location>& resultVector); 

PUBLIC functions:
-   std::string getResult();
-   void setInput(const std::string input);
-   void parse();
*/

class UnitTestClass
{
    public:
        void runTests();
};

int main(){

    return 0;
}
