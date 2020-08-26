//incluudes
#include <algorithm>
#include <string>
#include <vector>

struct Expression
{
    std::vector<double> numbers;
    std::vector<char> operators;
};

enum class Operators : char
{
    PLUS = '+',   
    MINUS = '-',
    TIMES = '*',
    DIVIDED_BY = '/',
    Last
};


class Calculator
{
    //methods
    public:  
        Calculator();
        ~Calculator() = default;

        std::string getResult();
        void setInput(const std::string& input);

    private:
        std::string setOrder(std::string input);
        double getNumber(std::string substring);
        void getOperator(std::string substring);
        void parse();
        void calculate();

        

    //members
        std::vector<Expression> calculations;
        std::string input;
        std::string result;

        const std::vector<char> operators = {'+','-','*','/'};
        const std::vector<int> numbers = {'1','2','3','4','5','6','7','8','9','0'};
};