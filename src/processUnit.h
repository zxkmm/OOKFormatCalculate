//
// Created by zxkmm on 2/6/23.
//

#ifndef OOKFORMATCALCULATE_STRING_UNIT_H
#define OOKFORMATCALCULATE_STRING_UNIT_H

#include <string>
#include <algorithm>
#include <sstream>

class StringUnit {

    std::string makeShortestGrain(
            int numOfGrain);//the number of meaningless "0" in input data，e.g. 4，then make a string with content "1111"

    std::string detectShortestGrainSize(
            std::string dataFromURH);//check how many meaningless "0" in the data from URH, e.g. 1111, then return 4(int). start looking since 10

    std::string decode2262FromURH(std::string dataFromURH);

    std::string makeStringFullOf0withANumber(int numbersOf0);


public:
    std::string replaceMeaningless0WithSpace(std::string i2262URH);

    std::string &replace_mod(std::string &src, const std::string &old_value, const std::string &new_value);

    int getLengthOfVariable(std::string variableName);

    int anyBS2DEC(std::string s, int radix);

    std::string DEC2anyBS(int n, int radix);

    std::string removeNonDesiredCharacters(const std::string& str, const std::string& desiredChars);

    std::string compareTwoStrings(std::string string1, std::string string2);
};


#endif //OOKFORMATCALCULATE_STRING_UNIT_H
