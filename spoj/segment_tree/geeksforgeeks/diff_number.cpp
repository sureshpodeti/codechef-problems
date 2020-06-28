#include<iostream>
#include<cmath>
#include<set>
using namespace std;

set<int> S;


class SegmentTree{
  int no_of_nodes;
  int *lazy_array;
public:
  SegmentTree(int);
  int ComputeMidIndex(int,int);
  void Update(int,int,int,int,int,int);
  void Query(int,int,int);
};


SegmentTree::SegmentTree(int n){
  int height = int(ceil(log2(n)));

  no_of_nodes = 2*int(pow(2, height)) - 1;

  lazy_array = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    lazy_array[i] = 0;
}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}

void SegmentTree::Update(int node, int node_left, int node_right, int left, int right, int x){
    if(lazy_array[node]){
      if(node_left!=node_right){
	lazy_array[2*node+1] = lazy_array[2*node+2] = lazy_array[node];
	lazy_array[node] = 0;
      }
    }
    
    if(right<node_left || left>node_right)
      return;

    if(left<=node_left && right>=node_right){
      lazy_array[node] = x;
      return;
    }
    int mid = ComputeMidIndex(node_left, node_right);
    Update(2*node+1, node_left, mid, left, right, x);
    Update(2*node+2, mid+1, node_right, left, right, x);
}

void SegmentTree::Query(int node, int node_left, int node_right){
  if(lazy_array[node]){
    S.insert(lazy_array[node]);
    return;
  }

  if(node_left==node_right){
    return;
  }

  

  int mid = ComputeMidIndex(node_left, node_right);

  Query(2*node+1, node_left, mid);
  Query(2*node+2, mid+1, node_right);
}

int main(){
  int n, Q;
  cin >> n >> Q;

  SegmentTree segment_tree(n);
  int l,r, x;
  while(Q--){
    cin >> l >> r >> x;
    segment_tree.Update(0, 0, n-1, l, r, x);
  }
  
  segment_tree.Query(0, 0, n-1);

  cout << S.size() << endl;
  
  
  
  return 0;
}
