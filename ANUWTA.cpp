#include<iostream>

using namespace std;

int main(){
    long long int T,N;
    cin >> T;


    while(T--){
            cin >> N;
            cout << (N+(N*(N+1)/2)) << endl;
    }

    return 0;
}
