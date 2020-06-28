#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
  int *lazy_array;
public:
  SegmentTree(int *, int);
  void Build(int, int, int, int*);
  int ComputeMidIndex(int, int);
  void RangeUpdate(int, int, int, int, int, int);
  int RangeQuery(int, int, int);
  int RangeQueryUtil(int,int,int,int, int); 
};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new int[no_of_nodes];
  lazy_array = new int[no_of_nodes];

  //initialize the lazy array with all pending updates 0
  for(int i=0;i<no_of_nodes;++i)
    lazy_array[i] = 0;

  Build(0, 0, n-1, A);
}


int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}

void SegmentTree::Build(int node, int node_left, int node_right, int *A){

  if(node_left == node_right){
    segment_tree[node] = A[node_left];
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
  
}

void SegmentTree::RangeUpdate(int node, int node_left, int node_right, int left, int right, int diff){
  if(lazy_array[node]){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];
    if(node_left!=node_right){
      segment_tree[2*node+1] += lazy_array[node];
      segment_tree[2*node+2] += lazy_array[node];
    }
    lazy_array[node] = 0;
  }

  if(left>node_right || right<node_left){
    return;
  }

  if(left<=node_left && right>=node_right){
    segment_tree[node] += (node_right - node_left+1)*diff;
    if(node_left!=node_right){
      segment_tree[2*node+1] += diff;
      segment_tree[2*node+2] += diff;
    }
    return;
  }

  
  int mid = ComputeMidIndex(node_left, node_right);
  RangeUpdate(2*node+1, node_left, mid, left, right, diff);
  RangeUpdate(2*node+2, mid+1, node_right, left, right, diff);
}

int SegmentTree::RangeQuery(int n, int left, int right){
  return RangeQueryUtil(0, 0, n-1, left, right);

}
int SegmentTree::RangeQueryUtil(int node, int node_left, int node_right, int left, int right){
  if(lazy_array[node]){
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

  int mid =ComputeMidIndex(node_left, node_right);

  int a = RangeQueryUtil(2*node+1, node_left, mid, left, right);
  int b = RangeQueryUtil(2*node+2, mid+1, node_right, left, right);
  return a + b;
}
int main(){
  int A[] = {1,3,2,4};
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A, n);


  segment_tree.RangeUpdate(0, 0, n-1, 0, 2, 1);

  cout << segment_tree.RangeQuery(n, 0, 1) << endl;
  /*
  cout << segment_tree.RangeQuery(n, 0, 2) << endl;
  cout << segment_tree.RangeQuery(n, 0, 3) << endl;

  cout << segment_tree.RangeQuery(n, 1, 2) << endl;
  cout << segment_tree.RangeQuery(n, 1, 3) << endl;

  cout << segment_tree.RangeQuery(n, 2, 3) << endl;
  */
  

  return 0;
}