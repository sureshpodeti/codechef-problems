
#include<iostream>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        int A[N], B[N];
        for(int i=0;i<N;++i)
            cin >> A[i];

        for(int i=0;i<N;++i)
            cin >> B[i];

        int sumARight[N], sumBRight[N],sumALeft[N], sumBLeft[N];
        sumARight[0] = A[0];
        sumBRight[0] = B[0];
        for(int i=1;i<N;++i){
            sumARight[i] = sumARight[i-1]+A[i];
            sumBRight[i] = sumBRight[i-1]+B[i];
        }

        sumALeft[N-1] = A[N-1];
        sumBLeft[N-1] = B[N-1];

        for(int i=N-2;i>=0;--i){
             sumALeft[i] = sumALeft[i+1]+A[i];
             sumBLeft[i] = sumBLeft[i+1]+B[i];
        }

        //shifting before first day
        int ans = sumBLeft[0];


        //shifting on following days
        for(int i=0;i<N;++i){
            // shifting on ith day
            ans = max(ans, (sumBLeft[i]-B[i] + sumARight[i]));
        }

        //shifting after the last day
        ans = max(ans, sumARight[N-1]);

        cout << ans << endl;
    }


    return 0;
}
