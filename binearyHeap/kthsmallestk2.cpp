#include<iostream>
using namespace std;

class MinHeap{
  int heapCapacity;
  int *minHeap;
public:
  MinHeap(int);
  int ParentIndex(int);
  int LeftIndex(int);
  int RightIndex(int);
};

MinHeap::MinHeap(int cap){
  heapCapacity = cap;
  minHeap = new int[heapCapacity];
}

int MinHeap::ParentIndex(int i){
  return (i-1)/2;
}

int MinHeap::LeftIndex(int i){
  return 2*i+1;
}

int MinHeap::RightIndex(int i){
  return 2*i+2;
}

int 


int main(){

  int A[] = {10, 50, 40, 75, 60, 65, 45};
  int n = sizeof(A)/sizeof(A[0]);

  int k = 2;

  MinHeap minHeap(n);
  

  return 0;
}
