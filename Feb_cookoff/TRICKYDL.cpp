#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int T;
    cin >> T;

    long long int A;
    int D1, D2=1;
    while(T--){
        cin >> A;

        int day= 1;
        while(1){

            long long profit = day*A - (pow(2,day) - 1);
            if(profit<0){
                    D1 = day -1;
                    break;
            }
            ++day;

        }

        // get the day that gives maximum profit
        long long int S=0;
        for(int i=1;i<=D1;++i){
            if(A-pow(2,(i-1))<=0){
                D2 = i-1;
                break;
            }
        }
        cout << D1 << " " << D2 << endl;

    }


    return 0;
}
