//includes
#include <algorithm>
#include <map>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
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
    NINE = '9',
    DOT = '.'
};

enum class Parenthesis : char
{
    OPEN = '(',
    CLOSE = ')'
};


struct Expression
{
    std::vector<double> numbers;
    std::vector<Operators> operators;
};

struct Location
{
    Location(unsigned int first, unsigned int second, std::string result){
             this->first = first;
             this->second = second;
             this->result = result;}
    
    ~Location() = default;

    unsigned int first;
    unsigned int second;
    std::string result;
};

using locationMultimap = std::multimap<unsigned int, std::pair<unsigned int,unsigned int>>; 
using lMMIter = locationMultimap::iterator;


class Calculator
{
    //methods
    public:  
        Calculator();
        ~Calculator() = default;

        std::string getResult();
        void setInput(const std::string input);
        void parse();

    private:
        locationMultimap setOrder(std::string input);
        bool isNumber(char toCompare);
        Operators charToOperator(char c);
        bool minusIsOperator(const std::string substring, const std::size_t pos);
        Expression getExpression(const std::string substring);
        std::string calculate(Expression expression);
        std::string replaceSubstrings(std::vector<Location>& resultVector);
        unsigned int getMaxKey(locationMultimap& inputOrder);
        void solve(std::string input, unsigned int first, unsigned int second, std::vector<Location>& resultVector);

        

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
                                              Numbers::NINE,
                                              Numbers::DOT};
};