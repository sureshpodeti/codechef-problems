
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        long long int P[N];
        for(int i=0;i<N;++i) cin >> P[i];


        //sort the array P
        sort(P, P+N);

        long long int res=0;
        for(int i=1;i<N;++i)
            res += P[0]*P[i];

        cout << res << endl;
    }



    return 0;
}
