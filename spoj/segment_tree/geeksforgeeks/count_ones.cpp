#include<iostream>
#include<cmath>
using namespace std;

class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
  int *lazy_array;
public:
  SegmentTree(int);
  
};

SegmentTree::SegmentTree(int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2,height))-1;

  segment_tree = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    segment_tree[i] = lazy_array[i] = 0;

}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right-node_left)/2;
}

void SegmentTree::RangeUpdate(int node, int node_left, int node_right, int left, int right){
  if(lazy_array[node]){
    segment_tree[node] = (node_right-node_left+1)*lazy_array[node];
    if(node_left!=node_right){
      lazy_array[2*node+1] = lazy_array[node];
      lazy_array[2*node+2] = lazy_array[node];
    }
    lazy_array[node] = 0;
  }

  if(left>node_right || right<node_left)
    return;

  if(left<=node_left && right>=node_right){
    segment_tree[node] = (node_right-node_left+1);
    return; 
  }
  
  int mid = ComputeMidIndex(node_left, node_right);
  RangeUpdate(2*node+1, node_left, mid, left, right);
  RangeUpdate(2*node+2, mid+1, node_right, left, right);
  segement_tree[node] = segment_tree[2*node+1]  + segment_tree[2*node+2];
}

int SegmentTree::RangeQuery(int node, int node_left, int node_right, int left, int right){


}


int main(){
  int n;
  cin >> n;

  SegmentTree segment_tree(n);
  


  
  

  return 0;
}
