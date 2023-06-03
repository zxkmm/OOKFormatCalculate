//
// Created by zxkmm.
//

#include "Algo226x.h"

std::string Algo226x::decode2262FromUrh(std::string stringOf2262WaveformFromUrh) {

    //desired 01

    /**
    流程：
    1:找到高电平的无意义的1的个数（肯定是大于2且大于低电平）
    2.找到低电平的无意义的1的个数（肯定是小于高电平）
    3.从左边开始查找``find()``，找到一个1(高电平)，再往左找，｜如果是低电平（0），就在数组1中给[0]值0，然后继续查找。
    ｜如果是高电平（1），就在数组1中给[0]值1，然后继续找。
    4.在数组1中查找，如果可以的话直接用替换法，先把11替换成a，再把10替换成b等等，反正要让顺序不要出现矛盾（或者两两放到数组中再操作更稳妥，包括可以把上面那个case一起替换了）
    如果不可以用替换法，就用第三步的方法。
    */

    StringUnit stringUnit;

    stringOf2262WaveformFromUrh = stringUnit.removeNonDesiredCharacters(stringOf2262WaveformFromUrh, "01");

    stringOf2262WaveformFromUrh = stringUnit.replaceMeaningless0WithSpace(stringOf2262WaveformFromUrh);

    std::string oCodeThatInArray[25];
    int i = 0;
    std::stringstream ssin(stringOf2262WaveformFromUrh);
    while (ssin.good() && i < 25) {
        ssin >> oCodeThatInArray[i];
        ++i;
    }


    //Calculate the average	of the array
    int sum = 0;
    for (const auto &i: oCodeThatInArray) {
        sum += stoi(i);
    }
    int average = sum / 25;


    int number = 0;
    std::string NWModeOfCode = "";
    const std::string N = "N";
    const std::string W = "W";
    for (; number < 24; number++) {//25 is total 2262 wave numbers,24 is for remove the sync code
        //Convert oCodeThatInArray[number] into int
        int oCodeThatInArrayInt = stoi(oCodeThatInArray[number]);
        if (oCodeThatInArrayInt <= average) {
            NWModeOfCode = NWModeOfCode + N;
        } else if (oCodeThatInArrayInt > average) {
            NWModeOfCode = NWModeOfCode + W;
        } else {
            std::string error = "Error: the average is " + std::to_string(average) + " and the number is " +
                                std::string(oCodeThatInArray[number]);

            return error;
        }
    }
    stringUnit.replace_mod(NWModeOfCode, "NN", "0");
    stringUnit.replace_mod(NWModeOfCode, "NW", "F");
    stringUnit.replace_mod(NWModeOfCode, "WW", "1");


    //check if there's any "N" or "W" in NWMoDeOfCode
    if (NWModeOfCode.find("N") != std::string::npos || NWModeOfCode.find("W") != std::string::npos) {
        std::string error = "Error: Maybe try 1527. this encoder looks like 1527, if there's still error, maybe share the raw with dev\n";
        return error;
    }


    return NWModeOfCode;

}
