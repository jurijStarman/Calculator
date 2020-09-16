#ifndef INC_H
#define INC_H

///
//Includes from the standard library
///
#include <algorithm>
#include <iostream>
#include <map>
#include <mutex>
#include <stack>
#include <string>
#include <thread>
#include <vector>


///
//Enum classes
///
enum class OperatorsEnum : char
{
    PLUS = '+',   
    MINUS = '-',
    TIMES = '*',
    DIVIDED_BY = '/',
};

enum class NumbersEnum : char
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

enum class ParenthesisEnum : char
{
    OPEN = '(',
    CLOSE = ')'
};


///
//Structures
///
struct ExpressionStruct
{
    std::vector<double> numbers;
    std::vector<OperatorsEnum> operators;

    bool operator==(const ExpressionStruct& expr) const{ 
        bool equalNum = expr.numbers == numbers;
        bool equalOp = expr.operators == operators;

        if(equalNum && equalOp){
            return true;
        }
        return false;
    }
};

struct LocationStruct
{
    LocationStruct(unsigned int first, unsigned int second, std::string result){
             this->first = first;
             this->second = second;
             this->result = result;}
        
    ~LocationStruct() = default;

    unsigned int first;
    unsigned int second;
    std::string result;
};


///
//using statements
///
using locationMultimapType = std::multimap<unsigned int, std::pair<unsigned int,unsigned int>>; 
using lMMIterType = locationMultimapType::iterator;

#endif