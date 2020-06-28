#include<iostream>
using namespace std;

int PartitionIndex(int *A, int l, int r){
  int pivot = r;
  int pIndex=l;
  for(int i=l;i<r;++i){
    if(A[i]<=A[pivot]){
      swap(A[i], A[pIndex]);
      pIndex++;
    }
  }
  swap(A[pIndex], A[pivot]);
  return pIndex;
}

void QuickSort(int A[], int l, int r){
  if(l>=r) return;
  int pIndex = PartitionIndex(A, l, r);
  QuickSort(A, l, pIndex-1);
  QuickSort(A, pIndex+1, r);
}

int main(){
  //int A[] = {10, 7, 8, 9, 1, 5};
  int A[] = {8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(A)/sizeof(A[0]);

  int l,r;
  l = 0;
  r = n-1;

  QuickSort(A, l, r);

  
  for(int i=0;i<n;++i)
    cout << A[i] << " ";
  cout << endl;

  return 0; 
}
