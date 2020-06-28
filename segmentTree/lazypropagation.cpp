#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
    int *segmentTree;
    int *lazy;
    int maxSize;
public:
    SegmentTree(int*, int);
    int computeMid(int, int);
    void display();
    void build(int*,int, int, int);
    int query(int,int,int,int,int);
    void update(int, int, int, int, int, int);

};
SegmentTree::SegmentTree(int *A, int n){
    //compute the height of tree as n leaf nodes
    int height = int(ceil(log2(n)));

    //compute maxSize
    maxSize = 2*int(pow(2,height)) - 1;

    segmentTree = new int[maxSize];
    lazy = new int[maxSize];

    //initialize
    for(int i=0;i<maxSize;++i)
        segmentTree[i] = lazy[i] = 0;

    build(A, 0, n-1, 0);
}

int SegmentTree::computeMid(int nodeStart, int nodeEnd){
    return nodeStart + (nodeEnd-nodeStart)/2;
}

void SegmentTree::build(int *A, int nodeStart, int nodeEnd, int idx){
    //base condition
    if(nodeStart==nodeEnd){
        segmentTree[idx] = A[nodeStart];
        return;
    }


    //first build the left and right subtrees
    int mid = computeMid(nodeStart, nodeEnd);

    build(A, nodeStart, mid, 2*idx+1);
    build(A, mid+1, nodeEnd, 2*idx+2);

    //after building left, right subtree build its parent
    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];

}

void SegmentTree::display(){
    for(int i=0;i<maxSize;++i)
        cout << segmentTree[i] << " ";
    cout << endl;

}

int SegmentTree::query(int nodeStart,int nodeEnd, int idx, int left, int right){

    if(lazy[idx]!=0){
            //update current node
            segmentTree[idx] += (nodeEnd-nodeStart+1)*lazy[idx];

            //if it is not leaf node, will update lazy of its children
            if(nodeStart!=nodeEnd){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;

    }


    //if nodes range is outside
    if(right<nodeStart || left>nodeEnd){
        return 0;
    }

    // if nodes range is completly within given range
    if(left<=nodeStart && right>=nodeEnd){
        return segmentTree[idx];
    }

    int mid = computeMid(nodeStart, nodeEnd);
    int a = query(nodeStart, mid, 2*idx+1, left, right);
    int b = query(mid+1, nodeEnd, 2*idx+2, left, right);
    return a+b;
}


void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int left, int right, int diff){
    if(lazy[idx]!=0){
        segmentTree[idx] += (nodeEnd-nodeStart+1)*lazy[idx];

        if(nodeStart!=nodeEnd){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    //if nodes range is outside
    if(right<nodeStart || left>nodeEnd){
        return;
    }

    // if nodes range is completly
    if(left<=nodeStart && right>=nodeEnd){
        segmentTree[idx] += (nodeEnd-nodeStart+1)*diff;

        //if it is not leaf node
        if(nodeStart!=nodeEnd){
            lazy[2*idx+1]  += diff;
            lazy[2*idx+2]  += diff;
        }
        return;
    }

    int mid = computeMid(nodeStart, nodeEnd);
    update(nodeStart, mid, 2*idx+1, left, right, diff);
    update(mid+1, nodeEnd, 2*idx+2, left, right, diff);
    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}


int main(){
    int A[] = {1,3,5,7,9,11};
    int n = sizeof(A)/sizeof(int);

    SegmentTree segmentTree = SegmentTree(A, n);

    segmentTree.display();
    segmentTree.update(0, n-1, 0, 1,5, 10);
    segmentTree.display();
    cout << segmentTree.query(0, n-1, 0,1,3) << endl;;
    return 0;
}
