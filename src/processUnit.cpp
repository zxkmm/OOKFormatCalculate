//
// Created by zxkmm.
//

#include "processUnit.h"


int StringUnit::anyBS2DEC(std::string s, int radix) {    //Any base to DEC. s for incoming string, radix for it's BS
    unsigned int ans = 0;
    for (char t: s) {
        if (t >= '0' && t <= '9') ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}

std::string
StringUnit::DEC2anyBS(int n, int radix) {    //DEC to any base. n for incoming numbers(int)，radix for it's BS

    std::string ans = "";
    do {
        unsigned int t = n % radix;
        if (t >= 0 && t <= 9) ans += t + '0';
        else ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);    //prevent-0-exception
    reverse(ans.begin(), ans.end());
    return ans;
}

std::string &StringUnit::replace_mod(std::string &src, const std::string &old_value, const std::string &new_value) {
    // Anti-loop
    for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length()) {
        if ((pos = src.find(old_value, pos)) != std::string::npos) {
            src.replace(pos, old_value.length(), new_value);
        } else break;
    }
    return src;
}

std::string StringUnit::makeShortestGrain(
        int numOfGrain) {//the number of meaningless "0" in input data，e.g. 4，then make a string with content "1111"
    std::string stringGrain = "1";
    for (; numOfGrain > 1; numOfGrain--) {
        //make grain string, e.g. when grainNum=4 ,then make stringGrain = "1111".
        stringGrain = stringGrain + "1";
    }
    //    string stringGrain;
    //    stringGrain = to_string(stringGrainInInt);
    return stringGrain;
}//TODO DEV

std::string StringUnit::detectShortestGrainSize(std::string dataFromURH) {
    //check how many meaningless "0" in the data from URH, e.g. 1111, then return 4(int). start looking since 10
    //查看来自URH的数据里面高电平的粒度是什么，例如是不是1111，从10个1开始找
    unsigned int tes1t;
    for (tes1t = 10; tes1t > 0; tes1t--) {

        if (dataFromURH.find(StringUnit::makeShortestGrain(tes1t)) != std::string::npos) {
//            cout << makeShortestGrain(tes1t) << endl; //DBG
            //如果找到
            //If found
            break;

            //返回高电平信号位的在URH显示的1的个数 TODO
            //return number of meaningless "1", since clock doesn't matter for this tool.
        }
    }

    return makeShortestGrain(tes1t);
}//TODO DEV

std::string StringUnit::decode2262FromURH(std::string dataFromURH) {
    std::string result3Bit2262Code;
    //TODO


    return result3Bit2262Code;
} //TODO DEV

std::string StringUnit::makeStringFullOf0withANumber(int numbersOf0) {
    std::string result = "";
    std::string zero = "0";
    for (; numbersOf0 > 0; numbersOf0--) {
        result = result + zero;
    }
    //				result = zero;
    return result;
}//TODO DEV

std::string
StringUnit::replaceMeaningless0WithSpace(std::string i2262URH) { //replace those meaningless gaps (0) in URH code
    for (int numbersOf0 = 100; numbersOf0 > 0; numbersOf0--) {
        replace_mod(i2262URH, StringUnit::makeStringFullOf0withANumber(numbersOf0), " ");
    }
    return i2262URH;
}

std::string putTheCodeIntoArray(std::string iCodeThatAlreadySeperatedByA) {
    std::string line = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1";
    std::string oCodeThatInArray[25];
    unsigned int i = 0;
    std::stringstream ssin(line);
    while (ssin.good() && i < 25) {
        ssin >> oCodeThatInArray[i];
        ++i;
    }
    for (i = 0; i < 25; i++) {
    }
    return oCodeThatInArray[24];
}//TODO DEV

int StringUnit::getLengthOfVariable(std::string variableName) {
    int lengthOfVariable = variableName.length();
    return lengthOfVariable;
}

std::string StringUnit::removeNonDesiredCharacters(const std::string &str, const std::string &desiredChars) {
    std::string result;
    for (char c: str) {
        if (desiredChars.find(c) != std::string::npos) {
            result += c;
        }
    }
    return result;
}