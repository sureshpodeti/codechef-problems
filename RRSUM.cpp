#include<iostream>

using namespace std;

int main(){
    long long int N, M, q;
    cin >> N >> M;

    for(int i=0;i<M;++i){
        cin >> q;
        long long int ans = 0;
        if(q<N+2 || q>3*N) ans = 0;
        else if(q<=2*N+1) ans = q-N-1;
        else ans = 3*N+1 - q;

        cout << ans << endl;
    }

    return 0;
}
