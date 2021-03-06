#include<iostream>
#include<cmath>
#define CUT_OFF -15008
using namespace std;


class Node{
public:
  int neg_value_count;
  int neg_value;
  int pos_value;
};
class SegmentTree{
  int no_of_nodes;
  Node *segment_tree;
public:
  SegmentTree(int*, int);
  int ComputeMidIndex(int, int);
  void Build(int, int, int, int*);
  void Display();
  int RangeQuery(int, int, int);
  Node *RangeQueryUtil(int, int, int, int, int);

};

SegmentTree::SegmentTree(int *A, int n){
  int height = int(ceil(log2(n)));
  no_of_nodes = 2*int(pow(2, height))-1;

  segment_tree = new Node[no_of_nodes];
  
  for(int i=0;i<no_of_nodes;++i){
    segment_tree[i].neg_value_count = 0;
    segment_tree[i].neg_value =  CUT_OFF;
    segment_tree[i].pos_value = 0;
  }
 
  Build(0, 0, n-1, A);

}
int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}

void SegmentTree::Build(int node, int node_left, int node_right, int *A){
  if(node_left==node_right){
    if(A[node_left]<0){
      segment_tree[node].neg_value_count += 1;
      segment_tree[node].neg_value = A[node_left];
    }else{
      segment_tree[node].pos_value = A[node_left];
    }
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  Build(2*node+1, node_left, mid, A);
  Build(2*node+2, mid+1, node_right, A);


  int neg_count = segment_tree[2*node+1].neg_value_count + segment_tree[2*node+2].neg_value_count;
  segment_tree[node].neg_value_count = neg_count;
  if(neg_count  == (node_right - node_left+1)){
    // all are negative numbers
    segment_tree[node].neg_value =  max(segment_tree[2*node+1].neg_value, segment_tree[2*node+2].neg_value);
  }else{
    //we have some or all positive numbers
    segment_tree[node].pos_value = segment_tree[2*node+1].pos_value + segment_tree[2*node+2].pos_value;
    segment_tree[node].neg_value = max(segment_tree[2*node+1].neg_value, segment_tree[2*node+2].neg_value);
  }
}

int SegmentTree::RangeQuery(int n, int x, int y){
  Node *node = RangeQueryUtil(0, 0, n-1, x-1, y-1);
  if(node==nullptr)
    return CUT_OFF;
  return max(node->neg_value, node->pos_value);
}

Node *SegmentTree::RangeQueryUtil(int node, int node_left, int node_right, int left, int right){
  if(left>node_right || right<node_left){
    return nullptr; 
  }

  if(left<=node_left && right>=node_right){
    return &segment_tree[node];
  }
    
  int mid = ComputeMidIndex(node_left, node_right);
  Node *left_node = RangeQueryUtil(2*node+1, node_left, mid, left, right);
  Node *right_node = RangeQueryUtil(2*node+2, mid+1, node_right, left, right);

  if(left_node!=nullptr && right_node!=nullptr){
    Node *n;
    int neg_total = left_node->neg_value_count + right_node->neg_value_count;
    n->neg_value_count = neg_total;
    if(neg_total==(node_right-node_left+1)){
      // all negative numbers
      n->neg_value = max(left_node->neg_value, right_node->neg_value);
    }else{
      // we have some or all positive values
       n->neg_value = max(left_node->neg_value, right_node->neg_value);
       n->pos_value = left_node->pos_value + right_node->pos_value;
       return n;
    }

  }else if(left_node==nullptr && right_node!=nullptr){
    return right_node;
  }else if(left_node!=nullptr && right_node==nullptr){
    return left_node;
  }
  return nullptr;
  
}

void SegmentTree::Display(){
  for(int i=0;i<no_of_nodes;++i){
    cout << "(" << segment_tree[i].neg_value_count << "," << segment_tree[i].neg_value << "," << segment_tree[i].pos_value << ")" << endl;
  }
  cout << endl;
}

int main(){
  int N, M, x, y;
  cin >> N;
  int A[N];
  for(int i=0;i<N;++i)
    cin >> A[i];

  SegmentTree segment_tree(A, N);
  segment_tree.Display();
  
 
  cin >> M;

  
  while(M--){
    cin >> x >> y;
    cout << segment_tree.RangeQuery(N, x, y) << endl;
  }
  
  return 0;
}
