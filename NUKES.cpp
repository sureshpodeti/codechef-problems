#include<iostream>
using namespace std;

int main(){
    long long int A;
    int N, K;

    cin >> A >> N >> K;

    long long int inp = A, out1, out2;
    for(int i=0;i<K;++i){
        out1 = inp/(N+1);
        out2 = out1*N;

        cout << (inp - out1 - out2) << " ";
        //update inp
        inp = out1;
    }
    cout << endl;

    return 0;
}
