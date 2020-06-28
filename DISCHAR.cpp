#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    string S;

    //define an array that represents lower case alphabets
    int A[26];

    while(T--){
        cin >> S;

        //initialize them with all zeros
        for(int i=0;i<26;++i) A[i] = 0;

        int C=0;

        for(int i=0;i<S.length();++i){
                if(!A[S[i]- 97]){ // we have not seen this character previously
                        A[S[i]-97] = 1; // mark it as seen
                        ++C; // count for the final result
                }

        }

        cout << C << endl;



    }



    return 0;
}
