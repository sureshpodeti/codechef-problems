#include<iostream>
#include<cmath>
using namespace std;
class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
public:
  SegmentTree(int*, int);
  void GetKthSetBitUtil(int,int,int,int);
  void GetKthSetBit(int, int);
  int ComputeMidIndex(int,int);
  void Build(int, int, int, int*);
  void UpdateNode(int, int, int);
  void UpdateNodeUtil(int, int, int, int, int);
};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new int[no_of_nodes];  
  Build(0, 0, n-1, A);
}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right-node_left)/2;
}

void SegmentTree::Build(int node, int node_left, int node_right, int *A){
  if(node_left==node_right){
    segment_tree[node] = A[node_left];
    return;
  }
  int mid = ComputeMidIndex(node_left, node_right);
  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

void SegmentTree::GetKthSetBitUtil(int node, int node_left, int node_right, int k){
  if(node_left==node_right){
    cout << "Index:" << node_left << endl;
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  // get the left tree value
  int curr_value = segment_tree[node];
  int left_value = segment_tree[2*node+1];

  if(k<=left_value){
    GetKthSetBitUtil(2*node+1, node_left, mid, k);
  }else{
    GetKthSetBitUtil(2*node+2, mid+1, node_right, k-left_value);
  }
}

void SegmentTree::GetKthSetBit(int n, int k){
  if(k>segment_tree[0]){
    cout << "Kth bit not found; Kth bit is Out of range" << endl;
    return;
  }
  GetKthSetBitUtil(0, 0, n-1, k);
}


void SegmentTree::UpdateNodeUtil(int node, int node_left, int node_right, int x, int y){
  if(x<node_left || x>node_right)
    return;

  if(node_left==node_right){
    segment_tree[node] = y;
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  UpdateNodeUtil(2*node+1, node_left, mid, x, y);
  UpdateNodeUtil(2*node+2, mid+1, node_right, x, y);
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}


void SegmentTree::UpdateNode(int n, int x, int y){
  if(x>=n){
    cout << "No Update done!. Out of range" << endl;
    return;
  }

  UpdateNodeUtil(0, 0, n-1, x, y);
}

int main(){
  int A[] = {1,0,1,0,0,1,1,1};
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A,n);
  for(int i=1;i<=n;++i){
    segment_tree.GetKthSetBit(n, i);
  }

  segment_tree.UpdateNode(n, 4, 1);
  for(int i=1;i<=n;++i){
    segment_tree.GetKthSetBit(n, i);
  }
  
  return 0;
}
