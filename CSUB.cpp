#include<iostream>

using namespace std;

int main(){
    int T, N;
    cin >> T;

    string st;
    while(T--){
        cin >> N;
        cin >>  st;

        // count the no.of 1's
        int ones = 0;
        for(int i=0;i<st.length();++i)
            if(st[i]=='1') ++ones;
        long long int ans =ones*(ones+1)/2;
        cout << ans << endl;

    }


    return 0;
}
