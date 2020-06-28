#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
  int noOfNodes;
  int *segmentTree;
public:
  SegmentTree(int, int*);
  int ComputeMidIndex(int,int);
  void Build(int, int, int, int*);
  void Display();
  int RangeSum(int, int, int, int, int);
  void PointUpdate(int, int, int, int, int);
};


SegmentTree::SegmentTree(int n, int *A){
  int height = int(ceil(log2(n)));

  noOfNodes = 2*int(pow(2, height)) -1;

  segmentTree = new int[noOfNodes];

  Build(0, 0, n-1, A);
}

int SegmentTree::ComputeMidIndex(int nodeStart, int nodeEnd){
  return nodeStart+(nodeEnd-nodeStart)/2;
}

void SegmentTree::Build(int node, int nodeStart, int nodeEnd, int *A){
  if(nodeStart==nodeEnd){
    segmentTree[node] = A[nodeStart];
    return;
  }
  int mid = ComputeMidIndex(nodeStart, nodeEnd);
  Build(2*node+1, nodeStart, mid, A);
  Build(2*node+2, mid+1, nodeEnd, A);
  segmentTree[node] = segmentTree[2*node+1] + segmentTree[2*node+2];
}

void SegmentTree::Display(){
  for(int i=0;i<noOfNodes;++i)
    cout << segmentTree[i] << " ";

  cout << endl;
}

int SegmentTree::RangeSum(int node, int nodeStart, int nodeEnd, int left, int right){

  if(left>nodeEnd || right< nodeStart)
    return 0;

  if(left<=nodeStart && right>=nodeEnd){
    return segmentTree[node];
  }

  int mid = ComputeMidIndex(nodeStart, nodeEnd);
  int a  = RangeSum(2*node+1, nodeStart, mid, left, right);
  int b = RangeSum(2*node+2, mid+1, nodeEnd, left, right);

  return a + b;
}

void SegmentTree::PointUpdate(int node, int nodeStart, int nodeEnd, int index, int newValue){

  if(index < nodeStart || index>nodeEnd)
    return;

  if(nodeStart==nodeEnd){
    segmentTree[node] = newValue;
    return;
  }

  int mid = ComputeMidIndex(nodeStart, nodeEnd);
  PointUpdate(2*node+1, nodeStart, mid, index, newValue);
  PointUpdate(2*node+2, mid+1, nodeEnd, index, newValue);

  segmentTree[node] = segmentTree[2*node+1] + segmentTree[2*node+2];
}


int main(){
    int A[] = {1,3,4,2};
    int n = sizeof(A)/sizeof(A[0]);

    SegmentTree segmentTree(n, A);
    segmentTree.Display();


    cout << segmentTree.RangeSum(0, 0, n-1, 0, 2) << endl;

    segmentTree.PointUpdate(0, 0, n-1, 0, 5); // not working correctly

    segmentTree.Display();

    cout << segmentTree.RangeSum(0, 0, n-1, 0, 1) << endl;
    

  return 0;
 }
