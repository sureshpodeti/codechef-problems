#include<iostream>
using namespace std;


int main(){
    int T, d;
    cin >> T;

    string N;
    while(T--){
        cin >> N >> d;
        int sze = N.length();
        int A[sze+1]; // +1 to add the digit at the end
        for(int i=0;i<sze;++i){
            A[i] = N[i] - 48;
        }

        // add digit d
        A[sze] = d;

        string ans = "";


        // Bi defines the least element in A[i...N-1]
        // Ci defines the least element index in A[i...N-1]
        int B[sze+1], C[sze+1], D[sze];

        B[sze] = A[sze];
        C[sze] = sze;
        for(int i=sze-1;i>=0;--i){
            //update B, and C
            if(A[i] <= B[i+1]){
                B[i] = A[i];
                C[i] = i;
            }else{
                B[i] = B[i+1];
                C[i] = i-1;
            }

        }


        int j=0;
        for(int i=0;i<sze;++i){
            if(C[i] == i){
                D[j++] = B[i];
            }
        }

        //push the remaining d's
        for(int i=j;i<sze;++i) D[i] = d;


        // write the array into a string
        for(int i=0;i<sze;++i){
            ans.push_back(48+D[i]);
        }



        cout << ans << endl;
    }


    return 0;
}
