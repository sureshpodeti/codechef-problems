#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int T, N,M;
    cin >> T;

    while(T--){
        cin >> N >> M;

        int P[M];
        for(int i=0;i<M;++i)
            cin >> P[i];

        //sort the array P
        sort(P, P+M);


        for(int i=0;i<N;++i)
                cout << max(abs(i- P[0]), abs(i- P[M-1])) << " ";
        cout << endl;


    }

    return 0;
}
