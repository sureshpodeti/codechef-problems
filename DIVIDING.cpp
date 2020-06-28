#include<iostream>
using namespace std;

int main(){
    long long int N;
    cin >> N;

    long long int A[N];
    for(int i=0;i<N;++i)
        cin >> A[i];

    //compute sum
    long long int S=0;
    for(int i=0;i<N;++i)
        S += A[i];

    cout << (((N*(N+1)/2)==S)?"YES":"NO") << endl;
    return 0;
}
