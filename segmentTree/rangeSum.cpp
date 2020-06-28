
#include<iostream>
#include<cmath>
using namespace std;


class SegmentTree{
    int *segmentTree;
    int maxSize;

public:
    SegmentTree(int*, int);
    void build(int*,int,int,int);
    int computeMid(int, int);
    void display();
    int query(int,int,int,int,int);
    void update(int,int,int,int,int);
};

SegmentTree::SegmentTree(int *A, int n){
    //compute the height of the tree
    int height = int(ceil(log2(n)));

    // compute the maxSize of the tree
    maxSize = 2*int(pow(2,height)) - 1;

    // declare and initialize the segment tree
    segmentTree  = new int[maxSize];

    for(int i=0;i<maxSize;++i) segmentTree[i] = 0;

    build(A, 0, n-1,0);
}

int SegmentTree::computeMid(int nodeStart, int nodeEnd){
    return nodeStart + (nodeEnd-nodeStart)/2;
}

void SegmentTree::build(int *A, int nodeStart, int nodeEnd, int idx){
    if(nodeStart==nodeEnd){
        segmentTree[idx] = A[nodeStart];
        return;
    }
    int mid = computeMid(nodeStart, nodeEnd);
    build(A, nodeStart, mid, 2*idx+1);
    build(A, mid+1, nodeEnd, 2*idx+2);
    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}

void SegmentTree::display(){
    for(int i=0;i<maxSize;++i)
        cout << segmentTree[i] << " ";
    cout << endl;
}

int SegmentTree::query(int nodeStart, int nodeEnd, int idx, int left, int right){
    //if the range is completely outside
    if(right<nodeStart || left>nodeEnd){
        return 0;
    }

    // if range is completly within
    if(left<=nodeStart && right>=nodeEnd){
        return segmentTree[idx];
    }

    int mid = computeMid(nodeStart, nodeEnd);
    int a = query(nodeStart, mid, 2*idx+1, left, right);
    int b = query(mid+1, nodeEnd, 2*idx+2, left, right);
    return a + b;
}


void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int index, int value){

    if(index<nodeStart || index>nodeEnd)
        return;

    if(nodeStart==nodeEnd){
        segmentTree[idx] = value;
        return;
    }


    int mid = computeMid(nodeStart, nodeEnd);

    update(nodeStart, mid, 2*idx+1, index, value);
    update(mid+1, nodeEnd, 2*idx+2, index, value);
    segmentTree[idx] = segmentTree[2*idx+1]+ segmentTree[2*idx+2];

}
int main(){
    int A[] = {1,3,5,7,9,11};
    int n = sizeof(A)/sizeof(int);

    SegmentTree segmentTree = SegmentTree(A, n);
    segmentTree.display();
    cout << segmentTree.query(0, n-1, 0, 1, 3) << endl;
    segmentTree.update(0, n-1, 0, 1, 10);
    cout << segmentTree.query(0, n-1, 0, 1, 3) << endl;
    segmentTree.display();

    return 0;
}
