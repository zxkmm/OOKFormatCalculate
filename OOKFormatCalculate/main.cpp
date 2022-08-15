//
//  main.cpp
//  OOKFormatCalculate
//
//  Created by zxkmm on 2022/6/26.
//  I wrote trash....

#include <iostream>
#include <string>
#include <algorithm>
//#include <sstream>

using namespace std;

int anyBS2DEC(string s,int radix)    //s for incoming string, radix for it's BS
{
				int ans=0;
				for(int i=0;i<s.size();i++)
				{
								char t=s[i];
								if(t>='0'&&t<='9') ans=ans*radix+t-'0';
								else ans=ans*radix+t-'a'+10;
				}
				return ans;
}

string DEC2anyBS(int n,int radix){    //n for incoming numbers(int)，radix for it's BS

				string ans = "";
				do{
								int t=n%radix;
								if(t>=0&&t<=9)    ans+=t+'0';
								else ans+=t-10+'a';
								n/=radix;
				}while(n!=0);    //anti-0-expection
				reverse(ans.begin(),ans.end());
				return ans;
}

/*
	manul string: src
	sub-string which is needed 2 be replaced: old_value
	to: new_value
	*/
string& replace_mod(string& src, const string& old_value, const string& new_value) {
				// Anti-loooooooop
				for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
								if ((pos = src.find(old_value, pos)) != string::npos) {
												src.replace(pos, old_value.length(), new_value);
								}
								else break;
				}
				return src;
}




string makeShortestGrain(int numOfGrain){//the number of meaningless "0" in inut data，e.g. 4，then make a string with content "1111"
				string stringGrain = "1";
				for ( ; numOfGrain > 1; numOfGrain --) {
								//make grain string, e.g. when grainNum=4 ,then make stringGrain = "1111".
								stringGrain = stringGrain + "1" ;
				}
				//    string stringGrain;
				//    stringGrain = to_string(stringGrainInInt);
				return stringGrain;
}

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
}

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
}

string replaceMeaningless0withA(string i2262URH){
				for (int numbersOf0 = 100; numbersOf0 > 0; numbersOf0 --) {
								replace_mod(i2262URH, makeStringFullOf0withANumber(numbersOf0), "A");
				}
				return i2262URH;
}

string putTheCodeIntoArray(string iCodeThatAlreadySeperatedByA){
				string oCodeThatBecameArray[1000002];
				//				getline(cin, w);                          //	string which already been seperated by A
				int s = 0;
				
				for (int i = 0; i < iCodeThatAlreadySeperatedByA.length(); i++) { //Seperate
								if (iCodeThatAlreadySeperatedByA[i] == 'A') {                 //A as seperate identify
												s++;
												continue;
								}
								oCodeThatBecameArray[s] += iCodeThatAlreadySeperatedByA[i];                      //put into array
				}
				
//				for(int i = 0;i<=s;i++){    //输出分割好的字符串
//								cout<<oCodeThatBecameArray[i]<<endl;
//				}
				return oCodeThatBecameArray;
}


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
				cout << "OOKFC running\n----\nPress 1 for 4Bits 1527 code to 2Bits\ne.g.H0FF1FHFHH>>10000101110110011010\n----\nPress 2 for 2Bits 1527 code to 4Bits\ne.g. 10000101110110011010>>H0FF1FHFHH\n----\nPress 3 for 3Bits 2262 code to demodulated wave form\n(Kinda useless but i just put it here in case if someone really need it :))\ne.g. 00100F0F0F00>>NNNNWWNNNNNWNNNWNNNWNNNNS\n----\nPress 4 for demodulated wave form to 3Bits 2262 code\n e.g. NNNNWWNNNNNWNNNWNNNWNNNNS>>00100F0F0F00\n----\nPress 6 to exit\n";
