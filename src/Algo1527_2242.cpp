//
// Created by zxkmm.
//

#define BIT_NUM_1527 24

#include "Algo1527_2242.h"

std::string Algo1527_2242::decode1527FromUrh(std::string stringOf1527WaveformFromUrh) {

    //desired 01

    StringUnit stringUnit;
    std::ostringstream ossCode;
    std::string decoded1527 = "";
    stringOf1527WaveformFromUrh = stringUnit.removeNonDesiredCharacters(stringOf1527WaveformFromUrh, "01");
    stringOf1527WaveformFromUrh = "0" + stringOf1527WaveformFromUrh + "0";
//    std::cout << "\n15$" + stringOf1527WaveformFromUrh + "$\n" << std::endl; //DBG
    stringOf1527WaveformFromUrh = stringUnit.replaceMeaningless0WithSpace(stringOf1527WaveformFromUrh);
//    std::cout << "\n17$" + stringOf1527WaveformFromUrh + "$\n" << std::endl; //DBG

    //检测line这个字符串当中有多少个由空格分开的部分，如果由空格分开的部分小于25或者大于26，就提示异常
    int count = 0;
    for (int i = 0; i < stringOf1527WaveformFromUrh.length(); i++) {
        if (stringOf1527WaveformFromUrh[i] == ' ') {
            count++;
        }
    }
    if (count != (1 + BIT_NUM_1527 + 1)) {

        decoded1527 =
                "Error: you inputed too less or too many data, it could happen if the encoder is not 1527. the data you inputed has "
                + std::to_string(count - 1) + " wave crest, but 1527 should be be 25 \n";

        return decoded1527;
    }


    //std::cout << "replaced is " + stringOf1527WaveformFromUrh + "\n"; //DBG
    std::string oCodeThatInArray[BIT_NUM_1527 + 1];
    std::string oDataCodeThatInArray[4];
    int i = 0;
    std::stringstream ssin(stringOf1527WaveformFromUrh);
    while (ssin.good() && i < (1 + BIT_NUM_1527 + 1)) {
        ssin >> oCodeThatInArray[i];
        ++i;
    }
    //now oCodeThatInArray[] still contains address code and sync bit
    //    std::cout << "\nDBG:oCodeThatInArray:";
    //    for(int i = 0;i<26;i++){//DBG
    //                    std::cout << oCodeThatInArray[i];
    //                    std::cout << " ";
    //    }
    //    std::cout << "\n";

    //avg
    int sumOfLength = 0;
    for (const auto &i: oCodeThatInArray) {
        sumOfLength += stringUnit.getLengthOfVariable(i);
    }
    int averageOfLength = sumOfLength / (BIT_NUM_1527 + 1);


    //    std::cout << "\nDBG:average: " << average << std::endl;//DBG
    //    for (i = 0; i < 25; i++) {//DBG
    //        cout << oCodeThatInArray[i] << endl;
    //    }
    //    return oCodeThatInArray[24];

    int number = 0;
    std::string NWModeOfCode = "";
    const std::string N = "N";
    const std::string W = "W";
    for (; number < 25; number++) {//25 is total 1527 wave numbers,24 is for remove the sync code
        //Convert oCodeThatInArray[number] into int
        int oCodeThatInArrayInt = stoi(oCodeThatInArray[number]);
        if (std::to_string(oCodeThatInArrayInt).length() <= averageOfLength) {
            NWModeOfCode = NWModeOfCode + N;
//            std::cout << "$\n"+NWModeOfCode+"\n" << std::endl;
        } else if (std::to_string(oCodeThatInArrayInt).length() > averageOfLength) {
            NWModeOfCode = NWModeOfCode + W;
//            std::cout << "@\n"+NWModeOfCode+"\n" << std::endl;
        } else {
            decoded1527 = "Error: the average is " + std::to_string(averageOfLength) + " and the number is " +
                          oCodeThatInArray[number] + "\n";
            return decoded1527;
            break;
        }
    }

    for (i = 0; i < 4; i++) {//this is for data code
        oDataCodeThatInArray[i] = NWModeOfCode.substr(NWModeOfCode.length() - i - 2, 1);
//        std::cout <<"!101"<< oDataCodeThatInArray[i]; //DBG
    }

    //cut the last 5 characters of NWModeOfCode, which means delete the last 5 characters aka data code and sync code.
    NWModeOfCode = NWModeOfCode.substr(0, NWModeOfCode.length() - 5);
//    std::cout << "\nDBG:NWModeOfCode: " << NWModeOfCode << std::endl;//this without data code and sync code//DBG

    long n = NWModeOfCode.length();//separate NWModeOfCode per 2 char by space, -4 is for remove the data code temp.ly
    while (n - 2 > 0) {

        n = n - 2;
        NWModeOfCode.insert(n, " ");

    }


    //now take care of last 5 characters aka data code and sync code.
    //replace all W into 1 and all	N into 0 in oDataCodeThatInArray
    for (i = 0; i < 4; i++) {
        if (oDataCodeThatInArray[i] == W) {
            oDataCodeThatInArray[i] = "1";
        } else if (oDataCodeThatInArray[i] == N) {
            oDataCodeThatInArray[i] = "0";
        } else {
            decoded1527 = "Error: the average is " + std::to_string(averageOfLength) + " and the number is " +
                          oCodeThatInArray[number] + "\n";
            return decoded1527;
            break;
        }
    }


    std::string NWModeCodeThatInArray[26];
    int i2 = 0;
    std::stringstream ssin2(NWModeOfCode);
    while (ssin2.good() && i2 < 26) {
        ssin2 >> NWModeCodeThatInArray[i2];
        ++i2;
    }
    for (auto &y: NWModeCodeThatInArray) {//last 4 data code is combined with  NN aka 0 and WW aka 1 anyway, so it's fine to be converted again
        stringUnit.replace_mod(y, "NN", "0");
        stringUnit.replace_mod(y, "NW", "F");
        stringUnit.replace_mod(y, "WW", "1");
        stringUnit.replace_mod(y, "WN", "H");
    }


    ossCode.str("");

    for (auto &y: NWModeCodeThatInArray) {

        ossCode << y;
    }
    //print a space and oDataCodeThatInArray aka data code

    //revert oDAtaCodeThatInArray e.g. 0001 to 1000
    std::reverse(std::begin(oDataCodeThatInArray), std::end(oDataCodeThatInArray));


    for (i = 0; i < 4; i++) {// print data code
        ossCode << oDataCodeThatInArray[i];
    }

    decoded1527 = ossCode.str();


    return decoded1527;


}


