
#include<iostream>
#include<cmath>
using namespace std;

int segTree[1000];

void build(int A[], int ss, int se, int *segTree, int idx){
    if(ss==se){
            segTree[idx] = A[ss];
            return;
    }

    int mid = ss + (se-ss)/2;

    // build the left subtree
    build(A, ss, mid, segTree, 2*idx+1);


    //build the right subtree
    build(A, mid+1, se, segTree, 2*idx+2);

    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}

int query(int *segTree, int idx, int ss, int se, int qs, int qe){
    // range represented by idx is completely outside the given range
    if(qe<ss || se<qs)
        return 0;

    //range represented by idx is completely inside the given range
    if(qs<=ss && se<=qe)
        return segTree[idx];

    // range represented by idx is partially inside and partially outside the given range
    int mid = ss + (se-ss)/2;
    int s1 = query(segTree, 2*idx+1, ss, mid, qs, qe);
    int s2 = query(segTree, 2*idx+2, mid+1, se, qs, qe);
    return s1+s2;

}


void update(int *A, int ss, int se, int *segTree, int idx, int index, int value){
    if(ss==se){
        // current node should be updated
        A[index] = value;
        segTree[idx] = value;
        return;
    }


    // compute the mid
    int mid = ss + (se-ss)/2;


    //check if the idx lies on left half
    if(index>=ss && index<=mid){
        //update in left half
        update(A, ss, mid, segTree, 2*idx+1, index, value);
    }else{
        //update in right half
        update(A, mid+1, se, segTree, 2*idx+2, index, value);

    }

    // update the root node
    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];


}
int main(){

    int A[] = {1,3,5,7,9,11};
    int n = sizeof(A)/sizeof(int);

    //compute the height of the tree
    int height = int(ceil(log2(n)));

    //compute maximum nodes needed
    int maxSize = 2*int(pow(2,height)) - 1;

    build(A, 0, n-1,  segTree,0);

//    for(int i=0;i<maxSize;++i)
//        cout << segTree[i] << " ";
//    cout << endl;

    //query
    cout << query(segTree, 0, 0, n-1, 2,5) << endl;

    update(A, 0, n-1, segTree, 0, 3,6);
    cout << query(segTree, 0, 0, n-1, 2,5) << endl;


    return 0;
}
