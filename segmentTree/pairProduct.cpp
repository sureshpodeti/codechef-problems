
#include<iostream>
#include<cmath>
using namespace std;

class Node{
public:
    int left; // to store the maximum value
    int right; // to store the second maximum
};

class SegmentTree{
    Node *segmentTree;
    int maxSize;
public:
    SegmentTree(int);
    void build(int*, int, int, int);
    void display();
    int computeMid(int, int);
    void update(int,int,int,int,int);
    void query(int,int,int,int,int);


};

SegmentTree::SegmentTree(int n){
    int height = int(ceil(log2(n)));
    maxSize = 2*int(pow(2,height)) - 1;


    segmentTree = new Node[maxSize];

    for(int i=0;i<maxSize;++i){
        segmentTree[i].left = segmentTree[i].right = 1;
    }
}

int SegmentTree::computeMid(int nodeStart, int nodeEnd){
    return nodeStart + (nodeEnd-nodeStart)/2;
}

void SegmentTree::build(int *A, int nodeStart, int nodeEnd, int idx){
    if(nodeStart==nodeEnd){
        segmentTree[idx].left = segmentTree[idx].right = A[nodeStart];
        return;
    }
    int mid = computeMid(nodeStart, nodeEnd);
    // first build the left, right subtrees
    build(A, nodeStart, mid, 2*idx+1);
    build(A, mid+1, nodeEnd, 2*idx+2);
    //now, build the current node

    segmentTree[idx].left = segmentTree[2*idx+1].left;
    segmentTree[idx].right = segmentTree[2*idx+2].right;

    //swap the segmentTree[idx].left and segmentTree[idx].right, according left, right meaning
    if(segmentTree[idx].left<segmentTree[idx].right){
        segmentTree[idx].left = segmentTree[idx].left + segmentTree[idx].right;
        segmentTree[idx].right = segmentTree[idx].left - segmentTree[idx].right;
        segmentTree[idx].left = segmentTree[idx].left - segmentTree[idx].right;
    }
}

void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int index, int value){
    if(index<nodeStart || index>nodeEnd){
        return;
    }

    if(nodeStart==nodeEnd){
        segmentTree[idx].left = segmentTree[idx].right = value;
        return;
    }

    int mid = computeMid(nodeStart, nodeEnd);

    // first update left, right subtrees
    update(nodeStart, mid, 2*idx+1, index, value);
    update(mid+1, nodeEnd, 2*idx+2, index, value);

    // after updating left, right subtrees update the current node

    segmentTree[idx].left = segmentTree[2*idx+1].left;
    segmentTree[idx].right = segmentTree[2*idx+2].right;

    //swap the segmentTree[idx].left and segmentTree[idx].right, according left, right meaning
    if(segmentTree[idx].left<segmentTree[idx].right){
        segmentTree[idx].left = segmentTree[idx].left + segmentTree[idx].right;
        segmentTree[idx].right = segmentTree[idx].left - segmentTree[idx].right;
        segmentTree[idx].left = segmentTree[idx].left - segmentTree[idx].right;
    }
}


void SegmentTree::query(int nodeStart, int nodeEnd, int idx, int left, int right){
    if(left>nodeEnd || right<nodeStart){
        return;
    }

    if(left<=nodeStart && right>=nodeEnd){
        cout << "sometibg " << (segmentTree[idx].left * segmentTree[idx].right) << endl;
        return;
    }
    int mid = computeMid(nodeStart, nodeEnd);
    query(nodeStart, mid, 2*idx+1, left, right);
    query(mid+1, nodeEnd, 2*idx+2, left, right);
}

void SegmentTree::display(){
    for(int i=0;i<maxSize;++i){
        cout << segmentTree[i].left << " " << segmentTree[i].right << endl;
    }
}

int main(){
    int A[] = {1,3,4,2,5};
    int n = sizeof(A)/sizeof(int);

    SegmentTree segmentTree = SegmentTree(n);
    segmentTree.build(A, 0, n-1, 0);
    segmentTree.query(0, n-1, 0, 0,2);
    segmentTree.update(0, n-1, 0, 1, 6);
    segmentTree.query(0, n-1, 0, 0,2);

    return 0;
}
