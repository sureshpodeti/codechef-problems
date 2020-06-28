#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;


    while(T--){
            string jewel, st;
            cin >> jewel;
            cin >> st;

            int A[52]; // to store jewel status of each alphabet(small and big)

            // initialize elements of A to all 0s
            // 0 -> not jewel character, 1 -> jewel character
            for(int i=0;i<52;++i) A[i] = 0;

            int index;

            // go through the jewel string and update A
            for(int i=0;i<jewel.length();++i){
                index = jewel[i]-65;
                A[index] = 1;
            }


            // go through the given string and count jewel in it
            int counter = 0;
            for(int i=0;i<st.length();++i){
                index = st[i]-65;
                if(A[index]) ++ counter;
            }


            cout << counter << endl;

    }

}
