
#include<iostream>

using namespace std;


int main(){
    int T, N;
    cin >> T;

    long long int K;
    while(T--){
            cin >> N >> K;
            long long int A[N], B[N];

            for(int i=0;i<N;++i) cin >> A[i];

            for(int i=0;i<N;++i) cin >> B[i];

            long long int res = 0; //will store the final result (maximum profit)

            for(int i=0;i<N;++i){
                long long int r = K/A[i];
                res = max(res, r*B[i]);
            }
            cout << res << endl;


    }

    return 0;
}
