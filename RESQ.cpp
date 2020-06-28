#include<iostream>
#include<vector>
using namespace std;


int main(){
    int T,N;
    cin >> T;

    while(T--){
        cin >> N;

        int diff = N;

        for(int i=1;i*i<=N;++i){

                if(N%i==0){
                    int j = N/i;

                    //update diff
                    diff = min(diff, (i>j)?i-j:j-i);

                    //see if prevDiff is less than the current diff break

                }

        }

        cout << diff << endl;
    }
    return 0;
}
