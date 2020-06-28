
#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    string st;
    while(T--){
        cin >> st;
        int n = st.length();

        int sum = 0;
        for(int i=0;i<n;++i)
            sum += st[i] - '0';
        cout << sum << endl;

    }

    return 0;
}
