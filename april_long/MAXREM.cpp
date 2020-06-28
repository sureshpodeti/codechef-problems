
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long int A[N];

    for(int i=0;i<N;++i)
        cin >> A[i];

     //sort the array
     sort(A, A+N);

     //get the second highest element
     int i=N-2;
     long long int maxElem = A[N-1];
     long long int ans=0;
     while(i>=0){
           if(maxElem%A[i]!=0){
                ans = A[i];
                break;
           }
        --i;
     }

     cout << ans << endl;



    return 0;
}
