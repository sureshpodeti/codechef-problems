#include<iostream>
#include<cmath>
using namespace std;

int constructSTUtil(int A[], int ss, int se, int *st, int si){
    // if only one element present
    if(ss==se){
        st[si] = A[ss];
        return A[ss];
    }

    //compute mid
    int mid = ss+(se-ss)/2;
    st[si] = constructSTUtil(A, ss, mid, st, 2*si+1)+constructSTUtil(A, mid+1, se, st, 2*si+2);

    return st[si];

}
int *constructST(int A[], int n){
    // compute the height of the binary tree
    int x = int(ceil(log2(n)));

    //compute the nodes needed for ST
    int maxSize = 2*int(pow(2, x)) - 1;

    int *st = new int[maxSize];

    constructSTUtil(A, 0, n-1, st, 0);


    return st;

}
int main(){
    int A[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(A)/sizeof(int);

    // construct the segmentation tree from the given array
    int *st = constructST(A, n);

    for(int i=0;i<15;++i) cout << *(st+i) << " ";
    cout << endl;



    return 0;
}
