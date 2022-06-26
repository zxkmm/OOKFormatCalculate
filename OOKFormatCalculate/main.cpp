//
//  main.cpp
//  OOKFormatCalculate
//
//  Created by zxkmm on 2022/6/26.
//

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

string DEC2anyBS(int n,int radix)    //n for decimal，radix for BS
{
    string ans="";
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
sub-stringwhich is needed 2 be replaced: old_value
to: new_value
*/
string& replace_all(string& src, const string& old_value, const string& new_value) {
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
    cout << "OOKFC running\n----\nPress 1 for 4Bits 1527 code to 2Bits\ne.g.H0FF1FHFHH>>10000101110110011010\n----\nPress 2 for 2Bits 1527 code to 4Bits\ne.g. 10000101110110011010>>H0FF1FHFHH\n----\nYour choice:";
    int select;
    cin >> select;
    if (select==1){
        string i1527B4;
        cout << "OOKFC running\nInput 4Bits 1527 code(Without data code):";
        cin >> i1527B4;
        replace_all(i1527B4, "1", "3");
        replace_all(i1527B4, "F", "1");
        replace_all(i1527B4, "H", "2");
        cout  <<"2Bit of it is " + DEC2anyBS(anyBS2DEC(i1527B4, 4), 2) << "\n";
    }else{
        string i1527B2;
        cout << "Input 2Bits 1527 code(Without data code):";
        cin >> i1527B2;
        string o1527B4 = DEC2anyBS(anyBS2DEC(i1527B2, 2), 4);
        replace_all(o1527B4, "1", "F");
        replace_all(o1527B4, "3", "1");
        replace_all(o1527B4, "2", "H");
        cout  << "4Bit of it is " + o1527B4 << "\n";
    }
    
    

}
