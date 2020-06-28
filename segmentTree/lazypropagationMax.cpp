#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

class SegmentTree{
    int *segmentTree;
    int *lazyArray;
    int maxSize;

public:
    SegmentTree(int);
    int computeMid(int,int);
    void display();
    void build(int*, int,int, int);
    void update(int, int, int, int, int, int);
    int query(int, int, int, int, int);

};


SegmentTree::SegmentTree(int n){
    int height = int(ceil(log2(n)));

    maxSize = 2*int(pow(2,height)) - 1;

    segmentTree = new int[maxSize];
    lazyArray = new int[maxSize];

    for(int i=0;i<maxSize;++i){
        lazyArray[i] = 0;
        segmentTree[i] = INT_MIN;
    }


}

int SegmentTree::computeMid(int nodeStart, int nodeEnd){
    return nodeStart + (nodeEnd-nodeStart)/2;
}

void SegmentTree::display(){

    for(int i=0;i<maxSize;++i)
        cout << segmentTree[i] << " ";
    cout << endl;
}

void SegmentTree::build(int *A, int nodeStart, int nodeEnd, int idx){

    if(nodeStart==nodeEnd){
        segmentTree[idx] = A[nodeStart];
        return;
    }
    //compute mid
    int mid = computeMid(nodeStart, nodeEnd);

    // first build left, right subtrees
    build(A, nodeStart, mid, 2*idx+1);

    build(A, mid+1, nodeEnd, 2*idx+2);

    // now build the current node
    segmentTree[idx] = max(segmentTree[2*idx+1], segmentTree[2*idx+2]);
}

void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int left, int right, int diff){

    if(lazyArray[idx]!=0){
        segmentTree[idx] += lazyArray[idx];
        if(nodeStart!=nodeEnd){
            //propagate to its children
            lazyArray[2*idx+1] += lazyArray[idx];
            lazyArray[2*idx+2] += lazyArray[idx];
        }

        lazyArray[idx] = 0;
    }

    if(left>nodeEnd || right<nodeStart){
        return;
    }

    //updating, if nodes range completly occupies the given range
    if(left<=nodeStart && right>=nodeEnd){
        segmentTree[idx] += diff;

        if(nodeStart!=nodeEnd){
            lazyArray[2*idx+1] += diff;
            lazyArray[2*idx+2] += diff;
        }
        return;
    }



    int mid = computeMid(nodeStart, nodeEnd);
    //first update left, right subtrees
    update(nodeStart, mid, 2*idx+1, left, right, diff);
    update(mid+1, nodeEnd, 2*idx+2, left, right, diff);
    segmentTree[idx] = max(segmentTree[2*idx+1], segmentTree[2*idx+2]);


}


int SegmentTree::query(int nodeStart, int nodeEnd, int idx, int left, int right){

    if(lazyArray[idx]!=0){
        segmentTree[idx] += lazyArray[idx];
        if(nodeStart!=nodeEnd){
            //propagate to its children
            lazyArray[2*idx+1] += lazyArray[idx];
            lazyArray[2*idx+2] += lazyArray[idx];
        }

        lazyArray[idx] = 0;
    }

    if(left>nodeEnd || right<nodeStart){
        return INT_MIN;
    }

    //updating, if nodes range completly occupies the given range
    if(left<=nodeStart && right>=nodeEnd)
        return segmentTree[idx];



    int mid = computeMid(nodeStart, nodeEnd);
    //first update left, right subtrees
    int a = query(nodeStart, mid, 2*idx+1, left, right);
    int b = query(mid+1, nodeEnd, 2*idx+2, left, right);
   return max(a, b);


}
int main(){

    int A[] = {1,3,5,7};
    int n = sizeof(A)/sizeof(int);

    SegmentTree segmentTree = SegmentTree(n);
    segmentTree.build(A, 0, n-1, 0);
    segmentTree.display();

    cout << segmentTree.query(0, n-1, 0, 2,3) << endl;

    segmentTree.update(0, n-1, 0, 2,3, 10);

    segmentTree.display();

    cout << segmentTree.query(0, n-1, 0, 2,3) << endl;
    cout << segmentTree.query(0, n-1, 0, 0,1) << endl;




    return 0;
}
