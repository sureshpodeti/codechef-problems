
#include<iostream>
using namespace std;

class MaxHeap{
    int *maxHeap;
    int heapSize;
    int capacity;
public:
    MaxHeap(int*, int);
    void insertKey(int);
    void display();
    void swapNodes(int*,int*);
    int getMax();
    int extractMax();
    void heapify(int);
    void decreaseKey(int,int);
    void deleteKey(int);
    int getParentIndex(int);
};

MaxHeap::MaxHeap(int *A, int n){
    capacity = n;
    heapSize = 0;
    maxHeap = new int[n];

    for(int i=0;i<n;++i){
        insertKey(A[i]);
    }
}

int getParentIndex(int node){
    return (node-1)/2;
}

void MaxHeap::insertKey(int key){

    if(capacity==heapSize){
        cout << "Reached maximum capacity, insertion key not allowed!" << endl;
        return;
    }
    heapSize++;
    int index = heapSize - 1;
    maxHeap[index] = key;


    while(index>0 && maxHeap[getParentIndex(index)]<maxHeap[index]){
        // swap parent and child
        swapNodes(&maxHeap[getParentIndex(index)], &maxHeap[index]);

        //set index to its parent
        index = getParentIndex(index);

    }

}

void MaxHeap::display(){
    for(int i=0;i<heapSize;++i){
        cout << maxHeap[i] << " ";
    }
    cout << endl;
}

void MaxHeap::swapNodes(int *a, int *b){
    int t = *a;
    *a  = *b;
    *b = t;
}

int MaxHeap::getMax(){
    return maxHeap[0];
}

int MaxHeap::extractMax(){
    // we want to extract the root element
    int maxElement = maxHeap[0];

    // replace the root element with the last element
    maxHeap[0] = maxHeap[heapSize-1];

    // reduce the count of heapSize
    heapSize--;

    // now the heap property is distrubed, heapify to fix it

    heapify(0);

    return maxElement;

}

void MaxHeap::heapify(int idx){
    //get the children of the current node, update with maximum among children and current node
    int leftNodeIndex =  2*idx+1;
    int rightNodeIndex = 2*idx+2;

    int largest = idx;

    if(leftNodeIndex<heapSize && maxHeap[leftNodeIndex]>maxHeap[idx])
        largest = leftNodeIndex;

    if(rightNodeIndex<heapSize && maxHeap[rightNodeIndex]>maxHeap[largest])
        largest = rightNodeIndex;

    if(largest!=idx){
        // we need to swap
        swapNodes(&maxHeap[largest], &maxHeap[idx]);
        heapify(largest);
    }
}

void MaxHeap::decreaseKey(int idx, int newValue){
    maxHeap[idx] = newValue;
    // check and fix if it voilates heap property

    while(idx>0 && maxHeap[getParentIndex(idx)]<maxHeap[idx]){
        swapNodes(&maxHeap[getParentIndex(idx)],&maxHeap[idx]);
        //update idx
        idx = getParentIndex(idx);
    }
}


void MaxHeap::deleteKey(int idx){
    decreaseKey(idx, INT_MAX);
    //now the INT_MAX stays at the root (topmost element)
    //extract it
    extractMax();

}


int main(){
    int A[] = {11,3, 2,1,15, 5,4,45};
    int n = sizeof(A)/sizeof(int);

    MaxHeap maxHeap = MaxHeap(A, n);
    maxHeap.display();

    //cout << maxHeap.getMax() << endl;
    //cout << maxHeap.extractMax() << endl;
    //maxHeap.display();



    return 0;
}
