#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


class SegmentTree{
  int no_of_nodes;
  pair<int,int> *segment_tree; //first will score the maximum values, and second will store its index

public:
  SegmentTree(int*, int);
  void Build(int, int, int, int*);
  int ComputeMidIndex(int, int);
  pair<int,int> RangeMax(int, int, int, int, int);
  int MaxSumSubArray(int*, int, int, int);  
};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));

  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new pair<int,int>[no_of_nodes];

  //build the segment tree
  Build(0, 0, n-1, A); 

}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}

void SegmentTree::Build(int node, int node_left, int node_right, int *A){

  if(node_left==node_right){
    segment_tree[node].first  = A[node_left];
    segment_tree[node].second = node_left;
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  segment_tree[node].first = max(segment_tree[2*node+1].first, segment_tree[2*node+2].first);
  segment_tree[node].second = (segment_tree[2*node+1].first > segment_tree[2*node+2].first)? segment_tree[2*node+1].second:segment_tree[2*node+2].second;
}

pair<int,int> SegmentTree::RangeMax(int node, int node_left, int node_right, int left, int right){
  if(right<node_left || left>node_right){
    return pair<int, int>(INT_MIN, -1);
  }

  if(left<=node_left && right>=node_right){
    return segment_tree[node];
  }

  int mid = ComputeMidIndex(node_left, node_right);

  pair<int, int> a = RangeMax(2*node+1, node_left, mid, left, right);
  pair<int, int> b = RangeMax(2*node+2, mid+1, node_right, left, right);

  return (a.first>b.first)?a:b;
}

int SegmentTree::MaxSumSubArray(int *A, int left, int right, int n){

  if(left>right) return 0;

  pair<int, int> p = RangeMax(0, 0, n-1, left, right);

  return  p.first*(right-p.second+1)*(p.second-left+1)+MaxSumSubArray(A, left, p.second-1, n) + MaxSumSubArray(A, p.second+1, right, n);
}

int main(){
  int A[] = {1, 3, 1, 7};
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A, n);

  cout << segment_tree.MaxSumSubArray(A, 0, n-1, n) << endl;

  return 0;
}
