#include<iostream>


int A[1000];
using namespace std;
int fib(int N){
    if(N==0 || N==1) return N;
    return fib(N-1) + fib(N-2);
}

int fibDp(int N){

}


int main(){
    int N;
    cin >> N;

    //initialize the array
    A[0] = 0;
    A[1] = 1;


    cout << fib(N, A) << endl;

    return 0;
}
