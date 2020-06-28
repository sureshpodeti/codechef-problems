#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;

        long long int S[N];
        for(int i=0;i<N;++i)
            cin >> S[i];

        // sort the array
        sort(S, S+N);
        long long int diff = INT_MAX;
        for(int i=0;i<N-1;++i)
            diff = min(diff, S[i+1]-S[i]);

        cout << diff << endl;


    }




    return 0;
}
