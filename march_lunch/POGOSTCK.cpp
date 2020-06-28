
#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int T, N, K;
    cin >> T;

    while(T--){
        cin >> N >> K;
        int A[N];

        for(int i=0;i<N;++i)
            cin >> A[i];


        long long int ans = INT_MIN;

        for(int i=0;i<N;++i){
            long long x = A[i];
            for(int j=i+K;j<N;j=j+K){
                x += A[j];
            }
            ans = max(ans, x);
        }

        cout << ans << endl;
    }

    return 0;
}
