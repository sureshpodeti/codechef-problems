#include<iostream>
#include<cmath>
using namespace std;


class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
  int *lazy_array;
public:
  SegmentTree(int);
  void RangeUpdate(int,int,int,int,int);
  int GetSum(int,int,int,int);
  int ComputeMid(int,int);
};

SegmentTree::SegmentTree(int W){
  int height = int(ceil(log2(W)));

  no_of_nodes = 2*int(pow(2,height))-1;

  segment_tree = new int[no_of_nodes];
  lazy_array = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    segment_tree[i] = lazy_array[i] = 0;
  
}

int SegmentTree::ComputeMid(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}

void SegmentTree::RangeUpdate(int node, int node_left, int node_right, int left, int right){
  if(lazy_array[node] != 0){
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
    segment_tree[node] += (node_right - node_left+1);
    if(node_left!=node_right){
      lazy_array[2*node+1] += 1;
      lazy_array[2*node+2] += 1;
    }
    return;
  }
  
  int mid = ComputeMid(node_left, node_right);
  RangeUpdate(2*node+1, node_left, mid, left, right);
  RangeUpdate(2*node+2, mid+1, node_right, left, right);
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

int SegmentTree::GetSum(int node,int node_left, int node_right, int index){
  if(lazy_array[node]!=0){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];
    if(node_left!=node_right){
      lazy_array[2*node+1] += lazy_array[node];
      lazy_array[2*node+2] += lazy_array[node];
    }
    lazy_array[node] = 0;
  }

  if(index<node_left || index>node_right)
    return 0;

  if(node_left==node_right){
    return segment_tree[node];
  }

  int mid = ComputeMid(node_left, node_right);
  return GetSum(2*node+1, node_left, mid, index) + GetSum(2*node+2, mid+1, node_right, index);
}


int main(){
  int N,M,W,L,R, query;
  cin >> N >> M >> W;
  SegmentTree segment_tree(W);
  while(N--){
    cin >> L >> R;
    segment_tree.RangeUpdate(0, 0, W-1, L,R);
  }
  while(M--){
    cin >> query;
    cout << segment_tree.GetSum(0,0,W-1,query) << endl;
  }


}
