
#include<iostream>
#include<vector>
typedef long long int LLI;
using namespace std;


int main(){
        LLI T;
        cin >> T;

        string st;

        while(T--){
            cin >> st;

            int N = st.length();

            int A[N];
            for(int i=0;i<N;++i) A[i] = st[i]-'0';

            int i=0, j=N-1;
            while(i<=j){
                    if(i+1==j){
                            if(A[j]<A[i]) A[j] = A[i];
                            else{

                            }

                    }else{
                        if(A[i]==A[j]) continue;
                        else A[j] = A[i];

                    }


            }


        }

    return 0;
}

