//
//  main.cpp
//  OOKFormatCalculate
//
//  Created by zxkmm on 2022/6/26.
//  I wrote trash....

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int anyBS2DEC(string s,int radix){    //Any base to DEC. s for incoming string, radix for it's BS
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        char t=s[i];
        if(t>='0'&&t<='9') ans=ans*radix+t-'0';
        else ans=ans*radix+t-'a'+10;
    }
    return ans;
}

string DEC2anyBS(int n,int radix){    //DEC to any base. n for incoming numbers(int)，radix for it's BS

    string ans = "";
    do{
        int t=n%radix;
        if(t>=0&&t<=9)    ans+=t+'0';
        else ans+=t-10+'a';
        n/=radix;
    }while(n!=0);    //anti-0-exception
    reverse(ans.begin(),ans.end());
    return ans;
}

/*
	manual string: src
	sub-string which is needed 2 be replaced: old_value
	to: new_value
	*/
string& replace_mod(string& src, const string& old_value, const string& new_value) {//Replace in my way, I hate using string::replace
    // Anti-loop
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = src.find(old_value, pos)) != string::npos) {
            src.replace(pos, old_value.length(), new_value);
        }
        else break;
    }
    return src;
}




string makeShortestGrain(int numOfGrain){//the number of meaningless "0" in input data，e.g. 4，then make a string with content "1111"
    string stringGrain = "1";
    for ( ; numOfGrain > 1; numOfGrain --) {
        //make grain string, e.g. when grainNum=4 ,then make stringGrain = "1111".
        stringGrain = stringGrain + "1" ;
    }
    //    string stringGrain;
    //    stringGrain = to_string(stringGrainInInt);
    return stringGrain;
}//TODO DEV

string detectShortestGrainSize(string dataFromURH){
    //check how many meaningless "0" in the data from URH, e.g. 1111, then return 4(int). start looking since 10
    //查看来自URH的数据里面高电平的粒度是什么，例如是不是1111，从10个1开始找
    int tes1t;
    for (tes1t = 10; tes1t > 0; tes1t --) {

        if (dataFromURH.find(makeShortestGrain(tes1t)) != string::npos)
        {
            cout << makeShortestGrain(tes1t) << endl;
            //如果找到
            //If found
            break;

            //返回高电平信号位的在URH显示的1的个数 TODO
            //return number of meaningless "1", since clock doesn't matter for this tool.
        }
    }

    return makeShortestGrain(tes1t);
}//TODO DEV

string decode2262FromURH(string dataFromURH){
    string result3Bit2262Code;
    //TODO


    return result3Bit2262Code;
}

string makeStringFullOf0withANumber(int numbersOf0){
    string result = "";
    string zero = "0";
    for (;numbersOf0 > 0;numbersOf0 --){
        result = result + zero;
    }
    //				result = zero;
    return result;
}//TODO DEV

string replaceMeaningless0WithSpace(string i2262URH){ //replace those meaningless gaps (0) in URH code
    for (int numbersOf0 = 100; numbersOf0 > 0; numbersOf0 --) {
        replace_mod(i2262URH, makeStringFullOf0withANumber(numbersOf0), " ");
    }
    return i2262URH;
}

string putTheCodeIntoArray(string iCodeThatAlreadySeperatedByA){
    string line = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1";
    string oCodeThatInArray[25];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 25){
        ssin >> oCodeThatInArray[i];
        ++i;
    }
    for(i = 0; i < 25; i++){
        cout << oCodeThatInArray[i] << endl;
    }
    return oCodeThatInArray[24];
}//TODO DEV

