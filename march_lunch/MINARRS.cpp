#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        long long int A[N];
        string byteString[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
            byteString[i] = bitset<64>(A[i]).to_string();
        }

        int oneCount[64], zeroCount[64];

        //initialize
        for(int i=0;i<64;++i){
            oneCount[i] = 0;
            zeroCount[i] = 0;
        }




        for(int i=0;i<N;++i){
            for(int j=0;j<64;++j){
                if(byteString[i][j]=='1')
                    oneCount[j]++;
                else zeroCount[j]++;
            }
        }



        //final array
        int finalArray[64];
        for(int i=0;i<64;++i){
            finalArray[i] = (oneCount[i]>zeroCount[i])?1:0;
        }


        long long int num = 0;
        for(int i=0;i<64;++i){
            num += finalArray[i] *pow(2, 63-i);
        }


        long long ans = 0;

        for(int i=0;i<N;++i)
                ans += num^A[i];



        cout << ans << endl;



    }



    return 0;
}
