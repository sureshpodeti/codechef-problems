#include<iostream>


using namespace std;

int main(){
    int T, N,K,V;
    cin >> T;

    while(T--){
        cin >> N >> K >> V;
        int a, S=0;
        for(int i=0;i<N;++i){
            cin >> a;
            S += a;
        }

        int cal = (V*(N+K) - S);
        if(cal >0 && cal%K==0){
            cout << cal/K << endl;
        }else cout << -1 << endl;
    }


    return 0;
}
