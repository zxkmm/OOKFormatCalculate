//
//  main.cpp
//  OOKFormatCalculate
//
//  Created by zxkmm on 2022/6/26.
//  I wrote trash....

#include <iostream>
#include <string>
#include <algorithm>

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

string DEC2anyBS(int n,int radix)    //n for incoming numbers(int)，radix for it's BS
{
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
				cout << "OOKFC running\n----\nPress 1 for 4Bits 1527 code to 2Bits\ne.g.H0FF1FHFHH>>10000101110110011010\n----\nPress 2 for 2Bits 1527 code to 4Bits\ne.g. 10000101110110011010>>H0FF1FHFHH\n----\nPress 3 for 3Bits 2262 code to demodulated wave form\n(Kinda useless but i just put it here in case if someone really need it :))\ne.g. 00100F0F0F00>>NNNNWWNNNNNWNNNWNNNWNNNNS\n----\nPress 4 for demodulated wave form to 3Bits 2262 code\n e.g. NNNNWWNNNNNWNNNWNNNWNNNNS>>00100F0F0F00\n----\nPress 5 to exit\n";
startplce:
				cout << "Your choice:\n>";
				int select;
				cin >> select;
				switch(select){
								case 1 : {
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
								case 2 : {
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
								case 3 : {
												string i2262WS;
												cout << "Input demodulated wave form of 2262 (WithOUT sync code):\ne.g.\n";
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
								case 4 : {
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
								case 5 :{
												//TODO
								}
								case 6 :{
												break;
								}
								case 7 :{//test
												string test1 = "0000FH01HH";
												replace_mod(test1, "1", "3");
												replace_mod(test1, "F", "1");
												replace_mod(test1, "H", "2");
												cout << test1;
												cout << "\n";
												cout << anyBS2DEC(test1, 4);
												cout << "\n" ;
												cout << DEC2anyBS(anyBS2DEC(test1, 4), 2);
												cout << "\n";
												
								}
				}
}
