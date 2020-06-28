
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


class MinHeap{
    int *minHeap; // array to store the minheap elements
    int capacity;
    int heapSize;

public:
    MinHeap(int);
    void insertKey(int);
    int getParentIndex(int);
    void display();
    void swapNodes(int*, int*);
    int extractMin();


};

MinHeap::MinHeap(int cap){
    heapSize = 0;
    capacity = cap;

    minHeap = new int[capacity];
}

int MinHeap::getParentIndex(int i){
    return (i-1)/2;
}


void MinHeap::swapNodes(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void MinHeap::insertKey(int k){

    // if heapsize is already equal to capacity
     if(capacity==heapSize){
            cout << "\nOverFlow: Could not insert key\n" << endl;
            return;
     }

     heapSize++;
     int index = heapSize - 1;
     //insert the key at the index
     minHeap[index] = k;

    // check if minheap properties satisfies
    while(index!=0 && minHeap[getParentIndex(index)] > minHeap[index]){
        swapNodes(&minHeap[index], &minHeap[getParentIndex(index)]);
        //update i to its parents index
        index = getParentIndex(index);
    }

}

void MinHeap::display(){
    for(int i=0;i<heapSize;++i)
        cout << minHeap[i] << " ";
    cout << endl;
}


int MinHeap::extractMin(){
    if(heapSize<=0){
        return INT_MAX;
    }

    if(heapSize==1){
        heapSize--;
        return minHeap[0];
    }

    heapSize--;
    int root = minHeap[0];
    // extract the root element and copy the last element to to root node
    minHeap[0] = minHeap[heapSize];

    minHeapify(0);

    return root;
}


void MinHeap::minHeapify(int idx){
    //left subtree
    int left = 2*idx+1;
    int right = 2*idx+2;

    int smallNodeIndex=idx;

    if(left<heapSize && minHeap[idx]>minHeap[left]){
        smallNodeIndex = left;
    }

    if(right<heapSize && minHeap[idx]>minHeap[right]){
        smallNodeIndex = right;
    }

    if(smallNodeIndex!=idx){
        swap(&minHeap[idx], &minHeap[smallNodeIndex]);
        minHeapify(smallNodeIndex);

    }


}

int main(){

    minHeap.insertKey(3);
    minHeap.insertKey(2);
    minHeap.insertKey(1);
    minHeap.insertKey(15);
    minHeap.insertKey(5);
    minHeap.insertKey(4);
    minHeap.insertKey(45);


    minHeap.display();


    return 0;
}
