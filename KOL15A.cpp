#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    string st;
    while(T--){
        cin >> st;

        int ans = 0;

        for(int i=0;i<st.length();++i){
            if(st[i]>=48 && st[i]<=57) ans += (st[i] - 48);
        }
        cout << ans << endl;

    }


    return 0;
}