std::string Algo1527_2242::trans4Bit1527To2Bit(std::string i1527B4) {

    //desired 01HF

    StringUnit stringUnit;

    i1527B4 = stringUnit.removeNonDesiredCharacters(i1527B4, "01HF");

//    std::string i1527B4;
    std::string o1527B2;

    //detect if user inputted right code
    if (stringUnit.getLengthOfVariable(i1527B4) == 10) {//size right
        //size right
        goto start15274to2work;
    } else if (stringUnit.getLengthOfVariable(i1527B4) == 14) {//inputted data code
        o1527B2 = "It seems you inputted the data code, please only input address code.\n";
        return o1527B2;


    } else {//unknown size
        o1527B2 = "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        return o1527B2;

    }
    start15274to2work:
    stringUnit.replace_mod(i1527B4, "1", "3");
    stringUnit.replace_mod(i1527B4, "F", "1");
    stringUnit.replace_mod(i1527B4, "H", "2");
    o1527B2 = stringUnit.DEC2anyBS(stringUnit.anyBS2DEC(i1527B4, 4), 2);

    if (stringUnit.getLengthOfVariable(o1527B2) < 20) {//In case if the 4 base (4Bit) data started with 0;
        for (long length = stringUnit.getLengthOfVariable(o1527B2); length < 20; length++) {
            o1527B2 = "0" + o1527B2;
        }
    }

    //detect if the size is correct
    if (stringUnit.getLengthOfVariable(o1527B2) != 20) {

        o1527B2 = "Error, maybe share the address code with the developer.\n Error code is:" +
                  std::to_string(stringUnit.getLengthOfVariable(o1527B2)) + o1527B2 + "\n";
        return o1527B2;


    } else {
        //detected end

        return o1527B2;
    }
}

std::string Algo1527_2242::trans2Bit1527To4Bit(std::string i1527B2) {

    //desired 01

    std::string o1527B4;

    StringUnit stringUnit;

    i1527B2 = stringUnit.removeNonDesiredCharacters(i1527B2, "01");


    //detect if user inputted right code
    if (stringUnit.getLengthOfVariable(i1527B2) == 20) {//size right
        //size is right
        goto start15272to4work;
    } else if (stringUnit.getLengthOfVariable(i1527B2) == 24) {//inputted data code
//        cout << "It seems you inputted the data code, please only input address code.";
        o1527B4 = "It seems you inputted the data code, please only input address code.";
        return o1527B4;
    } else {//unknown size
        o1527B4 = "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        return o1527B4;
    }
    start15272to4work:
    o1527B4 = stringUnit.DEC2anyBS(stringUnit.anyBS2DEC(i1527B2, 2), 4);
    stringUnit.replace_mod(o1527B4, "1", "F");
    stringUnit.replace_mod(o1527B4, "3", "1");
    stringUnit.replace_mod(o1527B4, "2", "H");
    if (stringUnit.getLengthOfVariable(o1527B4) < 10) {//In case if the 2 base (2Bit) data started with 0;
        for (long length = stringUnit.getLengthOfVariable(o1527B4); length < 10; length++) {

            o1527B4 = "0" + o1527B4;
        }
    }
    if (stringUnit.getLengthOfVariable(o1527B4) == 10) {//check if the output is correct
        //if correct
        goto startOutput1527B4;
    } else {
        o1527B4 = "Error, maybe share the address code with the developer";
        return o1527B4;

    }
    startOutput1527B4:
    return o1527B4;

}





