#include<iostream>

using namespace std;

int main(){

    int T;
    cin >> T;

    string st;

    while(T--){
        cin >> st;

        //count number of 4's and 7's in the string
        long long int luckyDigits=0;
        for(int i=0;i<st.length();++i){
            if(st[i]=='4' || st[i]=='7') ++luckyDigits;
        }

        cout << (st.length() - luckyDigits) << endl;
    }
    return 0;
}
