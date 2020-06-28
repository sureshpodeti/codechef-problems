#include<iostream>
typedef long long int LLI;

using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        int A[N];
        //counts no.of twos, and non-zero and non-ones
        int twos = 0, c=0;
        for(int i=0;i<N;++i){
            cin >> A[i];
            if(A[i]==2) ++ twos;
            if(A[i]>=2) ++c;

        }


        // total pairs
        LLI tPairs = c*(c-1)/2;

        cout << (tPairs-(twos*(twos-1)/2)) << endl;
    }

    return 0;
}
