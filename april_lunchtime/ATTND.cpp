
#include<iostream>
#include<sstream>
#include<map>
using namespace std;

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cin.ignore();
        string A[N];
        stringstream ss;
        string firstName[N], lastName[N];
        for(int i=0;i<N;++i){
            getline(cin, A[i]);

            stringstream ss(A[i]);
            ss >> firstName[i] >> lastName[i];
        }

        // map to frequency
        map<string,int> m;
        for(int i=0;i<N;++i){
            if(m.find(firstName[i])==m.end()){
                m.insert(pair<string, int>(firstName[i], 1));
            }else{
                m[firstName[i]]++;
            }
        }


        //counter
        int C[N];
        for(int i=0;i<N;++i)
            C[i] = m[firstName[i]];

        for(int i=0;i<N;++i){
            if(C[i]==1){
                cout << firstName[i] << endl;
            }else{
                cout << firstName[i] << " " << lastName[i] << endl;

            }
        }



    }

    return 0;
}
