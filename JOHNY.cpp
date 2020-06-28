// Algorithm time complexity: O(N)

#include<iostream>


using namespace std;


int main(){
    int T, N, K;
    cin >> T;

    while(T--){
        cin >> N;
        long long int A[N];
        for(int i=0;i<N;++i)
            cin >> A[i];
        // take position of johny song
        cin >> K;

        int counter = 0;

        //figure out the #.of songs that have length less than or equal to johny song length
        for(int i=0;i<N;++i)
            if(A[i]<=A[K-1]) ++counter;

        cout << counter << endl;


    }

    return 0;
}
