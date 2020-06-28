
#include<iostream>
#include<vector>
typedef long long int LLI;
using namespace std;

int palindrome(vector<int> &A, int N){
    int i=0, j=N-1;
    int pali = 1;
    while(i<j){
            if(A[i]!=A[j]){
                    pali = 0;
                break;
            }
            ++i;
            --j;

    }
   return pali;
}

void nextNum(vector<int> &A, int N){
    if(A[0]<9){
        A[0]++;
    }else{
        A[0] = 0;
        int carry = 1;
        int i = 1;
        while(carry!=0){
                if(i==A.size()){
                    A.push_back(carry);
                    carry = 0;
                    break;
                }
                if(A[i]+carry<=9){
                        A[i] += carry;
                        carry = 0;

                }else{
                    A[i] = 0;
                    carry = 1;
                    ++i;

                }

        }


    }

}
int main(){
        LLI T;
        cin >> T;

        string st;

        while(T--){
            cin >> st;

            int N = st.length();

            vector<int> A;
            for(int i=N-1;i>=0;--i) A.push_back(st[i]-'0');



            while(1){
                // update to the next number
                nextNum(A, A.size());

                if(palindrome(A,A.size())){
                    for(int i=A.size()-1;i>=0;--i) cout << A[i];
                    cout << endl;
                    break;
                }
            }


        }

    return 0;
}