void outputAClearResult(string explainContent, string result, string ADFormat){
    cout << explainContent << result << ADFormat << endl;
	//detect how long the result is, then put the result into an int variable
    int resultLength = result.length();
    //detect how long the explainContent is, then put the explainContent into an int variable
    int explainContentLength = explainContent.length();
    //out put spaces which is as long as explainContentLength
    for (int i = 0; i < explainContentLength; i++) {
        cout << " ";
    }
    cout << "┏";
    //output spaces which is as long as resultLength
    for (int i = 0; i < resultLength; i++) {
        cout << "━";
    }
    cout << "┓" << endl;
    cout << explainContent << "┃" << result << "┃" << endl;
    for (int i = 0; i < explainContentLength; i++) {
        cout << " ";
    }
    cout << "┗";
    for (int i = 0; i < resultLength; i++) {
        cout << "━";
    }
    cout << "┛" << endl;
    //output spaces which is as long as explainContentLength
    for (int i = 0; i < explainContentLength; i++) {
        cout << " ";
    }
    cout << " "+ ADFormat;
    cout << "\n";
}



//string identifyNWMode(){
//				int number = 0;
//				for (; number > 24; number ++) {//25 is total 2262 wave numbers
//								if () {
//
//								}
//				}
//}



//int detectShortestGrainSize(string dataFromURH){ //探测URH数据传过来的二进制字符串的最小粒度
//    int minGrain = 1;
//    for (int grainNum = 10; grainNum == 0; grainNum --) {
//        for (int realGrainNum = grainNum; realGrainNum == 0; realGrainNum --) {  //制造grain字符串, 例如grainNum值为4则制造赋值stringGrain = "1111"
//            int stringGrainInInt = 1;
//            stringGrainInInt = stringGrainInInt ++;
//            if (stringGrainInInt > 1) {
//                string stringGrain = to_string(stringGrainInInt);
//                break;
//            }
//        }
//
//        //查找存不存在诸如1111的字符串在dataFromURH中，如果存在，则返回处理完的字符串即realGrainNum
//    }
//    return minGrain;
//}

