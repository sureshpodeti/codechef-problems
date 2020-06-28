#include<iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    int A[N];
    for(int i=0;i<N;++i) cin >> A[i];

    int maxLength = 0;
    if(N==1){
        maxLength = 0;
    }else{
        int B[N];
        //initialiaze the first element
        B[0] = (A[0]==0)?0:1;

        maxLength = B[0];
        for(int i=1;i<N;++i){
            B[i] = (A[i]==0)?0:(B[i-1]+1);
            //update the maxLength
            maxLength = max(maxLength, B[i]);
        }
    }
    cout << maxLength << endl;
    return 0;
}
