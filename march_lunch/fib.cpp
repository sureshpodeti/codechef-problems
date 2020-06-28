
#include<iostream>

int A[1000];
using namespace std;

long long int fib(int A[], int N){

    if(A[N]!=-1)
        return A[N];
    else{
        A[N] = fib(A,N-1) + fib(A, N-2);
        return A[N];
    }
}
int main(){
    int N;
    cin >> N;

    //initialize the array A
    for(int i=0;i<1000;++i) A[i] = -1;
    A[0] = 0;
    A[1] = 1;


    cout << fib(A, N) << endl;


    return 0;
}
