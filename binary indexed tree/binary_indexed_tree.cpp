#include<iostream>

using namespace std;

class BITree{
  int no_of_nodes;
  int *bi_tree;
public:
  BITree(int*, int);
  int GetSum(int);
  void UpdateBITree(int,int);
};


BITree::BITree(int *A, int n){
  no_of_nodes = n;
  bi_tree = new int[no_of_nodes+1];

  // initialize the binary index tree with all 0's initially
  for(int i=1;i<=no_of_nodes;++i)
    bi_tree[i] = 0;

  //update the tree
  for(int i=0;i<n;++i)
    UpdateBITree(i+1, A[i]);

  
}

void BITree::UpdateBITree(int index, int value){

  while(index<=no_of_nodes){
    // first element of the binary index tree
    bi_tree[index] += value;


      //update index value to its parents
      index += index &  (-index);
  }
}


int BITree::GetSum(int index){
  int result = 0;

  while(index>0){
    result += bi_tree[index];
    index -= index &(-index);
  }
  return result;
}
int main(){
  int A[] = {1,3,2}; 
  int n = sizeof(A)/sizeof(A[0]);

  BITree bi_tree(A, n);
  
  cout << "Sum of elements in arr[1..2] is "
       << bi_tree.GetSum(2) << endl; 
  
  // Let use test the update operation 
  bi_tree.UpdateBITree(3, 6);
  
    cout << "\nSum of elements in arr[1..2] after update is "
	 << bi_tree.GetSum(3) << endl;
  
  

  
  return 0;
}
