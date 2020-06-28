#include<iostream>
using namespace std;

int main(){
    int N , K, open, close, boxNum;
    cin >> N >> K;

    int A[N+1];
    for(int i=0;i<=N;++i) A[i] = 0; // initially all closed

    close = N;

    string st;
    while(K--){
        cin >> st;
        cout << st <<  endl;

    }




    return 0;
}
