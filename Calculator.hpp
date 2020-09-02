//includes
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <vector>


enum class Operators : char
{
    PLUS = '+',   
    MINUS = '-',
    TIMES = '*',
    DIVIDED_BY = '/',
};

enum class Numbers : char
{
    ZERO = '0',
    ONE = '1',
    TWO = '2',
    THREE = '3',
    FOUR = '4',
    FIVE = '5',
    SIX = '6',
    SEVEN = '7',
    EIGHT = '8',
    NINE = '9'
};

enum class Parenthesis : char
{
    OPEN = '(',
    CLOSE = ')'
};


class Calculator
{
    //methods
    public:  
        Calculator();
        ~Calculator() = default;

        std::string getResult();
        void setInput(const std::string input);

    private:
        std::map<unsigned int, std::pair<unsigned int,unsigned int>> setOrder(std::string input);
        double getNumbers(std::string substring);
        void getOperators(std::string substring);
        void parse();
        void calculate();

        

    //members
        std::string input;
        std::string result;

        const std::vector<Operators> operators = {Operators::PLUS,
                                                  Operators::MINUS,
                                                  Operators::TIMES,
                                                  Operators::DIVIDED_BY};

        const std::vector<Numbers> numbers = {Numbers::ZERO,
                                              Numbers::ONE,
                                              Numbers::TWO,
                                              Numbers::THREE,
                                              Numbers::FOUR,
                                              Numbers::FIVE,
                                              Numbers::SIX,
                                              Numbers::SEVEN,
                                              Numbers::EIGHT,
                                              Numbers::NINE};
};