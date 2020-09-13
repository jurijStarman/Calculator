#ifndef INC_H
#define INC_H
#include "Include.hpp"
#endif

class CalculatorHelperClass
{
    public:
        CalculatorHelperClass() = default;
        ~CalculatorHelperClass() = default;

        std::string replaceSubstrings(std::vector<LocationStruct>& resultVector);
        unsigned int getMaxKey(locationMultimapType& inputOrder);

};