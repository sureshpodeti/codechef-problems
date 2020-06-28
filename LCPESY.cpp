
#include<iostream>

using namespace std;
#define SIZE 68
int A[SIZE], B[SIZE];
int main(){
    int T;
    cin >> T;

    string S1, S2;
    while(T--){
        cin >> S1 >> S2;

        //initialize A, B
        for(int i=0;i<SIZE;++i){
            A[i] = 0;
            B[i] = 0;
        }


        for(int i=0;i<S1.length(); ++i)
            A[S1[i]-48]++;

        for(int i=0;i<S2.length();++i)
            B[S2[i]-48]++;

        long long result = 0;
        for(int i=0;i<SIZE;++i)
            result += min(A[i], B[i]);

        cout << result << endl;


    }


    return 0;
}
