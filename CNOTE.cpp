#include<iostream>

using namespace std;


int main(){
    int T, X,Y, K,N;
    cin >> T;

    int pages, price;

    while(T--){
            cin >> X >> Y >> K >> N;
            int luckyStatus = 0;
            while(N--){
                cin >> pages >> price;
                if(price<=K){
                    if(pages >=(X-Y)) luckyStatus = 1;
                }

            }

            cout << ((luckyStatus)?"LuckyChef":"UnluckyChef") << endl;


    }
    return 0;
}
