#include<iostream>
#define MAX 100
using namespace std;

int A[MAX];

int fib(int N){
    if(A[N]==-1){
            if(N<2) A[N] = N;
            else A[N] = fib(N-1) + fib(N-2);
    }

    return A[N];

}

int main(){
    int N;
    cin >> N;


    //initialize the array with all -1
    for(int i=0;i<=N;++i) A[i] = -1;

    cout << fib(N) << endl;


    return 0;
}
