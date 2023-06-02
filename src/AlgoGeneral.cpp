//
// Created by zxkmm on 2/6/23.
//

#include "AlgoGeneral.h"

std::string AlgoGeneral::decodeGeneralFromUrh(std::string oCodeGeneral) {

    StringUnit stringUnit;

    //ask user to input a string
//    cout << "Please input a general demodulated code from URH: \n>";
//    string oCodeGeneral;
//    cin >> oCodeGeneral;
//            //DBG start
//            cout << "\n----\n";
//            cout << oCodeGeneral;
//            cout << "\n----\n";
//            //DBG end
    //add 0 is for making sure that the both sides of the string has 0, so that the string can be divided by space, and we could detect how long the array should be.
    //add "0" to the end of oCodeGeneral
    oCodeGeneral = oCodeGeneral + "0";
    //add "0" to the start of oCodeGeneral
    oCodeGeneral = "0" + oCodeGeneral;

//            //DBG start
//            cout << "\n----\n";
//            cout << oCodeGeneral;
//            cout << "\n----\n";
//            //DBG end

    oCodeGeneral = stringUnit.replaceMeaningless0WithSpace(oCodeGeneral);

    //if there is one or more spaces in the beginning of the string, delete them
    while (oCodeGeneral[0] == ' ') {
        oCodeGeneral = oCodeGeneral.substr(1);
    }
    //if there is one or more spaces in the end of the string, delete them
    while (oCodeGeneral[oCodeGeneral.length() - 1] == ' ') {
        oCodeGeneral = oCodeGeneral.substr(0, oCodeGeneral.length() - 1);
    }


    //detect how many space in the string
    int spaceCount = 0;
    for (char i : oCodeGeneral) {
        if (i == ' ') {
            spaceCount++;
        }
//																spaceCount = spaceCount + 1;
    }


    std::string oCodeThatInArray[spaceCount];
    //put the string which seperated by spaces into oCodeThatInArray
    int i = 0;
    std::stringstream ssin(oCodeGeneral);
    while (ssin.good() && i < spaceCount){
        ssin >> oCodeThatInArray[i];
        ++i;
    }
//           for (int y = 0; y < spaceCount; y++) {
//            	cout << oCodeThatInArray[y] << endl;
//                cout << "\nend";
//            }

    //calculate the average of the array
    int average = 0;
    for (int number = 0; number < spaceCount; number++) {
        average = average + stoi(oCodeThatInArray[number]);
    }
    average = average / spaceCount;
    std::string NWModeOfCode = "";

    //check the array one by one and if one of the number is bigger than the average, then add W into NWModeOfCode, if not, add N into NWModeOfCode
    for (int number = 0; number < spaceCount; number++) {
        if (stoi(oCodeThatInArray[number]) > average) {
            NWModeOfCode = NWModeOfCode +"-";
        }else{
            NWModeOfCode = NWModeOfCode + ".";
        }
    }
//    cout << ".-ModeOfGeneralCode:";
//    cout << NWModeOfCode;
    return NWModeOfCode;
//    cout << "\n";

//    cout << "\n----\nmain menu\n----\n";
//    goto startplace;


}

