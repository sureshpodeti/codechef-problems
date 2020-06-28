#include<iostream>

using namespace std;

class BITree{
  int no_of_nodes;
  int *bindex_tree;
public:
  BITree(int *,int);
  void ConstructBITree(int, int);
  int GetSum(int);
};
BITree::BITree(int *A, int n){
  no_of_nodes = n;
  bindex_tree = new int[no_of_nodes+1];
  for(int i=1;i<=no_of_nodes;++i){
    bindex_tree[i] = 0;
  }

  for(int i=0;i<n;++i)
    ConstructBITree(i+1, A[i]);
}

void BITree::ConstructBITree(int index, int value){
  while(index<=no_of_nodes){
    bindex_tree[index] += value;
    index += index&(-index);
  }
}

int BITree::GetSum(int index){
  int result=0;
  while(index>0){
    result += bindex_tree[index];
    index -= index &(-index);
  }
  return result;

}


int main(){
  int A[] = {1,3,2};
  int n = sizeof(A)/sizeof(A[0]);
  BITree bindex_tree(A, n);
  

  cout << bindex_tree.GetSum(3) << endl;
  cout << bindex_tree.GetSum(2) << endl;
  cout << bindex_tree.GetSum(1) << endl;


  bindex_tree.ConstructBITree(3, 2);

  cout << bindex_tree.GetSum(3) << endl;
  cout << bindex_tree.GetSum(2) << endl;

  return 0;
}
