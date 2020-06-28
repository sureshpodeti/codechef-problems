#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
  int *lazy_array;
public:
  SegmentTree(int*,int);
  void Build(int,int,int,int*);
  void Print();
  int ComputeMid(int,int);
  void RangeUpdate(int,int,int,int,int,int);
  int RangeSum(int,int,int,int,int);
};

SegmentTree::SegmentTree(int *A, int n){
  
  int height = int(ceil(log2(n)));

  no_of_nodes = 2*int(pow(2, height)) - 1;
  cout << no_of_nodes << endl;

  segment_tree = new int[no_of_nodes];
  lazy_array = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    segment_tree[i] = lazy_array[i] = 0;

  Build(0, 0, n-1, A);
}

int SegmentTree::ComputeMid(int node_left, int node_right){
  return node_left+(node_right-node_left)/2;
}

void SegmentTree::Build(int node, int node_left, int node_right, int *A){
  if(node_left==node_right){
    segment_tree[node] = A[node_left];
    return;
  }
  int mid = ComputeMid(node_left, node_right);

  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

void SegmentTree::Print(){
  for(int i=0;i<no_of_nodes;++i)
    cout << segment_tree[i] << " ";
  cout << endl;


   for(int i=0;i<no_of_nodes;++i)
    cout << lazy_array[i] << " ";
  cout << endl;
}

void SegmentTree::RangeUpdate(int node, int node_left, int node_right, int left, int right, int diff){
  
  if(lazy_array[node]!=0){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];
    if(node_left!=node_right){
      lazy_array[2*node+1] += lazy_array[node];
      lazy_array[2*node+2] += lazy_array[node];
    }
    lazy_array[node] = 0;
  }

  if(left>node_right || right<node_left)
    return;

  if(left<=node_left && right>=node_right){
    segment_tree[node] += (node_right - node_left+1)*diff;
    if(node_left!=node_right){
      lazy_array[2*node+1] += diff;
      lazy_array[2*node+2] += diff;
    }
    return;
  }
  
  int mid = ComputeMid(node_left, node_right);
  RangeUpdate(2*node+1, node_left, mid, left, right, diff);
  RangeUpdate(2*node+2, mid+1, node_right, left, right, diff);
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}



int SegmentTree::RangeSum(int node, int node_left, int node_right, int left, int right){
  if(lazy_array[node]!=0){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];
    if(node_left!=node_right){
      lazy_array[2*node+1] += lazy_array[node];
      lazy_array[2*node+2] += lazy_array[node];
    }
    lazy_array[node] = 0;
  }

  
  if(left>node_right || right<node_left)
    return 0;

  if(left<=node_left && right>=node_right){
    return segment_tree[node];
  }

  int mid = ComputeMid(node_left, node_right);
  int a = RangeSum(2*node+1,node_left,mid,left,right);
  int b = RangeSum(2*node+2,mid+1,node_right,left,right);
  return a+b;
}

int main(){
  int A[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A, n);
  segment_tree.Print();

  cout << segment_tree.RangeSum(0,0,n-1,1,3) << endl;
  
  segment_tree.RangeUpdate(0, 0, n-1, 1, 5,10);

  segment_tree.Print();

  cout << segment_tree.RangeSum(0,0,n-1,1,3) << endl;

  /*
  cout << segment_tree.RangeSum(0,0,n-1,2,3) << endl;
  cout << segment_tree.RangeSum(0,0,n-1,0,3) << endl;
  cout << segment_tree.RangeSum(0,0,n-1,1,2) << endl;
  cout << segment_tree.RangeSum(0,0,n-1,0,2) << endl;

  */
  return 0;
}
