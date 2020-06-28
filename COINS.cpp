#include<iostream>
#define SIZE 1000000001
typedef long long int LLI;
using namespace std;



LLI byteLand(LLI *A, LLI N){
    if(A[N]==-1){
        if(N<12) A[N] = N;
        else
            A[N] = max(byteLand(A, N/2) + byteLand(A, N/3) + byteLand(A, N/4), N);
    }

    return A[N];


}
int main(){
    LLI N;
    LLI A[SIZE];

    for(LLI i=0;i<SIZE;++i) A[i] = -1;

    while(cin >> N){
        cout << byteLand(A, N) << endl;
    }


    return 0;
}
