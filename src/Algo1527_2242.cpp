//
// Created by zxkmm.
//

#include "Algo1527_2242.h"

std::string Algo1527_2242::decode1527FromUrh(std::string stringOf1527WaveformFromUrh) {
    StringUnit stringUnit;
    std::ostringstream ossCode;
    std::string decoded1527 = "";

//    string stringOf1527WaveformFromUrh = "";
//    cout << "Input 1527 demodulated code from URH:\n>";
//    cin >> stringOf1527WaveformFromUrh;
    stringOf1527WaveformFromUrh = stringUnit.replaceMeaningless0WithSpace(stringOf1527WaveformFromUrh);

    //检测line这个字符串当中有多少个由空格分开的部分，如果由空格分开的部分小于25或者大于26，就提示异常
    int count = 0;
    for (int i = 0; i < stringOf1527WaveformFromUrh.length(); i++) {
        if (stringOf1527WaveformFromUrh[i] == ' ') {
            count++;
        }
    }
    if (count != 25) {

        decoded1527 =
                "Error: you inputed too less or too many data, it could happen if the encoder is not 1527. the data you inputed has "
                + std::to_string(count) + " wave crest, but 1527 should be be 25 \n";

        return decoded1527;


//        cout
//                << "Error: you inputed too less or too many data, it could happen if the encoder is not 1527. the data you inputed has "
//                << count << " wave crest, but 1527 should be be 25 \n";
//        goto startplace;
    }


    //												cout << "replaced is " + stringOf1527WaveformFromUrh + "\n"; //DBG
    //												string stringOf1527WaveformFromUrh = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1"; //DBG
    std::string oCodeThatInArray[25];
    std::string oDataCodeThatInArray[4];
    int i = 0;
    std::stringstream ssin(stringOf1527WaveformFromUrh);
    while (ssin.good() && i < 26) {
        ssin >> oCodeThatInArray[i];
        ++i;
    }
    //												cout << "\nDBG:oCodeThatInArray:";
    //												for(int i = 0;i<26;i++){//DBG
    //																cout << oCodeThatInArray[i];
    //																cout << " ";
    //												}
    //												cout << "\n";


    //Calculate the average	of the array
    int sum = 0;
    for (const auto &i: oCodeThatInArray) {
        sum += stoi(i);
    }
    int average = sum / 25;                                                //												for(i = 0; i < 25; i++){//DBG
    //																cout << oCodeThatInArray[i] << endl;
    //												}
    //												return oCodeThatInArray[24];

    int number = 0;
    std::string NWModeOfCode = "";
    const std::string N = "N";
    const std::string W = "W";
    for (; number < 25; number++) {//25 is total 1527 wave numbers,24 is for remove the sync code
        //Convert oCodeThatInArray[number] into int
        int oCodeThatInArrayInt = stoi(oCodeThatInArray[number]);
        if (oCodeThatInArrayInt <= average) {
            NWModeOfCode = NWModeOfCode + N;
            //																				cout << "\n追加n\n"; //DBG
        } else if (oCodeThatInArrayInt > average) {
            NWModeOfCode = NWModeOfCode + W;
            //																				cout << "\n 追加w \n"; //DBG
        } else {
//            cout << "Error: the average is " << average << " and the number is " << oCodeThatInArray[number] << endl;

            decoded1527 = "Error: the average is " + std::to_string(average) + " and the number is " +
                          oCodeThatInArray[number] + "\n";
            return decoded1527;
            break;
        }
    }

    //												cout << "DBG";
    //												for (i=0; i<4; i++) {//DBG
    //																oDataCodeThatInArray[i] = oCodeThatInArray[i+21];
    //																cout << oDataCodeThatInArray[i];
    //												}

    //cut the last 5 characters of NWModeOfCode, which means delete the last 5 characters aka data code and sync code.
    NWModeOfCode = NWModeOfCode.substr(0, NWModeOfCode.length() - 5);
    //												cout << "\nDBG:NWModeOfCode: " << NWModeOfCode << endl;

    //cut last 1 characters of NWModeOfCode and assign to oDataCodeThatInArray, which means seperated the last 5 characters aka data code + sync code, and put them into oDataCodeThatInArray, and take care if it later
    for (i = 0; i < 4; i++) {//DBG
        oDataCodeThatInArray[i] = NWModeOfCode.substr(i, 1);
        //																cout << oDataCodeThatInArray[i];
    }

    long n = NWModeOfCode.length();//separate NWModeOfCode per 2 char by space, -4 is for remove the data code temp.ly
    while (n - 2 > 0) {
        //																cout << "DBG:NWModeOfCode:";
        //																cout << NWModeOfCode;
        //																cout << "\n";
        n = n - 2;
        NWModeOfCode.insert(n, " ");
        //																cout << "DBG:NWModeOfCode:";
        //																cout << NWModeOfCode;
        //																cout << "\n";
    }
    //												cout << "DBG:NWModeOfCode:";
    //												cout << NWModeOfCode;
    //												cout << "\n";

    //now take care of last 5 characters aka data code and sync code.
    //replace all W into 1 and all	N into 0 in oDataCodeThatInArray
    for (i = 0; i < 4; i++) {//DBG
        if (oDataCodeThatInArray[i] == W) {
            oDataCodeThatInArray[i] = "1";
        } else if (oDataCodeThatInArray[i] == N) {
            oDataCodeThatInArray[i] = "0";
        } else {
//            cout << "Error: the average is " << average << " and the number is " << oCodeThatInArray[number] << endl;
            decoded1527 = "Error: the average is " + std::to_string(average) + " and the number is " +
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
        //												cout << "\n" + NWModeOfCode + "\n"; //DBG
        stringUnit.replace_mod(y, "NN", "0");
        stringUnit.replace_mod(y, "NW", "F");
        stringUnit.replace_mod(y, "WW", "1");
        stringUnit.replace_mod(y, "WN", "H");
    }
    //												cout << NWModeOfCode; //DBG
//    cout << "\n----\n";


//    cout << "Static ternary code of it is ";


    ossCode.str("");

    for (auto &y: NWModeCodeThatInArray) {

        ossCode << y;
    }
    //print a space and oDataCodeThatInArray aka data code
    //												cout << " ";
    for (i = 0; i < 4; i++) {// print data code
        ossCode << oDataCodeThatInArray[i];
    }

    decoded1527 = ossCode.str();

//    cout << "\n                             AAAAAAAAAADDDD";
//    cout << "\n----\nmain menu\n----\n";
//    goto startplace;


    return decoded1527;
//    THE_END:


}


std::string Algo1527_2242::trans4Bit1527To2Bit(std::string i1527B4) {

    StringUnit stringUnit;


//    std::string i1527B4;
    std::string o1527B2;
//    cout << "Input 4Bits 1527 code(Without data code):\n>";
//    cin >> i1527B4;
    //detect if user inputted right code
    if (stringUnit.getLengthOfVariable(i1527B4) == 10) {//size right
        //size right
        goto start15274to2work;
    } else if (stringUnit.getLengthOfVariable(i1527B4) == 14) {//inputted data code
//        cout << "It seems you inputted the data code, please only input address code.\n";
        o1527B2 = "It seems you inputted the data code, please only input address code.\n";
        return o1527B2;


//        goto startplace;
    } else {//unknown size
        //																cout << size(i1527B4);//DBG
//        cout << "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        o1527B2 = "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        return o1527B2;

//        goto startplace;
    }
    start15274to2work:
    stringUnit.replace_mod(i1527B4, "1", "3");
    stringUnit.replace_mod(i1527B4, "F", "1");
    stringUnit.replace_mod(i1527B4, "H", "2");
    o1527B2 = stringUnit.DEC2anyBS(stringUnit.anyBS2DEC(i1527B4, 4), 2);
    //												cout  <<"2Bit of it is " + DEC2anyBS(anyBS2DEC(i1527B4, 4), 2) << "\n";

    if (stringUnit.getLengthOfVariable(o1527B2) < 20) {//In case if the 4 base (4Bit) data started with 0;
        for (long length = stringUnit.getLengthOfVariable(o1527B2); length < 20; length++) {
            //																				cout << length;//DBG
            //																				cout << "\n";//DBG
            o1527B2 = "0" + o1527B2;
        }
    }
    //            break;
    //												cout << size(o1527B2);//DBG
    //detect if the size is correct
    if (stringUnit.getLengthOfVariable(o1527B2) != 20) {
//        cout << "Error, maybe share the address code with the developer.\n";
//        cout << "Error code is:";
//        cout << getLengthOfVariable(o1527B2);
//        cout << o1527B2;
//        cout << "\n";
        o1527B2 = "Error, maybe share the address code with the developer.\n Error code is:" + std::to_string(stringUnit.getLengthOfVariable(o1527B2)) + o1527B2 + "\n";
        return o1527B2;



//        goto startplace;
    } else {
        //detected end
//        outputAClearResult("2Bit code if it is:", o1527B2, "AAAAAAAAAAAAAAAAAAAA + Your data code");
//        cout << "\n----\nmain menu\n----\n";
//        goto startplace;
    return o1527B2;
    }
}

std::string Algo1527_2242::trans2Bit1527To4Bit(std::string i1527B2){

    std::string o1527B4;

    StringUnit stringUnit;

//    string i1527B2;
//    cout << "Input 2Bits 1527 code(Without data code):\n>";
//    cin >> i1527B2;
    //detect if user inputted right code
    if(stringUnit.getLengthOfVariable(i1527B2) == 20){//size right
        //size right
        goto start15272to4work;
    }else if (stringUnit.getLengthOfVariable(i1527B2) == 24){//inputted data code
//        cout << "It seems you inputted the data code, please only input address code.";
        o1527B4 = "It seems you inputted the data code, please only input address code.";
        return o1527B4;
//        goto startplace;
    }else{//unknown size
//        cout << "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        o1527B4 = "You inputted a wrong code. Please make sure you inputted 1527 address code.";
        return o1527B4;
//        goto startplace;
    }
    start15272to4work:
    o1527B4 = stringUnit.DEC2anyBS(stringUnit.anyBS2DEC(i1527B2, 2), 4);
    stringUnit.replace_mod(o1527B4, "1", "F");
    stringUnit.replace_mod(o1527B4, "3", "1");
    stringUnit.replace_mod(o1527B4, "2", "H");
    if (stringUnit.getLengthOfVariable(o1527B4)<10){//In case if the 2 base (2Bit) data started with 0;
        for (long length = stringUnit.getLengthOfVariable(o1527B4); length < 10; length ++) {
            //																				cout << length;//DBG
            //																				cout << "\n";//DBG
            o1527B4 = "0" + o1527B4;
        }
    }
    if (stringUnit.getLengthOfVariable(o1527B4) == 10) {//check if the output is correct
        //if correct
        goto startOutput1527B4;
    } else{
//        cout << "Error, maybe share the address code with the developer";
        o1527B4 = "Error, maybe share the address code with the developer";
        return o1527B4;

    }
    startOutput1527B4:
//    outputAClearResult("4Bit code if it is:", o1527B4, "AAAAAAAAAA + Your data code");
    return o1527B4;
//            cout  << "4Bit of it is " + o1527B4 << "\n";
    //            break;
//    cout << "\n----\nmain menu\n----\n";
//    goto startplace;
}





