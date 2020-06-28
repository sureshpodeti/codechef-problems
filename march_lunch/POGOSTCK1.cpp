
#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int T, N, K;
    cin >> T;

    while(T--){
        cin >> N >> K;
        long long int A[N];

        for(int i=0;i<N;++i)
            cin >> A[i];


        long long int B[N];

        // initialize the first element
        B[0] = A[0];

        long long int ans = B[0];

        for(int i=1;i<N;++i){
                B[i] = max(A[i], (i-K<0)?A[i]:B[i-K]+A[i]);
                ans = max(ans, B[i]);

        }

        cout << ans << endl;
    }

    return 0;
}

