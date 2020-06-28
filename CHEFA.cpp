#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        long long int A[N];
        for(int i=0;i<N;++i) cin >> A[i];

        //sort the array
        sort(A, A+N);

        long long ans = 0;
        for(int i=N-1;i>=0;i-=2)
            ans += A[i];

        cout << ans << endl;
    }

    return 0;
}
