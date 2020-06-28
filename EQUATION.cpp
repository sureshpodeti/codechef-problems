
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int T, N, A, B, C;
    cin >> T;


    while(T--){
        cin >> N >> A >> B >> C;

       long long int ans = 0;
       for(int i=0;i<=A;++i){
        for(int j=0;j<=B;++j){
            if(N<(i+j)) break;
            ans += min(N - i - j, C)+1;
        }
       }

       cout << ans << endl;



    }

    return 0;
}
