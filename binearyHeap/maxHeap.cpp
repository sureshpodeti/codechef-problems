#include<iostream>
#include<climits>

using namespace std;

class MaxHeap{
  int *maxHeap;
  int heapSize;
  int heapCapacity;
public:
  MaxHeap(int);
  int ParentIndex(int);
  int LeftIndex(int);
  int RightIndex(int);
  void InsertKey(int);
  void Swap(int*, int*);
  void Display();
  int GetMax();
  void DecreaseKey(int,int);
};

MaxHeap::MaxHeap(int cap){
  heapSize=0;
  heapCapacity=cap;
  maxHeap = new int[heapCapacity];
}

int MaxHeap::ParentIndex(int key){
  return (key-1)/2;
}

int MaxHeap::RightIndex(int key){
  return 2*key+1;
}
int MaxHeap::LeftIndex(int key){
  return 2*key+2;
}

void MaxHeap::InsertKey(int key){
  if(heapSize>=heapCapacity){
    cout << "Overflow" << endl;
    return;
  }

  maxHeap[heapSize] = key;
  int i = heapSize;
  heapSize++;

  while(i!=0 && maxHeap[ParentIndex(i)] < maxHeap[i]){
    Swap(&maxHeap[ParentIndex(i)], &maxHeap[i]);
    i = ParentIndex(i);
  }  
}

void MaxHeap::Swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void MaxHeap::Display(){
  for(int i=0;i<heapSize;++i)
    cout << maxHeap[i] << " ";
  cout << endl;
}

int MaxHeap::GetMax(){
  return maxHeap[0];
}

void MaxHeap::DecreaseKey(int key, int new_value){
  maxHeap[key] = new_value;
  while(key!=0 && maxHeap[ParentIndex(key)]<maxHeap[key]){
    Swap(&maxHeap[ParentIndex(key)], &maxHeap[key]);
    key = ParentIndex(key);
  }
}

int MaxHeap::ExtractMax(){
  if(heapSize<=0)
    return INT_MIN;

  if(heapSize==1){
    heapSize--;
    return maxHeap[0];
  }

  int root = maxHeap[0];
  maxHeap[0] = maxHeap[heapSize-1];
  heapSize--;
  MaxHeapify(0);
  return root;
}

void MaxHeap::MaxHeapify(int key){

  int leftKey = LeftIndex(key);
  int rightKey = RightIndex(key);

  int largest = key;

  if(leftKey < heapSize && maxHeap[key]<maxHeap[leftKey]){
    largest = leftKey;
  }
  if(rightKey < heapSize && maxHeap[largest] <maxHeap[rightKey]){
    largest = rightKey;
  }

  if(largest!=key){
    MaxHeapify(largest);
  } 
}

int main(){

  int A[] = {1,3,2,4};
  int n = sizeof(A)/sizeof(A[0]);

  MaxHeap maxHeap(n);
  for(int i=0;i<n;++i)
    maxHeap.InsertKey(A[i]);

  maxHeap.Display();

  maxHeap.DecreaseKey(3, 5);
  maxHeap.Display();
  

  return 0;
}
