#include<iostream>
#include<sstream>
using namespace std;


int main(){
    int T, d;
    cin >> T;

    string N;
    while(T--){
        cin >> N >> d;
        int sze = N.length();
        int A[sze];
        for(int i=0;i<sze;++i){
            A[i] = N[i] - 48;
        }

        string ans = "";
        //get the least element of the array and its index
        int index, least=9;
        for(int i=sze-1;i>=0;--i){
            if(least>=A[i]){
                    least = A[i];
                    index = i;
            }
        }


            int B[sze];

            int j=0;


            //write the remaining values
            for(int i=index;i<sze;++i){
                if(A[i]<d){
                        B[j] = A[i];
                        ++j;
                }

            }

            //fill the remaining elements of B
            for(int i=j;i<sze;++i){
                B[i] = d;
            }

            for(int i=0;i<sze;++i) ans.push_back(B[i]+48);


            cout << ans << endl;



    }


    return 0;
}
