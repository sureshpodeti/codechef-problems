#include<iostream>

using namespace std;


int main(){
    int T;
    cin >> T;


    string st;

    while(T--){
        cin >> st;

        // get tockens of length 3 check if matches any of 010 or 101
        int good = 0;
        for(int i=0;i<st.length();++i){
            string s = st.substr(i,3);
            cout << s << endl;
            if(s == "010" || s=="101"){
                good = 1;
                break;
            }

        }

        cout << ((good)?"Good":"Bad") << endl;

    }
    return 0;
}
