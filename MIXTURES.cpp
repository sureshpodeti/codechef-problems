
#include<iostream>
#define ll long long int
using namespace std;

int main(){
    ll T, N;
    cin >> T;

    while(T--){
        cin >> N;

        int A[N];
        for(int i=0;i<N;++i)
            cin >> A[i];

        int B[N];
        for(int i=0;i<N;++i)
            B[i] = A[i];

        ll smoke1 = 0, smoke2=0, newValue;

        ll a = A[0];

        for(int i=0;i<N-1;++i){
            int j=i+1;

            smoke1 += A[i]*A[j];
            newValue = (A[i] + A[j])%100;

            A[i] = A[j] = newValue;
        }



         for(int i=N-1;i>=1;--i){
            int j=i-1;

            smoke2 += B[i]*B[j];
            newValue = (B[i] + B[j])%100;

            B[i] = B[j] = newValue;
        }

        if(N==1)
            cout << a << endl;
        else
            cout << ((smoke1>smoke2)?smoke2:smoke1) << endl;

    }
    return 0;
}
