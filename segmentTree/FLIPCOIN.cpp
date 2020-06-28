#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
    int *segmentTree;
    int *lazyArray;
    int maxSize;

public:
    SegmentTree(int);
    int computeMid(int,int);
    void display();
    void update(int, int, int, int, int);
    int query(int, int, int, int, int);

};


SegmentTree::SegmentTree(int n){
    int height = int(ceil(log2(n)));

    maxSize = 2*int(pow(2,height)) - 1;

    segmentTree = new int[maxSize];
    lazyArray = new int[maxSize];

    for(int i=0;i<maxSize;++i){
        lazyArray[i] = 0;
        segmentTree[i] = 0;
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


void SegmentTree::update(int nodeStart, int nodeEnd, int idx, int left, int right){

    if(lazyArray[idx]==1){
        segmentTree[idx] = (nodeEnd-nodeStart+1) - segmentTree[idx];
        if(nodeStart!=nodeEnd){
            //propagate to its children
            lazyArray[2*idx+1] = !lazyArray[2*idx+1];
            lazyArray[2*idx+2] = !lazyArray[2*idx+2];
        }

        lazyArray[idx] = !lazyArray[idx];
    }

    if(left>nodeEnd || right<nodeStart){
        return;
    }

    //updating, if nodes range completly occupies the given range
    if(left<=nodeStart && right>=nodeEnd){
        segmentTree[idx] = (nodeEnd-nodeStart+1)-segmentTree[idx];

        if(nodeStart!=nodeEnd){
            lazyArray[2*idx+1] = !lazyArray[2*idx+1];
            lazyArray[2*idx+2] = !lazyArray[2*idx+2];
        }
        return;
    }



    int mid = computeMid(nodeStart, nodeEnd);
    //first update left, right subtrees
    update(nodeStart, mid, 2*idx+1, left, right);
    update(mid+1, nodeEnd, 2*idx+2, left, right);
    segmentTree[idx] = segmentTree[2*idx+1]+segmentTree[2*idx+2];


}


int SegmentTree::query(int nodeStart, int nodeEnd, int idx, int left, int right){

    if(lazyArray[idx]==1){
        segmentTree[idx] = (nodeEnd-nodeStart+1) - segmentTree[idx];
        if(nodeStart!=nodeEnd){
            //propagate to its children
            lazyArray[2*idx+1] = !lazyArray[2*idx+1];
            lazyArray[2*idx+2] = !lazyArray[2*idx+2];
        }

        lazyArray[idx] = 0;
    }

    if(left>nodeEnd || right<nodeStart){
        return 0;
    }

    //updating, if nodes range completly occupies the given range
    if(left<=nodeStart && right>=nodeEnd)
        return segmentTree[idx];



    int mid = computeMid(nodeStart, nodeEnd);
    //first update left, right subtrees
    int a = query(nodeStart, mid, 2*idx+1, left, right);
    int b = query(mid+1, nodeEnd, 2*idx+2, left, right);
   return a+b;


}
int main(){

    int n,q;
    cin >> n >> q;

    SegmentTree segmentTree = SegmentTree(n);

    int type, A, B;
    while(q--){
        cin >> type >> A >> B;
        if(type){
                // query operation
                cout << segmentTree.query(0, n-1, 0, A,B) << endl;

        }else{
                // update operation
                segmentTree.update(0, n-1, 0, A,B);
        }

    }


    return 0;
}
