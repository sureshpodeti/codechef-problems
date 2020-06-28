#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


class SegmentTree{
  int no_of_nodes;
  vector<int> *segment_tree;
public:
  SegementTree();
  

};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2, height)) - 1;

  segment_tree = new vector<int>[no_of_nodes];


  Build();

}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}
void SegmentTree::Build(int node, int node_left, int node_right, int *A){
  if(node_left == node_right){
    segment_tree[node].push_back(A[node_left]);
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  // merging operation
  
  

}


void Merge(int *A, int *B, int n, int m ){
  int *C  = new int[n+m];

  int i,j,k;
  i=j=k=0;
  while(i<m && j<n){
    if(A[i]<B[j])
      C[k++] = A[i++];
    else
      C[k++] = B[j++];
  }

  //fill the remaining elements 

}
int main(){


  return 0;
}
