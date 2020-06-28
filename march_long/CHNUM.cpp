#include<iostream>

using namespace std;


int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        long long int A[N];

        for(int i=0;i<N;++i) cin >> A[i];


        int neg, pos, zero;
        pos = neg = zero = 0;

        int maxCount = 0, minCount = N, tValue;

        for(int i=0;i<N;++i){
            if(A[i]==0) ++zero;
            else if(A[i]>0) ++pos;
            else ++neg;
        }

        if(neg>pos)
            neg += zero;
        else pos += zero;

        if(neg==0 || pos==0){
            cout << N << " " << N << endl;
        }else{
            if(neg>pos) cout << neg << " " << pos << endl;
            else cout << pos << " " << neg << endl;
        }


    }

    return 0;
}
