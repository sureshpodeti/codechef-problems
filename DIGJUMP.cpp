#include<iostream>
using namespace std;

int main(){
    string st;
    cin >> st;

    int N = st.length();

    // write values into an array
    int A[N];
    for(int i=0;i<N;++i)
        A[i] = st[i] - 48;

    int C[10];
    for(int i=0;i<10;++i) C[i] = -1;

    for(int i=0;i<N;++i)
        if(C[A[i]] == -1) C[A[i]] = i;


    //define array B that stores no.of jumps needed to reach
    //to that location from the first
    int B[N];

    //initialize first entry to 0
    B[0] = 0;

    for(int i=1;i<N;++i){
            B[i] = B[i-1]+1;
            if(C[A[i]]<i)
                B[i] = min(B[i], B[C[A[i]]]+1);

    }


    cout << B[N-1] << endl;

    return 0;
}
