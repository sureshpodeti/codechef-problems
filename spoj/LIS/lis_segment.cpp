#include<iostream>
#include<cmath>
using namespace std;


class SegmentTree{
public:
  int no_of_nodes;
  int *segment_tree;
public:
  SegmentTree(pair<int,int>*, int);
  int GetRangeValue(int,int,int,int,int);
  void UpdateIndex(int,int,int,int,int);
  int GetMidIndex(int,int);
  
};

SegmentTree::SegmentTree(pair<int,int> *p, int n){
  int height = int(ceil(log2(n)));

  no_of_nodes = 2*int(pow(2,height))-1;

  segment_tree = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    segment_tree[i] = 0;


  int value;
  for(int i=0;i<n;++i){
    value = 0;
    if(p[i].second != 0)
      value = GetRangeValue(0, 0, n-1, 0, p[i].second-1);
    UpdateIndex(0, 0, n-1, p[i].second, value+1);
  }


}

int SegmentTree::GetMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}


void SegmentTree::UpdateIndex(int node, int node_left, int node_right,int index, int value){

  if(index<node_left || index>node_right)
    return;

  if(node_left == node_right){
    segment_tree[node]  = value;
    return;
  }

  int mid = GetMidIndex(node_left, node_right);
  UpdateIndex(2*node+1, node_left, mid, index, value);
  UpdateIndex(2*node+2, mid+1, node_right, index, value);
  segment_tree[node] = max(segment_tree[2*node+1], segment_tree[2*node+2]);
}
int SegmentTree::GetRangeValue(int node, int node_left, int node_right, int left, int right){

  if(right<node_left || left>node_right)
    return 0;

  if(node_left == node_right)
    return segment_tree[node];
    

  int mid = GetMidIndex(node_left, node_right);
  return max(GetRangeValue(2*node+1, node_left, mid, left, right),
	     GetRangeValue(2*node+2, mid+1, node_right, left, right));
}


int main(){
  //int A[] = {1,3,2,4};
  //int A[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int A[] = {5, 1, 3, 9};
  int n = sizeof(A)/sizeof(A[0]);

  pair<int,int> p[n];
  for(int i=0;i<n;++i){
    p[i].first = A[i];
    p[i].second = i;
  }

  sort(p, p+n);

  SegmentTree segment_tree(p,n);
  cout << segment_tree.segment_tree[0] << endl;
  
  return 0;
}
