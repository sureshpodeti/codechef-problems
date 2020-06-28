#include<iostream>
#include<cmath>
#include<set>
using namespace std;

class SegmentTree{
  int no_of_nodes;
  set<int> *segment_tree;
 public:
  SegmentTree(int *, int);
  int ComputeMidIndex(int, int);
  void Build(int, int, int, int*);
  int RangeQuery(int, int, int);
  void RangeQueryUtil(int, int, int, int, int, set<int> *);
};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));

  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new set<int>[no_of_nodes];

  Build(0, 0, n-1, A);

}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}
void SegmentTree::Build(int node, int node_left, int node_right, int *A){
  if(node_left == node_right){
    segment_tree[node].insert(A[node_left]);
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);

  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);

  for(auto it=segment_tree[2*node+1].begin();it!=segment_tree[2*node+1].end();++it)
    segment_tree[node].insert(*it);

  for(auto it=segment_tree[2*node+2].begin();it!=segment_tree[2*node+2].end();++it)
    segment_tree[node].insert(*it);
}

int SegmentTree::RangeQuery(int n, int left, int right){
  set<int> result;
  RangeQueryUtil(0, 0, n-1, left, right, &result);
  
  return result.size();
}


void SegmentTree::RangeQueryUtil(int node, int node_left, int node_right, int left, int right, set<int> *result){

  if(left>node_right || right<node_left){
    return;
  }
  if(left<=node_left && right>=node_right){
    for(auto it=segment_tree[node].begin();it!=segment_tree[node].end();++it)
      result->insert(*it);
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  RangeQueryUtil(2*node+1, node_left, mid, left, right, result);
  RangeQueryUtil(2*node+2, mid+1, node_right, left, right, result);
}


int main(){
  int A[] ={ 1, 1, 2, 1, 3 };
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A, n);

  int q, l ,r ;
  cin >> q;

  while(q--){
    cin >> l >> r;
    cout << segment_tree.RangeQuery(n, l, r) << endl;
  }
 
  return 0;
}
