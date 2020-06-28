#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int getNumber(string st){
    int sze = st.length();
    int A[5] = {0,0,0,0,0};

    //initialize the array
    for(int i=0;i<sze;++i){
            //it could a,e,i,o,u
            if(st[i] == 'a') A[0] = 1;
            else if(st[i]=='e') A[1] = 1;
            else if(st[i]=='i') A[2] = 1;
            else if(st[i]=='o') A[3] = 1;
            else if(st[i]=='u') A[4] = 1;
    }


    int value = 0;
    for(int i=0;i<5;++i)
        value += A[i]*pow(2, i);

    return value;

}
int main(){
    int T, N;
    cin >> T;

    string st;

    while(T--){
        cin >> N;

        long long int pos = N*(N-1)/2;
        int A[pos];
        vector<string> V;
        for(int i=0;i<N;++i){
            cin >> st;
            V.push_back(st);
        }

        int z = 0;
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                string str = V[i] + V[j];
                A[z++] = getNumber(str);
            }
        }

        long long int ans=0;
        for(int i=0;i<pos;++i){
            if(A[i] == 31) ++ans;
        }
        cout << ans << endl;

    }



    return 0;
}
