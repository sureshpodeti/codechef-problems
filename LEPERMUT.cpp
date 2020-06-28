#include<iostream>

using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        int A[N];
        for(int i=0;i<N;++i)
            cin >> A[i];


        // count the local inversions
        int locals = 0;
        for(int i=1;i<N;++i)
            if(A[i-1]>A[i]) ++locals;

        // count the total inversions
        int totalInv = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<i;++j)
                if(A[j] > A[i]) ++ totalInv;

        cout << ((locals==totalInv)? "YES": "NO") << endl;



    }

    return 0;
}
