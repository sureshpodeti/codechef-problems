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

        int B[N];

        //first one element of A, B are same
        B[0] = A[0];
        for(int i=1;i<N;++i){
            if(B[i-1]>A[i]) {
                // speed will at maximum
                B[i] = A[i];
            }else{
                // speed must decrease
                B[i] = B[i-1];

            }
        }


        // count elements that are equal in A,B
        int counter = 1;
        for(int i=1;i<N;++i)
            if(A[i]==B[i]) ++ counter;

        cout << counter << endl;
    }

    return 0;
}
