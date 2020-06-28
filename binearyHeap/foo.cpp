#include<iostream>
#include<climits>
using namespace std;

class MinHeap{
  int heapSize;
  int heapCapacity;
  int *minHeap;
public:
  MinHeap(int);
  int ParentIndex(int);
  int LeftIndex(int);
  int RightIndex(int);
  void InsertKey(int);
  void Display();
  int GetMin();
  void MinHeapify(int);
  int ExtractMin();
  void DecreaseKey(int,int);
  void DeleteKey(int);
};

MinHeap::MinHeap(int cap){
  heapSize = 0;
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
void MinHeap::InsertKey(int key){
  if(heapSize>=heapCapacity){
    cout << "overflow" << endl;
    return;
  }

  minHeap[heapSize] = key;
  int i = heapSize;
  heapSize++;

  while(i>0 && minHeap[ParentIndex(i)] > minHeap[i]){
    swap(minHeap[ParentIndex(i)], minHeap[i]);
    i = ParentIndex(i);
  }
}

void MinHeap::Display(){
  for(int i=0;i<heapSize;++i)
    cout << minHeap[i] << " ";
  cout << endl;
}

int MinHeap::GetMin(){
  return minHeap[0];
}
int MinHeap::ExtractMin(){
  if(heapSize<=0){
    return INT_MAX;
  }

  if(heapSize==1)
    return minHeap[0];
  
  int root = minHeap[0];
  minHeap[0] = minHeap[heapSize-1];
  heapSize--;

  MinHeapify(0);
  return root;
}
void MinHeap::MinHeapify(int i){
  int leftIndex = LeftIndex(i);
  int rightIndex = RightIndex(i);

  int smallestIndex = i;

  if(leftIndex<heapSize && minHeap[leftIndex]<minHeap[i]){
    smallestIndex = leftIndex;
  }

  if(rightIndex<heapSize && minHeap[rightIndex]< minHeap[smallestIndex]){
    smallestIndex = rightIndex;
  }

  if(i!=smallestIndex){
    swap(minHeap[smallestIndex], minHeap[i]);
    MinHeapify(smallestIndex);
  }
}

void MinHeap::DecreaseKey(int i, int newValue){
  /* decrease the value of key at i to newValue;
     assumption: i is valid index, new value is less than the previous value*/
  minHeap[i] = newValue;

  while(i> 0 && minHeap[ParentIndex(i)] < minHeap[i]){
    swap(minHeap[ParentIndex(i)], minHeap[i]);
    i = ParentIndex(i);
  }
}

void MinHeap::DeleteKey(int i){
  DecreaseKey(i, INT_MIN);
  ExtractMin();
}


int main(){
  int A[] = {1,3,4,2};
  int n = sizeof(A)/sizeof(A[0]);

  MinHeap minHeap(n);

  for(int i=0;i<n;++i)
    minHeap.InsertKey(A[i]);

  minHeap.Display();

  cout << minHeap.ExtractMin() << endl;
  minHeap.Display();

  
  return 0;
}
