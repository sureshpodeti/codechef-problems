#include<iostream>

using namespace std;


int main(){
    int T, G;
    cin >> T;

    int I,Q;
    long long int N;
    while(T--){
        cin >> G;

        while(G--){
            cin >> I >> N >> Q;

            // stores the final answer
            long long int ans;
            if(Q==1){
            // needed count of heads
            // count of heads depends on the initial configuration
                if(I==1){ // if initial configuration is all heads
                    ans = N/2;
                }
                else {
                    ans = N - (N/2);
                }
            }else{
            // needed count of tails
                if(I==1){
                    ans = N - (N/2);
                }else{
                    ans = N/2;
            }

        }

        cout << ans << endl;



        }


    }

    return 0;
}