startplce:
				cout << "Your choice:\n>";
				int select;
				cin >> select;
				switch(select){
								case 1 : {//1527 base4 to base2
												string i1527B4;
												string o1527B2;
												cout << "OOKFC running\nInput 4Bits 1527 code(Without data code):\n>";
												cin >> i1527B4;
												replace_mod(i1527B4, "1", "3");
												replace_mod(i1527B4, "F", "1");
												replace_mod(i1527B4, "H", "2");
												o1527B2 = DEC2anyBS(anyBS2DEC(i1527B4, 4), 2);
//												cout  <<"2Bit of it is " + DEC2anyBS(anyBS2DEC(i1527B4, 4), 2) << "\n";
												
												if (size(o1527B2)<20){//In case if the 4 base (4Bit) data started with 0;
																for (unsigned long length = size(i1527B4); length < 19; length ++) {
																				o1527B2 = "0" + o1527B2;
																}
												}
												//            break;
												cout << o1527B2 + "\nbacking to main menu::\n----\nmain menu\n----\n";
												goto startplce;
								}
								case 2 : { //1527 Base 2 to Base 4
												string i1527B2;
												cout << "Input 2Bits 1527 code(Without data code):\n>";
												cin >> i1527B2;
												string o1527B4 = DEC2anyBS(anyBS2DEC(i1527B2, 2), 4);
												replace_mod(o1527B4, "1", "F");
												replace_mod(o1527B4, "3", "1");
												replace_mod(o1527B4, "2", "H");
												cout  << "4Bit of it is " + o1527B4 << "\n";
												//            break;
												cout << "backing to main menu::\n----\nmain menu\n----\n";
												goto startplce;
								}
								case 3 : { //2262 waveform to Base 3
												string i2262WS;
												cout << "Input demodulated wave form of 2262 (WITHOUT sync code):\ne.g.\n";
												//            cout << "  ─   ─   ──   ──   ─   ──   ─  \n";
												cout << " ┌┐ ┌┐ ┌──┐ ┌──┐ ┌┐ ┌──┐ ┌┐ \n";
												cout << " ││ ││ │  │ │  │ ││ │  │ ││ \n";
												cout << "─┘└─┘└─┘  └─┘  └─┘└─┘  └─┘└─\n";
												cout << " N  N    W    W   N   W   S  \n>";
												cin >> i2262WS;
												replace_mod(i2262WS, "NN", "0");
												replace_mod(i2262WS, "NW", "F");
												replace_mod(i2262WS, "WW", "1");
												cout << i2262WS;
												cout  << "3Bit of it is " + i2262WS << "\n";
												//            break;
												cout << "backing to main menu::\n----\nmain menu\n----\n";
												goto startplce;
								}
								case 4 : {//2262 Base 3 to waveform
												string i2262B3;
												cout << "Input 3Bits 2262 code(Without data code):\n>";
												cin >> i2262B3;
												replace_mod(i2262B3, "0", "NN");
												replace_mod(i2262B3, "1", "WW");
												replace_mod(i2262B3, "F", "NW");
												cout  << "demodulated wave form of it is " + i2262B3 + "S" + "\ne.g." << "\n";
												cout << " N  N   W    W   N    W  S  \n";
												cout << " ┌┐ ┌┐ ┌──┐ ┌──┐ ┌┐ ┌──┐ ┌┐ \n";
												cout << " ││ ││ │  │ │  │ ││ │  │ ││ \n";
												cout << "─┘└─┘└─┘  └─┘  └─┘└─┘  └─┘└─\n";
												//            break;
												cout << "backing to main menu::\n----\nmain menu\n----\n";
												goto startplce;
								}
								case 5 :{//2262 URH demodulated data to Base3
												//TODO
												/**
													流程：
													1:找到高电平的无意义的1的个数（肯定是大于2且大于低电平）
													2.找到低电平的无意义的1的个数（肯定是小于高电平）
													3.从左边开始查找``find()``，找到一个1(高电平)，再往左找，｜如果是低电平（0），就在数组1中给[0]值0，然后继续查找。
																																																				   ｜如果是高电平（1），就在数组1中给[0]值1，然后继续找。
													4.在数组1中查找，如果可以的话直接用替换法，先把11替换成a，再把10替换成b等等，反正要让顺序不要出现矛盾（或者两两放到数组中再操作更稳妥，包括可以把上面那个case一起替换了）
													如果不可以用替换法，就用第三步的方法。
													*/
												string i2262URH;
												cin >> i2262URH;
												
												
								}
								case 6 :{
												break;
								}
								case 7 :{//for test
												cout << putTheCodeIntoArray("1A1A111A111A1A1A1A111A1A1A1A1A1A1A1A1A111A111A1A1A1A1A1A1A1A") + "\n";
												
								}
				}
}
