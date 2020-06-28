#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int T;
    double Ds, Dt, D;
    cin >> T;

    while(T--){
        cin >> Ds >> Dt >> D;
        int diff = (D-Dt) - Ds;


        // diff could be negative, in that case distance is 0
        cout << setprecision(6)  << ((diff<=0)?abs(diff):diff)<< endl;
    }

    return 0;
}
