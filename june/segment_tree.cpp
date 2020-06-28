#include<iostream>
#include<cmath>
using namespace std;


class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
  int *lazy_array;
public:
  SegmentTree(int*, int);
  void Display();
  void Build(int *,int,int,int);
  int GetSum(int,int,int,int,int);
  void Update(int,int,int,int,int);
  void RangeUpdate(int,int,int,int,int,int);
  int RangeQuerySum(int,int, int, int, int);
  
};

SegmentTree::SegmentTree(int *A, int n){
  int height = 2*pow(2, n) -1;
  
  no_of_nodes = height;

  segment_tree = new int[height];
  lazy_array = new int[height];

  //initialize the segment tree
  for(int i=0;i<no_of_nodes;++i)
     segment_tree[i] = lazy_array[i] = 0;


  //build the segment tree
  Build(A, 0, 0, n-1);

}

void SegmentTree::Display(){
  for(int i=0;i<no_of_nodes;++i)
    cout << segment_tree[i] << " ";
  cout << endl;
}


void SegmentTree::Build(int *A, int node, int left, int right){
  if(left==right){
    segment_tree[node] = A[left]; 
    return;
  }

  int mid = left + (right-left)/2;

  //first build left,right subtree
  Build(A, 2*node+1, left, mid);
  Build(A, 2*node+2, mid+1, right);

  //update the current node
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}


int SegmentTree::GetSum(int node, int node_left, int node_right, int left, int right){

  if(left<= node_left && right>=node_right){
    return segment_tree[node];
  }


  if(right<node_left || left>node_right){
     return 0;
  }
   

  int mid = node_left + (node_right - node_left)/2;
  

  int left_sum =  GetSum(2*node+1,node_left, mid, left, right);
  int right_sum = GetSum(2*node+2,mid+1, node_right, left, right);

  return left_sum + right_sum;

}

void SegmentTree::Update(int node, int node_left, int node_right, int index, int value){

   if(index< node_left || index>node_right){
    return;
  }
   
  if(node_left==node_right){
    //update the node value
    segment_tree[node] = value;
    return;
  }


  int mid = node_left + (node_right - node_left)/2;

  //first update the left, right subtrees
  Update(2*node+1, node_left, mid, index, value);
  Update(2*node+2, mid+1, node_right, index, value);
  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}


int SegmentTree::RangeQuerySum(int node, int node_left, int node_right, int left, int right){

  // as we are visiting we may come to node which has pending update
  if(lazy_array[node]!=0){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];

    if(node_left!=node_right){
      lazy_array[2*node+1] += lazy_array[node];
      lazy_array[2*node+2] += lazy_array[node];
    }

    lazy_array[node] = 0;
  }

  if(right < node_left || left > node_right)
    return 0;


  if(left<=node_left && right>=node_right)
    return segment_tree[node];
  

  int mid = node_left + (node_right - node_left)/2;

  return RangeQuerySum(2*node+1, node_left, mid, left, right) + RangeQuerySum(2*node+2, mid+1, node_right, left, right);
}


void SegmentTree::RangeUpdate(int node, int node_left, int node_right, int left, int right , int update_val){


  //process any pending updates for the current node
  if(lazy_array[node]!=0){
    segment_tree[node] += (node_right - node_left+1)*lazy_array[node];
    
    //mark the childrens update as pending
    //down propagate the update to children
    //but what if current node does not have any children
    //check if the node is leaf

    if(node_left!=node_right){
       lazy_array[2*node+1] += lazy_array[node];
       lazy_array[2*node+2] += lazy_array[node];
    }
   

    //clear the current node pending
    lazy_array[node] = 0;
  }

  //if the nodes range is outside
  if(right<node_left || left>node_right)
    return;

  if(left<=node_left && right>=node_right){
    segment_tree[node] += (node_right - node_left+1)*update_val;

    if(node_left!=node_right){
      lazy_array[2*node+1] += update_val;
      lazy_array[2*node+2] += update_val;
    }
    return;
  }


  int mid = node_left + (node_right - node_left)/2;

  RangeUpdate(2*node+1, node_left, mid, left, right, update_val);
  RangeUpdate(2*node+2, mid+1, node_right, left, right, update_val);

  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
  
 
}

void Print(SegmentTree segment_tree,int n){
  cout << segment_tree.GetSum(0, 0,n-1, 0,2) << endl;
  cout << segment_tree.GetSum(0, 0, n-1, 0,1) << endl;
  cout << segment_tree.GetSum(0, 0, n-1,  0,3) << endl;
  cout << segment_tree.GetSum(0, 0, n-1, 1,2) << endl;
  cout << segment_tree.GetSum(0, 0,n-1, 1,3) << endl;

}





int main(){
  int A[] = {1,3,4,2};
  int n = sizeof(A)/sizeof(A[0]);

  SegmentTree segment_tree(A, n);
  segment_tree.Display();

  Print(segment_tree, n);


  /*
  //update a node
  segment_tree.Update(0, 0, n-1, 3, 5);

  cout << "After update:" << endl;
  Print(segment_tree, n);

  segment_tree.Display();
  */

  cout << "Range queries: " << endl;

  cout << segment_tree.RangeQuerySum(0, 0, n-1, 1,2) << endl;
  cout << segment_tree.RangeQuerySum(0, 0, n-1, 2,3) << endl;


  segment_tree.RangeUpdate(0, 0, n-1, 2, 3, 2);
  cout << segment_tree.RangeQuerySum(0, 0, n-1, 1,2) << endl;
  cout << segment_tree.RangeQuerySum(0, 0, n-1, 2,3) << endl;
  
  return 0;
}
