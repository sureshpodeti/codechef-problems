
#include<iostream>
#include<vector>
#define REP(i,a, b) for(int i=a;i<b;++i)

#define SQ(a) (a)*(a)
using namespace std;
typedef  vector<int> vct;

int main(){

    int A[] =  {10, 20, 3, 40, 100};
    int N = sizeof(A)/sizeof(int);
    vct v;

    REP(i,0,N){
        v.push_back(A[i]);
    }


    for(int i=0;i<N;++i)
        cout << v[i] << " ";
    cout << endl;


    cout << SQ(3+3) << endl;



    return 0;
}
