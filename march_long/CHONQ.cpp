
#include<iostream>

typedef long long int LLI;
using namespace std;

int main(){
   int T, N;
   LLI K;
   cin >> T;

   while(T--){
        cin >> N >> K;

        int A[N];
        for(int i=0;i<N;++i) cin >> A[i];

        // compute the array, assuming chef can stand at any location
        LLI B[N];
        B[N-1] = A[N-1];

        LLI a = 0;
        int z = 1;

        for(int i=N-2;i>=0;--i){
            a = 0;
            z = 1;
            for(int j=i;j<N;++j){
                    a += A[j]/z;
                    ++z;
                    if(a>K) break;
            }
            B[i] = a;
        }


        // get the first index
        int index=-1;
        for(int i=N-1;i>=0;--i){
                if(B[i]<=K){
                        index = i;
                }

        }
        cout << ((index==-1)? N+1: (index+1)) << endl;

   }


    return 0;
}
