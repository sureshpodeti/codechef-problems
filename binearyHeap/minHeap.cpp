#include<iostream>
#include<cmath>
using namespace std;

class MinHeap{
  int *minHeap;
  int heapCapacity;
  int heapSize;
public:
  MinHeap(int);
  int Parent(int);
  void InsertKey(int);
  void Display();
  void Swap(int*, int*);
  int LeftKey(int);
  int RightKey(int);
  int GetMin();
  int ExtractMin();
  void MinHeapify(int);
  void DeleteKey(int);
  void DecreaseKey(int, int);
};

MinHeap::MinHeap(int cap){
  heapCapacity = cap;
  heapSize=0;
  minHeap = new int[heapCapacity];
}
int MinHeap::Parent(int i){
  return (i-1)/2;
}
void MinHeap::InsertKey(int key){
  if(heapSize==heapCapacity){
    cout << "Overflow: Could not insert key" << endl;
    return;
  }
  minHeap[heapSize] = key;
  int i  = heapSize;
  heapSize++;

  while(i!=0 && minHeap[Parent(i)]>minHeap[i]){
    Swap(&minHeap[Parent(i)], &minHeap[i]);
    i = Parent(i);
  }
}

void MinHeap::Display(){
  for(int i=0;i<heapSize;++i)
    cout << minHeap[i] << " ";
  cout << endl;
}
void MinHeap::Swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int MinHeap::GetMin(){
  return minHeap[0];
}

void MinHeap::DecreaseKey(int key, int new_value){
  minHeap[key] = new_value;
  if(key!=0 && minHeap[Parent(key)]>minHeap[key]){
    Swap(&minHeap[Parent(key)], &minHeap[key]);
    key = Parent(key);
  }
}

int MinHeap::ExtractMin(){
  if(heapSize<=0){
    return INT_MAX;
  }
  if(heapSize==1){
    return minHeap[0];
  }

  int root = minHeap[0];
  minHeap[0] = minHeap[heapSize-1];
  heapSize--;
  MinHeapify(0);
  return root;
}

int MinHeap::LeftKey(int key){
  return 2*key+1;
}

int MinHeap::RightKey(int key){
  return 2*key+2;
}
void MinHeap::MinHeapify(int key){
  int left_key = LeftKey(key);
  int right_key = RightKey(key);

  int smallest_value_key = key;
  if(left_key<heapSize && minHeap[key]>minHeap[left_key]){
    smallest_value_key = left_key;
  }
  if(right_key<heapSize && minHeap[smallest_value_key]>minHeap[right_key]){
    smallest_value_key = right_key;
  }

  if(key!=smallest_value_key){
    Swap(&minHeap[key], &minHeap[smallest_value_key]);
    MinHeapify(smallest_value_key);
  }
}

void MinHeap::DeleteKey(int key){
  DecreaseKey(key, INT_MIN);
  ExtractMin();
}
int main(){
  MinHeap minHeap(11);
  minHeap.InsertKey(3);
  minHeap.InsertKey(2);
  minHeap.InsertKey(1);
  minHeap.InsertKey(15);
  minHeap.InsertKey(5);
  minHeap.InsertKey(4);
  minHeap.InsertKey(45);

  cout << minHeap.ExtractMin() << endl;
  cout << minHeap.GetMin() << endl;
  minHeap.DecreaseKey(2,1);
  cout << minHeap.GetMin() << endl;
  

  return 0;
}
