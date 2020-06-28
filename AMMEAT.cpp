#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    long long int M;

    while(T--){
        cin >> N >> M;
        long long int P[N];

        for(int i=0;i<N;++i)
            cin >> P[i];

        //sort the array P
        sort(P, P+N);

        long long int S[N+1];
        S[0] = 0;
        for(int i=1;i<=N;++i)
            S[i] = S[i-1] + P[i-1];

        int result = -1;
        for(int i=1;i<=N;++i){
                if(S[N] - S[N-i]>=M){
                    result = i;
                    break;
                }

        }

        cout << result << endl;


    }

    return 0;
}
