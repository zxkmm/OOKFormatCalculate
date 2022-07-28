//
//  main.cpp
//  OOKFormatCalculate
//
//  Created by zxkmm on 2022/6/26.
//  I wrote trash....

#include <iostream>
#include <string>

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

int main(){
    cout << "OOKFC running\n----\nPress 1 for 4Bits 1527 code to 2Bits\ne.g.H0FF1FHFHH>>10000101110110011010\n----\nPress 2 for 2Bits 1527 code to 4Bits\ne.g. 10000101110110011010>>H0FF1FHFHH\n----\nPress 3 for 3Bits 2262 code to demodulated wave form\n(Kinda useless but i just put it here in case if someone really need it :))\ne.g. 00100F0F0F00>>NNNNWWNNNNNWNNNWNNNWNNNNS\n----\nPress 4 for demodulated wave form to 3Bits 2262 code\n e.g. NNNNWWNNNNNWNNNWNNNWNNNNS>>00100F0F0F00\n----\nPress 5 to exit\n";
    startplce:
    cout << "Your choice:\n>";
    int select;
    cin >> select;
    switch(select){
        case 1 : {
            string i1527B4;
            cout << "OOKFC running\nInput 4Bits 1527 code(Without data code):\n>";
            cin >> i1527B4;
            replace_mod(i1527B4, "1", "3");
            replace_mod(i1527B4, "F", "1");
            replace_mod(i1527B4, "H", "2");
            cout  <<"2Bit of it is " + DEC2anyBS(anyBS2DEC(i1527B4, 4), 2) << "\n";
//            break;
            cout << "backing to main menu::\n----\nmain menu\n----\n";
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
            cout << " ┌─┐ ┌─┐ ┌──┐ ┌──┐ ┌─┐ ┌──┐ ┌─┐ \n";
            cout << " │ │ │ │ │  │ │  │ │ │ │  │ │ │ \n";
            cout << "─┘ └─┘ └─┘  └─┘  └─┘ └─┘  └─┘ └─\n";
            cout << "  N   N   W    W    N   W    S  \n>";
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
            cout << "  N   N   W    W    N   W    S  \n";
            cout << " ┌─┐ ┌─┐ ┌──┐ ┌──┐ ┌─┐ ┌──┐ ┌─┐ \n";
            cout << " │ │ │ │ │  │ │  │ │ │ │  │ │ │ \n";
            cout << "─┘ └─┘ └─┘  └─┘  └─┘ └─┘  └─┘ └─\n";
//            break;
            cout << "backing to main menu::\n----\nmain menu\n----\n";
            goto startplce;
        }
        case 5 :{
            break;
        }
    }
}
