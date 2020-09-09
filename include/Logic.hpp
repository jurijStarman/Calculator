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

class Logic
{
    public:
        Logic() = default;
        ~Logic() = default;

        locationMultimap setOrder(std::string input); //OK
        Expression getExpression(const std::string substring);//OK
        std::string calculate(Expression expression);
        void solve(std::string input, unsigned int first, unsigned int second, std::vector<Location>& resultVector);       
};