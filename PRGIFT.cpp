
#include<iostream>
using namespace std;


int main(){
    int T,N, K;
    cin >> T;

    while(T--){
        cin >> N >> K;

        int A[N], B[N];
        for(int i=0;i<N;++i) cin >> A[i];

        int counter=0;
        for(int i=0;i<N;++i){
            if(A[i]%2==0) ++counter;
            B[i] = counter;
        }

        int flag = 0, j;
        for(int i=K-1;i<N;++i){
            j = i-K;
            int k = (j<0)?B[i]:B[i] - B[j];
            if(k == K){
                    flag = 1;
                    break;
            }
        }

        cout << ((flag)?"YES": "NO") << endl;
    }


    return 0;
}
