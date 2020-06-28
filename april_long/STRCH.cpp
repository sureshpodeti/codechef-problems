#include<iostream>
#include<vector>
using namespace std;

int main(){

    int T, N;
    cin >>  T;

    string st;
    char X;

    while(T--){
        cin >> N;
        cin >> st >> X;

        //count the total no.of substrings
        long long int tot = N*(N+1)/2;
        // Traverse the string and get the count of non X alphabets
        int c = 0;
        long long int rem = 0;
        for(int i=0;i<N;++i){
            if(st[i]!=X) ++c;
            else{
                rem += c*(c+1)/2;
                c = 0;
            }

        }

        cout << (tot-rem - c*(c+1)/2) << endl;
    }

    return 0;
}