int main(){
    cout << "\n----\nPress 1 for 4Bits 1527 code to 2Bits\ne.g.H0FF1FHFHH>>10000101110110011010\n----\nPress 2 for 2Bits 1527 code to 4Bits\ne.g. 10000101110110011010>>H0FF1FHFHH\n----\nPress 3 for demodulated wave form to 3Bit 2262 code\ne.g. NNNNWWNNNNNWNNNWNNNWNNNNS>>00100F0F0F00\n----\nPress 4 for 3Bit 2262 code to demodulated wave form\n(Kinda useless but i just put it here in case if someone really need it :))\ne.g. 00100F0F0F00>>NNNNWWNNNNNWNNNWNNNWNNNNS\n----\nPress 5 for demodulated 2262/2260 from URH to static 2262/2260 code\n----\nPress 6 for demodulated 1527 from URH to static 1527 code\n----\nPress 7 for general decode e.g. Tesla/K5 Morining/Car keys\n----\nPress 99 to exit.\n";
    startplace:
    cout << "Your choice:\n>";
    int select;
    cin >> select;
    switch(select){
        case 1 : {//1527 base4 to base2
            string i1527B4;
            string o1527B2;
            cout << "Input 4Bits 1527 code(Without data code):\n>";
            cin >> i1527B4;
            //detect if user inputted right code
            if(size(i1527B4) == 10){//size right
                //size right
                goto start15274to2work;
            }else if (size(i1527B4) == 14){//inputted data code
                cout << "It seems you inputted the data code, please only input address code.\n";
                goto startplace;
            }else{//unknown size
                //																cout << size(i1527B4);//DBG
                cout << "You inputted a wrong code. Please make sure you inputted 1527 address code.";
                goto startplace;
            }
            start15274to2work:
            replace_mod(i1527B4, "1", "3");
            replace_mod(i1527B4, "F", "1");
            replace_mod(i1527B4, "H", "2");
            o1527B2 = DEC2anyBS(anyBS2DEC(i1527B4, 4), 2);
            //												cout  <<"2Bit of it is " + DEC2anyBS(anyBS2DEC(i1527B4, 4), 2) << "\n";

            if (size(o1527B2)<20){//In case if the 4 base (4Bit) data started with 0;
                for (long length = size(o1527B2); length < 20; length ++) {
                    //																				cout << length;//DBG
                    //																				cout << "\n";//DBG
                    o1527B2 = "0" + o1527B2;
                }
            }
            //            break;
            //												cout << size(o1527B2);//DBG
            //detect if the size is correct
            if(size(o1527B2) != 20){
                cout << "Error, maybe share the address code with the developer.\n";
                cout << "Error code is:";
                cout << size(o1527B2);
                cout << o1527B2;
                cout << "\n";
                goto startplace;
            }else{
                //detected end
                outputAClearResult("2Bit code if it is:", o1527B2, "AAAAAAAAAAAAAAAAAAAA + Your data code");
                cout << "\n----\nmain menu\n----\n";
                goto startplace;
            }
        }
        case 2 : { //1527 Base 2 to Base 4
            string i1527B2;
            cout << "Input 2Bits 1527 code(Without data code):\n>";
            cin >> i1527B2;
            //detect if user inputted right code
            if(size(i1527B2) == 20){//size right
                //size right
                goto start15272to4work;
            }else if (size(i1527B2) == 24){//inputted data code
                cout << "It seems you inputted the data code, please only input address code.";
                goto startplace;
            }else{//unknown size
                cout << "You inputted a wrong code. Please make sure you inputted 1527 address code.";
                goto startplace;
            }
            start15272to4work:
            string o1527B4 = DEC2anyBS(anyBS2DEC(i1527B2, 2), 4);
            replace_mod(o1527B4, "1", "F");
            replace_mod(o1527B4, "3", "1");
            replace_mod(o1527B4, "2", "H");
            if (size(o1527B4)<10){//In case if the 2 base (2Bit) data started with 0;
                for (long length = size(o1527B4); length < 10; length ++) {
                    //																				cout << length;//DBG
                    //																				cout << "\n";//DBG
                    o1527B4 = "0" + o1527B4;
                }
            }
            if (size(o1527B4) == 10) {//check if the output is correct
                //if correct
                goto startOutput1527B4;
            } else{
                cout << "Error, maybe share the address code with the developer";
            }
            startOutput1527B4:
            outputAClearResult("4Bit code if it is:", o1527B4, "AAAAAAAAAA + Your data code");
//            cout  << "4Bit of it is " + o1527B4 << "\n";
            //            break;
            cout << "\n----\nmain menu\n----\n";
            goto startplace;
        }
        case 3 : { //2262 waveform to Base 3
            string i2262WS;
            startInput2262WS:
            cout << "Input demodulated wave form of 2262 (WITHOUT sync code):\ne.g.\n";
            cout << " ┌┐ ┌┐ ┌──┐ ┌──┐ ┌┐ ┌──┐ ┌┐ \n";
            cout << " ││ ││ │  │ │  │ ││ │  │ ││ \n";
            cout << "─┘└─┘└─┘  └─┘  └─┘└─┘  └─┘└─\n";
            cout << " N  N    W    W   N   W   S  \n>";
            cin >> i2262WS;
            if (size(i2262WS) == 24) {//detect is user inputted correct code
                //inputted correct
                goto startCalculate2262WS;
            }else if (size(i2262WS) == 25){
                cout << "you inputted code within sync code, you should remove sync code and try again.";
                goto startInput2262WS;
            }else{
                cout << "It seems you inputted wrong code, please make sure you inputted right 2262 code.";
                goto startInput2262WS;
            }
            startCalculate2262WS:
            replace_mod(i2262WS, "NN", "0");
            replace_mod(i2262WS, "NW", "F");
            replace_mod(i2262WS, "WW", "1");
            if (size(i2262WS) == 12) {//check if the output is correct
                //output is correct
                goto startOutput3Bit2262;
            }else{
                cout << "It seems you inputted wrong code, please make sure you inputted right 2262 code.";//it is because user inputted those form that doesn't exist e.g. it contains WS aka H which is not exist in 2262.
                goto startInput2262WS;
            }
            //												cout << i2262WS;
            startOutput3Bit2262:
//            cout  << "Base3 of it is " + i2262WS << "\n";
            outputAClearResult("Base3 code if it is:", i2262WS, "AAAAAAAADDDD" );
            //            break;
            cout << "\n----\nmain menu\n----\n";
            goto startplace;
        }
        case 4 : {//2262 Base 3 to waveform
            string i2262B3;
            startInput22623B:
            cout << "Input ternary 2262 code:\n>";
            cin >> i2262B3;
            if (size(i2262B3) == 12) {//check if user inputted right 2262 3 bit code
                goto startCalculate2262WS23B;
            }else{
                cout << "It seems you inputted wrong code, please try again";
                cout << "\n";
                cout << "the code you inputed is" + i2262B3 +"and the size is";
                cout << size(i2262B3);
                goto startInput22623B;
            }
            startCalculate2262WS23B:
            replace_mod(i2262B3, "0", "NN");
            replace_mod(i2262B3, "1", "WW");
            replace_mod(i2262B3, "F", "NW");
            if (size(i2262B3) == 24) {//check if output is correct. the S is manually IO::cout so in here it is 24
                goto startOutput242262WS;
            }else{
                cout << "Error, maybe share 3Bit 2262 code with developer.";
                goto startInput22623B;
            }
            startOutput242262WS:
//            cout << "demodulated wave form of it is " + i2262B3 + "S" + "\ne.g." << "\n";
            outputAClearResult("demodulated wave form of it is:", i2262B3 + "S","AAAAAAAAAAAAAAAADDDDDDDDS");
            cout << " N  N   W    W   N    W  S  \n";
            cout << " ┌┐ ┌┐ ┌──┐ ┌──┐ ┌┐ ┌──┐ ┌┐ \n";
            cout << " ││ ││ │  │ │  │ ││ │  │ ││ \n";
            cout << "─┘└─┘└─┘  └─┘  └─┘└─┘  └─┘└─\n";
            //            break;
            cout << "backing to main menu::\n----\nmain menu\n----\n";
            goto startplace;
        }
        case 5 :{//2262 URH demodulated data to Base3
            /**
                流程：
                1:找到高电平的无意义的1的个数（肯定是大于2且大于低电平）
                2.找到低电平的无意义的1的个数（肯定是小于高电平）
                3.从左边开始查找``find()``，找到一个1(高电平)，再往左找，｜如果是低电平（0），就在数组1中给[0]值0，然后继续查找。
                ｜如果是高电平（1），就在数组1中给[0]值1，然后继续找。
                4.在数组1中查找，如果可以的话直接用替换法，先把11替换成a，再把10替换成b等等，反正要让顺序不要出现矛盾（或者两两放到数组中再操作更稳妥，包括可以把上面那个case一起替换了）
                如果不可以用替换法，就用第三步的方法。
                */
            string line = "";
            cout << "Input 2262/2260 demodulated code from URH:\n>";
            cin >> line;
            line = replaceMeaningless0WithSpace(line);
            //												cout << "replaced is " + line + "\n"; //DBG
            //												string line = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1"; //DBG
            string oCodeThatInArray[25];
            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < 25){
                ssin >> oCodeThatInArray[i];
                ++i;
            }


            //Calculate the average	of the array
            int sum = 0;
            for (int i = 0; i < 25; i++){
                sum += stoi(oCodeThatInArray[i]);
            }
            int average = sum / 25;												//												for(i = 0; i < 25; i++){//DBG
            //																cout << oCodeThatInArray[i] << endl;
            //												}
            //												return oCodeThatInArray[24];

            int number = 0;
            string NWModeOfCode = "";
            const string N = "N";
            const string W = "W";
            for (; number < 24; number ++) {//25 is total 2262 wave numbers,24 is for remove the sync code
                //Convert oCodeThatInArray[number] into int
                int oCodeThatInArrayInt = stoi(oCodeThatInArray[number]);
                if (oCodeThatInArrayInt <= average) {
                    NWModeOfCode = NWModeOfCode + N;
                    //																				cout << "\n追加n\n"; //DBG
                }else if (oCodeThatInArrayInt	>	average) {
                    NWModeOfCode = NWModeOfCode + W;
                    //																				cout << "\n 追加w \n"; //DBG
                }else{
                    cout << "Error: the average is " << average << " and the number is " << oCodeThatInArray[number] << endl;
                    break;
                }
            }
            //												cout << "\n" + NWModeOfCode + "\n"; //DBG
            replace_mod(NWModeOfCode, "NN", "0");
            replace_mod(NWModeOfCode, "NW", "F");
            replace_mod(NWModeOfCode, "WW", "1");
            //												cout << NWModeOfCode; //DBG


            //check if there's any "N" or "W" in NWMoDeOfCode
            if (NWModeOfCode.find("N") != string::npos || NWModeOfCode.find("W") != string::npos) {
                cout << "Error: Maybe try 1527. this encoder looks like 1527, if there's still error, maybe share the raw with dev\n";
                break;
            }


            cout << "\n----\n";
//            cout << "Static ternary code of it is " + NWModeOfCode << "\n";
            outputAClearResult("static 2262 code is:", NWModeOfCode, "AAAAAAAADDDD");
//            cout << "                             AAAAAAAADDDD\n";
            cout << "----\nmain menu\n----\n";
            goto startplace;
        }
        case 6 :{//1527
            string line = "";
            cout << "Input 1527 demodulated code from URH:\n>";
            cin >> line;
            line = replaceMeaningless0WithSpace(line);
            //												cout << "replaced is " + line + "\n"; //DBG
            //												string line = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1"; //DBG
            string oCodeThatInArray[25];
            string oDataCodeThatInArray[4];
            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < 26){
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
            for (int i = 0; i < 25; i++){
                sum += stoi(oCodeThatInArray[i]);
            }
            int average = sum / 25;												//												for(i = 0; i < 25; i++){//DBG
            //																cout << oCodeThatInArray[i] << endl;
            //												}
            //												return oCodeThatInArray[24];

            int number = 0;
            string NWModeOfCode = "";
            const string N = "N";
            const string W = "W";
            for (; number < 25; number ++) {//25 is total 1527 wave numbers,24 is for remove the sync code
                //Convert oCodeThatInArray[number] into int
                int oCodeThatInArrayInt = stoi(oCodeThatInArray[number]);
                if (oCodeThatInArrayInt <= average) {
                    NWModeOfCode = NWModeOfCode + N;
                    //																				cout << "\n追加n\n"; //DBG
                }else if (oCodeThatInArrayInt	>	average) {
                    NWModeOfCode = NWModeOfCode + W;
                    //																				cout << "\n 追加w \n"; //DBG
                }else{
                    cout << "Error: the average is " << average << " and the number is " << oCodeThatInArray[number] << endl;
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
            for (i=0; i<4; i++) {//DBG
                oDataCodeThatInArray[i] = NWModeOfCode.substr(i, 1);
                //																cout << oDataCodeThatInArray[i];
            }

            long n = NWModeOfCode.length();//separate NWModeOfCode per 2 char by space, -4 is for remove the data code temp.ly
            while(n - 2 > 0)
            {
                //																cout << "DBG:NWModeOfCode:";
                //																cout << NWModeOfCode;
                //																cout << "\n";
                n = n - 2;
                NWModeOfCode.insert(n," ");
                //																cout << "DBG:NWModeOfCode:";
                //																cout << NWModeOfCode;
                //																cout << "\n";
            }
            //												cout << "DBG:NWModeOfCode:";
            //												cout << NWModeOfCode;
            //												cout << "\n";

            //now take care of last 5 characters aka data code and sync code.
            //replace all W into 1 and all	N into 0 in oDataCodeThatInArray
            for (i=0; i<4; i++) {//DBG
                if (oDataCodeThatInArray[i] == W) {
                    oDataCodeThatInArray[i] = "1";
                }else if (oDataCodeThatInArray[i] == N) {
                    oDataCodeThatInArray[i] = "0";
                }else{
                    cout << "Error: the average is " << average << " and the number is " << oCodeThatInArray[number] << endl;
                    break;
                }
            }



            string NWModeCodeThatInArray[26];
            int i2 = 0;
            stringstream ssin2(NWModeOfCode);
            while (ssin2.good() && i2 < 26){
                ssin2 >> NWModeCodeThatInArray[i2];
                ++i2;
            }
            for(int y=0;y<26;y++){//last 4 data code is combined with  NN aka 0 and WW aka 1 anyway, so it's fine to be converted again
                //												cout << "\n" + NWModeOfCode + "\n"; //DBG
                replace_mod(NWModeCodeThatInArray[y], "NN", "0");
                replace_mod(NWModeCodeThatInArray[y], "NW", "F");
                replace_mod(NWModeCodeThatInArray[y], "WW", "1");
                replace_mod(NWModeCodeThatInArray[y], "WN", "H");
            }
            //												cout << NWModeOfCode; //DBG
            cout << "\n----\n";


            cout  << "Static ternary code of it is ";
            for (int y = 0; y < 26; y++) {

                cout << NWModeCodeThatInArray[y];
            }
            //print a space and oDataCodeThatInArray aka data code
            //												cout << " ";
            for (i=0; i<4; i++) {// print data code
                cout << oDataCodeThatInArray[i];
            }
            cout << "\n                             AAAAAAAAAADDDD";
            cout << "\n----\nmain menu\n----\n";
            goto startplace;								}


        case 7 :{//general //TODO
            //ask user to input a string
            cout << "Please input a general demodulated code from URH: \n>";
            string oCodeGeneral;
            cin >> oCodeGeneral;
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

            oCodeGeneral = replaceMeaningless0WithSpace(oCodeGeneral);

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
            for (int i = 0; i < oCodeGeneral.length(); i++) {
                if (oCodeGeneral[i] == ' ') {
                    spaceCount++;
                }
//																spaceCount = spaceCount + 1;
            }


            string oCodeThatInArray[spaceCount];
            //put the string which seperated by spaces into oCodeThatInArray
            int i = 0;
            stringstream ssin(oCodeGeneral);
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
            string NWModeOfCode = "";

            //check the array one by one and if one of the number is bigger than the average, then add W into NWModeOfCode, if not, add N into NWModeOfCode
            for (int number = 0; number < spaceCount; number++) {
                if (stoi(oCodeThatInArray[number]) > average) {
                    NWModeOfCode = NWModeOfCode +"W";
                }else{
                    NWModeOfCode = NWModeOfCode + "N";
                }
            }
			cout << "NWModeOfGeneralCode:";
			cout << NWModeOfCode;
			cout << "\n";

												cout << "\n----\nmain menu\n----\n";
												goto startplace;
        }
        case 8 :{//for test
            string NWModeOfCode;
            NWModeOfCode = "WNNNNWNWWWNWWNNW";
            //												string dataStr;
            //												dataStr = NWModeOfCode;


            unsigned long n = NWModeOfCode.length();//separate NWModeOfCode per 2 char by space
            while(n-2 > 0)
            {
                n = n - 2;
                NWModeOfCode.insert(n," ");
            }


            string NWModeCodeThatInArray[26];
            int i2 = 0;
            stringstream ssin2(NWModeOfCode);
            while (ssin2.good() && i2 < 26){
                ssin2 >> NWModeCodeThatInArray[i2];
                ++i2;
            }
            for(int y=0;y<26;y++){
                //												cout << "\n" + NWModeOfCode + "\n"; //DBG
                replace_mod(NWModeCodeThatInArray[y], "NN", "0");
                replace_mod(NWModeCodeThatInArray[y], "NW", "F");
                replace_mod(NWModeCodeThatInArray[y], "WW", "1");
                replace_mod(NWModeCodeThatInArray[y], "WN", "H");
            }
            //												cout << NWModeOfCode; //DBG
            cout << "\n----\n";
            for (int y = 0; y < 26; y++) {
                cout  << NWModeCodeThatInArray[y];
            }

            //check if there's any "N" or "W" in NWMCodeThatInArray
            for (int y = 0; y < 26; y++) {
                if (NWModeCodeThatInArray[y] == "N" || NWModeCodeThatInArray[y] == "W") {
                    cout << "\nError: Maybe Try 2262, if the error still exist, maybe share the raw files with dev."  << endl;
                    break;
                }
            }

            cout << "----\nmain menu\n----\n";
        }
        case 99:{
            break;
        }
    }
}

