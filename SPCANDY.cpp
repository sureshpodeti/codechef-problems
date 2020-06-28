#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    long long int N, K, student, teacher;
    while(T--){
        cin >> N >> K;

        // if K=0;
        if(K==0) cout << 0 <<" " << N << endl;
        else
            cout << N/K << " "<< N%K << endl;
    }
    return 0;
}
