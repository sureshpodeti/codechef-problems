#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


int main(){
    int T, N, K;
    cin >> T;

    while(T--){
        cin >> N >> K;
        int weight[N];
        for(int i=0;i<N;++i)
            cin >> weight[i];
        //sort the array
        sort(weight, weight+N);

        // K groups could be from any side left or right side of the array


        // compute the total sum
        long long int S = 0;
        for(int i=0;i<N;++i)
            S += weight[i];


        // compute the sum of first K elements
        long long int firstK=0;
        for(int i=0;i<K;++i)
            firstK += weight[i];

        //compute the sum of last k elements
        long long int lastK = 0;
        for(int i=N-1;i>=N-K;--i)
            lastK += weight[i];

        cout << max(abs(2*firstK-S), abs(2*lastK-S))<< endl;

    }


    return 0;
}
