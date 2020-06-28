#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    long long int D;
    cin >> N >> D;

    long long int A[N];
    for(int i=0;i<N;++i) cin >> A[i];


    //sort the array
    sort(A, A+N);


    int i=0, j=1;
    int counter = 0;

    while(i<N && j<N){
        if(A[j] - A[i]<=D){
            i += 2;
            j += 2;
            ++counter;
        }else{
            ++i;
            ++j;
        }
    }

    cout << counter << endl;




    return 0;
}
