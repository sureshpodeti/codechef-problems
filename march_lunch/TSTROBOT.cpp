
#include<iostream>
#include<set>
using namespace std;

int main(){
    int T, N, X;
    cin >> T;

    string command;
     while(T--){
        cin >> N >> X;
        cin >> command;
        set<long long int> A;

        A.insert(X);

        for(int i=0;i<N;++i){
                if(command[i]=='R') --X;
                else ++X;


                // insert the X into set
                A.insert(X);
        }

        cout << A.size() << endl;




    }



    return 0;
}
