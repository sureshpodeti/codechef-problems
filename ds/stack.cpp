#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextGreaterElement(int *A, int n){

    int B[n];
    for(int i=0;i<n;++i) B[i] = -1;
    stack<int, vector<int> >  S;

    //push the first element
    S.push(0);

    for(int i=1;i<n;++i){
            if(A[i]>A[S.top()]){
                    while(!S.empty() && A[S.top()]<A[i]){
                        B[S.top()] = A[i];
                        S.pop();
                    }

            }
            S.push(i);
    }


    for(int i=0;i<n;++i)
        cout << B[i] << " ";
    cout << endl;
}
int main(){
    int A[] = {11, 13, 21, 3};
    int n = sizeof(A)/sizeof(int);
    nextGreaterElement(A, n);

    return 0;
}

