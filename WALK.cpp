#include<iostream>

using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        int A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        long long int ans = A[N-1];
        for(int i=N-2;i>=0;--i){
                //update answer
                ans = (A[i]>(ans+1))?A[i]:(ans+1);
        }

        cout <<  ans << endl;


    }


    return 0;
}
