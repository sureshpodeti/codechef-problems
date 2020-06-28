#include<iostream>
#include<cmath>

using namespace std;

class SegmentTree{
  int no_of_nodes;
  int *segment_tree, *lazy_array;

public:
  SegmentTree(int*, int);
  int ComputeMidIndex(int, int);
  void Build(int, int, int, int*);
  void RangeUpdate(int, int, int, int);
  void  RangeUpdateUtil(int, int, int, int, int, int);
  int RangeQuery(int, int, int);
  int RangeQueryUtil(int, int, int, int, int);
};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new int[no_of_nodes];
  lazy_array = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    lazy_array[i] = 0;

  Build(0, 0, n-1, A);
}

int SegmentTree::ComputeMidIndex(int node_start, int node_end){
  return node_start + (node_end - node_start)/2;
}

void SegmentTree::Build(int node, int node_start, int node_end, int *A){
  if(node_start==node_end){
    segment_tree[node] = A[node_start];
    return;
  }

  int mid = ComputeMidIndex(node_start, node_end);
  Build(2*node+1, node_start, mid, A);
  Build(2*node+2, mid+1, node_end, A);
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

void SegmentTree::RangeUpdate(int n, int left, int right, int diff){
  RangeUpdateUtil(0, 0, n-1, left, right, diff);
}
void SegmentTree::RangeUpdateUtil(int node, int node_start, int node_end, int left, int right, int diff){
  if(lazy_array[node]){
    segment_tree[node] += (node_end - node_start+1)*lazy_array[node];
    if(node_start!=node_end){
      lazy_array[node] += lazy_array[2*node+1];
      lazy_array[node] += lazy_array[2*node+2];
    }
    lazy_array[node] = 0;
  }

  if(left>node_end || right<node_start){
    return;
  }

  if(left<=node_start && right>=node_end){
    segment_tree[node] += (node_end - node_start+1)*diff;
    if(node_start!=node_end){
      lazy_array[2*node+1] += diff;
      lazy_array[2*node+2] += diff;
    }
    return;
  }

  int mid = ComputeMidIndex(node_start, node_end);

  RangeUpdateUtil(2*node+1, node_start, mid, left, right, diff);
  RangeUpdateUtil(2*node+2, mid+1, node_end, left, right, diff);

  segment_tree[2*node] = segment_tree[2*node+1] + segment_tree[2*node+2];
 
}


int SegmentTree::RangeQuery(int n, int left, int right){
  return RangeQueryUtil(0, 0, n-1, left, right);
}

int SegmentTree::RangeQueryUtil(int node, int node_start, int node_end, int left, int right){

  if(lazy_array[node]){
    segment_tree[node] += (node_end - node_start+1)*lazy_array[node];

    if(node_start!=node_end){
      lazy_array[2*node+1] += lazy_array[node];
      lazy_array[2*node+2] += lazy_array[node];
    }

    lazy_array[node] = 0;
  }

  if(left>node_end || right< node_start){
    return 0;
  }

  if(left<=node_start && right>=node_end){
    return segment_tree[node];
  }
  

  int mid = ComputeMidIndex(node_start, node_end);
  int a = RangeQueryUtil(2*node+1, node_start, mid, left, right);
  int b = RangeQueryUtil(2*node+2, mid+1, node_end, left, right);

  return a + b;
}



int main(){

  int A[] = {1, 3, 4, 2};
  int n = sizeof(A)/sizeof(A[0]);
  
  SegmentTree segment_tree(A,n);

  segment_tree.RangeUpdate(n, 0, 1, 1);

  cout << segment_tree.RangeQuery(n, 0, n-1) << endl;
  cout << segment_tree.RangeQuery(n, 0, 1) << endl;
  cout << segment_tree.RangeQuery(n, 0, 2) << endl;


  
  return 0;
}
