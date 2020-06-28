
#include<iostream>
using namespace std;

int main(){
    int T, N;
    cin >> T;

    char a, b, c;
    while(T--){
        cin >> N;
        if(N>360)
            cout << "n n n" << endl;
        else{
            // exactly N equal pieces
            if(360%N==0) a = 'y';
            else a = 'n';



            // exaclty N pieces, such that no two of them are equal
            if(360/N>=(N-1)) c = 'y';
            else c = 'n';

            // exactly N pieces
            if(a == 'y'  || c == 'y') b = 'y';
            else b = 'n';


            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}
