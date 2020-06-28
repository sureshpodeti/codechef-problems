
#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    long long int L, R;
    while(T--){
        cin >> L >> R;

        long long int counter = 0;

        for(int i=L;i<=R;++i){
                // get the No.of co-primes for each i, write into coprimes
                //i % coprimes == 0 , then increment counter


        }
        cout << counter << endl;
    }

    return 0;
}
