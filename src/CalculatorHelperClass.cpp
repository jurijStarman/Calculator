#include "../include/CalculatorHelperClass.hpp"
///
//Description:
//  This function returns a newly formed input string, in which the solved expressions
//  have been replaced by their results.
///
std::string CalculatorHelperClass::replaceSubstrings(std::vector<LocationStruct> resultVector, std::string input)
{
    unsigned int size;
    unsigned int correction = 0;
    auto isSmaller = [](LocationStruct i, LocationStruct j){
        return (i.first < j.first);
    };

    if(resultVector.size() > 1){
        std::sort(resultVector.begin(), resultVector.end(), isSmaller);    
    }

    for(auto iter = resultVector.begin(); iter != resultVector.end()-1; iter++){

        size = iter->second - iter->first + 1;     

        input.replace(iter->first, size, iter->result);

        correction = correction + (iter->result.size() - size);

        (iter+1)->first += correction;
        (iter+1)->second += correction; 
    } 

    size = (resultVector.end()-1)->second - (resultVector.end()-1)->first + 1;
    input.replace((resultVector.end()-1)->first, size, (resultVector.end()-1)->result);

    return input;
}


///
//TODO:
//Add description.
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