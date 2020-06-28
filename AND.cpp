
#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin >> N;

    long long int a, finalBits[64];

    //initialize finalBits
    for(int i=0;i<64;++i) finalBits[i] = 0;

    // count no.of 1's possible in each bytes positions
    for(int i=0;i<N;++i){
        cin >> a;
        //convert input number to byte string
        string st = bitset<64>(a).to_string();
        for(int i=0;i<64;++i){
            if(st[i]=='1') finalBits[i]++;
        }
    }


    long long int ans = 0;

    for(int i=0;i<64;++i){
        int comp = (finalBits[i]*(finalBits[i]-1))/2; // n*(n-1)/2 total pairs
        ans += comp*pow(2, 63-i);
    }


    cout << ans << endl;

    return 0;
}
