#include<iostream>
#include<deque>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;

        if(N==1){
            cout << 1 << endl;
        }else if(N==2){
            cout << 5 << endl;
        }else{

            ll prev = 1;
            for(int i=3;i<=N;++i)
                prev = prev*(i+1);
            cout << ((6*prev - 1)%MOD) << endl;


        }

    }



    return 0;
}
