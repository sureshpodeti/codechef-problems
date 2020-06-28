#include<iostream>
#include<cmath>
using namespace std;

class MinHeap{
  int *minHeap;
  int heapSize;
  int heapCapacity;
public:
  MinHeap(int);
  int ParentIndex(int);
  int LeftIndex(int);
  int RightIndex(int);
  //void Display();
  int GetMin();
  void InsertKey(int);
  void Swap(int*, int*);
  int ExtractMin();
  void MinHeapify(int);
  
};

MinHeap::MinHeap(int cap){
  heapCapacity = cap;
  heapSize = 0;
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
/*
void MinHeap::Display(){
  for(int i=0;i<heapSize;++i)
    cout << minHeap[i] << " ";
  cout << endl;
  }
*/

int MinHeap::GetMin(){
  return minHeap[0];
}

void MinHeap::InsertKey(int key){
  if(heapSize>=heapCapacity){
    cout << "Insert not possible: Overflow" << endl;
    return;
  }

  minHeap[heapSize] = key;
  int i = heapSize;
  heapSize++;

  while(i!=0 && minHeap[ParentIndex(i)] >minHeap[i]){
    Swap(&minHeap[ParentIndex(i)], &minHeap[i]);
    i = ParentIndex(i);
  }
}

void MinHeap::Swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
int MinHeap::ExtractMin(){
  if(heapSize<=0){
    return INT_MAX;
  }

  if(heapSize==1){
    heapSize--;
    return minHeap[0];
  }


  int root = minHeap[0];
  minHeap[0] = minHeap[heapSize-1];
  heapSize--;

  MinHeapify(0);

  return root;
}

void MinHeap::MinHeapify(int i){

  int leftIndex = LeftIndex(i);
  int rightIndex = RightIndex(i);
  int smallestValueKey = i;

  if(leftIndex<heapSize && minHeap[i] >minHeap[leftIndex]){
    smallestValueKey  = leftIndex;
  }

  if(rightIndex<heapSize && minHeap[smallestValueKey] > minHeap[rightIndex]){
    smallestValueKey = rightIndex;
  }

  if(smallestValueKey!=i){
    Swap(&minHeap[i], &minHeap[smallestValueKey]);
    MinHeapify(smallestValueKey);
  }
}

void Swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a + *b;
}
int main(){
  
  int A[] = { 1, 23, 12, 9, 30, 2, 50 };
  int n = sizeof(A)/sizeof(A[0]);
  
  MinHeap minHeap(n);
  for(int i=0;i<n;++i)
    minHeap.InsertKey(A[i]);

  
  cout << minHeap.ExtractMin() << endl;
  cout << minHeap.ExtractMin() << endl;
  cout << minHeap.ExtractMin() << endl;
  
  return 0;
}
