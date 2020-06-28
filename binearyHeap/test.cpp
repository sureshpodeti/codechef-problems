#include<iostream>
#include<climits>
using namespace std;

class MinHeap{
  int capacity;
  int heapSize;
  int *minHeap;
public:
  MinHeap(int);
  int ParentIndex(int);
  int LeftChildIndex(int);
  int RightChildIndex(int);
  void InsertKey(int);
  void Display();
  void DecreaseKey(int, int);
  void MinHeapify(int);
  int ExtractMin();
  int GetMin();
  
};

MinHeap::MinHeap(int cap){
  capacity = cap;
  heapSize = 0;
  minHeap = new int[capacity];
}

int MinHeap::ParentIndex(int i){
  return (i-1)/2;
}

int MinHeap::LeftChildIndex(int i){
  return 2*i+1;
}

int MinHeap::RightChildIndex(int i){
  return 2*i+2;
}

void MinHeap::InsertKey(int key){
  if(heapSize>=capacity){
    cout << "overflow: Cannot insert new key" << endl;
    return;
  }

  minHeap[heapSize] = key;
  int i = heapSize;
  heapSize++;

  while(i>0 && minHeap[ParentIndex(i)]>minHeap[i]){
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

  int root  = minHeap[0];
  minHeap[0] = minHeap[heapSize-1];
  heapSize--;
  MinHeapify(0);
  return root;
}

void MinHeap::DecreaseKey(int i, int newKey){
  //assumption: valid key, new_value<value
  minHeap[i] = newKey;

  while(i>0 && minHeap[ParentIndex(i)]>minHeap[i]){
    swap(minHeap[ParentIndex(i)], minHeap[i]);
    i = ParentIndex(i);
  }

}

void MinHeap::MinHeapify(int i){
  int leftChildIndex = LeftChildIndex(i);
  int rightChildIndex = RightChildIndex(i);

  int smallestIndex = i;

  if(leftChildIndex<heapSize && minHeap[i]>minHeap[leftChildIndex]){
    smallestIndex = leftChildIndex;
  }

  if(rightChildIndex<heapSize && minHeap[smallestIndex]>minHeap[rightChildIndex]){
    smallestIndex = rightChildIndex;
  }

  if(smallestIndex!=i){
    swap(minHeap[i], minHeap[smallestIndex]);
    MinHeapify(smallestIndex);
  }

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

  cout << minHeap.ExtractMin() << endl;
  minHeap.Display();


  cout << minHeap.ExtractMin() << endl;
  minHeap.Display();
  
 
  return 0;
}
