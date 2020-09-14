#ifndef CALCHC_H
#define CALCHC_H

#include "Include.hpp"


class CalculatorHelperClass
{
    public:
        CalculatorHelperClass() = default;
        ~CalculatorHelperClass() = default;

        std::string replaceSubstrings(std::vector<LocationStruct>& resultVector);
        unsigned int getMaxKey(locationMultimapType& inputOrder);

};

#endif