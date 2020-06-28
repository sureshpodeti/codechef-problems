#include<iostream>
#include<algorithm>
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
        int C[sze], z=0;

        int i=sze-1, c=0;
        while(A[i]>=d && i){
            --i;
            ++c;
        }

        for(int j=0;j<=i;++j){
            if(A[j]<d){
                // add A[j] to array C
                C[z++] = A[j];
            }else ++c;
        }


        // append d's at the ending
        for(int j=z;j<sze;++j) C[j] = d;

        // write the array into a string
        for(int i=0;i<sze;++i){
            ans.push_back(48+C[i]);
        }


        cout << ans << endl;
    }


    return 0;
}

