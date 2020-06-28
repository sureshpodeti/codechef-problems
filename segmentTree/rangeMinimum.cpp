#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

class SegmentTree{
    int *segmentTree;
    int maxSize;

public:
    SegmentTree(int*, int);
    int computeMid(int,int);
    void build(int*, int, int, int);
    void display();
    int query(int, int, int, int, int);
    void update(int, int, int, int,int);

};


SegmentTree::SegmentTree(int *A, int n){
    //computer height of the tree with n nodes
    int height = int(ceil(log2(n)));

    //compute the maximum nodes needed for segment tree
    maxSize = 2*int(pow(2,height)) -1;

    //declare and initialize the segment tree
    segmentTree = new int[maxSize];

    for(int i=0;i<maxSize;++i) segmentTree[i] = INT_MAX;

    build(A, 0, n-1, 0);
}

int SegmentTree::computeMid(int nodeStart, int nodeEnd){
    return nodeStart + (nodeEnd - nodeStart)/2;
}

void SegmentTree::build(int *A, int nodeStart, int nodeEnd, int idx){
    //base cases
    if(nodeStart==nodeEnd){
        segmentTree[idx] = A[nodeStart];
        return;
    }

    //first build left, right subtrees
    int mid = computeMid(nodeStart, nodeEnd);
    build(A, nodeStart, mid, 2*idx+1);
    build(A, mid+1, nodeEnd, 2*idx+2);
    segmentTree[idx] = min(segmentTree[2*idx+1] ,segmentTree[2*idx+2]);
}

void SegmentTree::display(){

    for(int i=0;i<maxSize;++i)
        cout << segmentTree[i] << " ";
    cout << endl;
}

int SegmentTree::query(int nodeStart, int nodeEnd, int idx, int left, int right){

    //base cases
    // if node is outside the given range
    if(left>nodeEnd || right < nodeStart){
        return INT_MAX;
    }

    //if the node is completly within the given range
    if(left<=nodeStart && right>=nodeEnd){
        return segmentTree[idx];
    }

    int mid = computeMid(nodeStart, nodeEnd);
    int a = query(nodeStart, mid, 2*idx+1, left, right);
    int b = query(mid+1, nodeEnd, 2*idx+2, left, right);
    return min(a,b);

}

void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int index, int value){
    //base cases
    // if index outside the given nodes range
    if(index< nodeStart || index>nodeEnd){
        return;
    }


    if(nodeStart==nodeEnd){
        segmentTree[idx] = value;
        return;
    }


    int mid = computeMid(nodeStart, nodeEnd);
    update(nodeStart, mid, 2*idx+1, index, value);
    update(mid+1, nodeEnd, 2*idx+2, index, value);
    //update its parents;once the childrens are updated
    segmentTree[idx] = min(segmentTree[2*idx+1], segmentTree[2*idx+2]);

}
int main(){

    int A[] = {2, 5, 1, 4, 9, 3};
    int n = sizeof(A)/sizeof(int);

    SegmentTree segmentTree = SegmentTree(A, n);
    segmentTree.display();
    cout << segmentTree.query(0, n-1, 0, 1, 3) << endl;
    segmentTree.update(0, n-1, 0, 0,10);
    segmentTree.display();



    return 0;
}
