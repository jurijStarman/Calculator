#include "../include/CalculatorHelperClass.hpp"


///
//TODO
//change input parameter when Location name is changed.
//
//Description:
//  This function returns a newly formed input string, in which the solved expressions
//  have been replaced by their results.
///
std::string CalculatorHelperClass::replaceSubstrings(std::vector<LocationStruct>& resultVector)
{
    std::string input;

    for(auto elem : resultVector){

        unsigned int size = elem.second - elem.first;

        input.replace(elem.first, size, elem.result);
    }

    return input;
}


///
//TODO:
//Add explanation.
//Add implementation.
///
unsigned int CalculatorHelperClass::getMaxKey(locationMultimapType& inputOrder)
{
    unsigned int maxKey = 0;

    for(auto elem : inputOrder){
        if(elem.first > maxKey){
            maxKey = elem.first;
        }
    }

    return maxKey;
}