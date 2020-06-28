/*
  Merge sort algorithm: 
  time complexity: O(n*log(n))
  space complexity: O(n)
  
 */

#include<iostream>
using namespace std;

void Merge(int *A,int l, int m, int r){
  int leftLen = (m-l+1);
  int rightLen = (r-m);

  int leftArray[leftLen], rightArray[rightLen];

  for(int i=0;i<leftLen;++i)
    leftArray[i] = A[l+i];

  for(int i=0;i<rightLen;++i)
    rightArray[i] = A[m+1+i];

  int i,j,k;
  i = l;
  j=k=0;

  while(j<leftLen && k<rightLen){
    if(leftArray[j]<rightArray[k]){
      A[i] = leftArray[j];
      j++;
    }else{
      A[i]  = rightArray[k];
      k++;
    }

     i++;
  }


  if(j<leftLen){
    for(int u=j;u<leftLen;u++){
      A[i] = leftArray[u];
      ++i;
    }
  }

   if(k<rightLen){
    for(int u=k;u<rightLen;u++){
      A[i] = rightArray[u];
      ++i;
    }
  }

}


void MergeSort(int *A, int l, int r){
  if(l>=r){
    return;
  }
  int mid = l+(r-l)/2;
  MergeSort(A, l, mid);
  MergeSort(A,mid+1,r);

  Merge(A, l, mid, r);
  
}

int main(){
  //int A[] = {1,3, 2, 4};
  int A[] = {12, 11, 13, 5, 6, 7}; 
  int n = sizeof(A)/sizeof(A[0]);

  int l, r;
  l = 0;
  r = n-1;

  MergeSort(A, l, r);

  for(int i=0;i<n;++i)
    cout << A[i] << " ";
  cout << endl;

  return 0;
}
