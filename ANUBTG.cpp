#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        int A[N];
        for(int i=0;i<N;++i) cin >> A[i];

        //sort the array
        sort(A, A+N);

        int i=N-1, j=N-2;
        int totalPay = 0;
        while(i>=0&&j>=0){
            totalPay += A[i] +A[j];
            i -= 4;
            j -= 4;
        }
        cout << totalPay <<endl;
    }
    return 0;
}
