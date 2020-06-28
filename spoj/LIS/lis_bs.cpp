#include<iostream>
using namespace std;

int BinarySearch(int *c, int l, int r, int key){
  if(l<r){
    int mid = l + (r-l)/2;
    if(c[mid]>=key)
      r = mid;
    else
      l = mid;
  }

  return r;
}
int LisBinarySearch(int *A, int n){
  // define an array c to store largest element of the subsequence of length i
  int *c = new int[n]; // maximum length of the increasing subsequnce is n; the size of input array A

  int length = 1; // will give the length of LIS
  c[0] = A[0];

  int l, r, idx;

  for(int i=1;i<n;++i){
    if(A[i]<c[0])
      c[0] = A[i];
    else if(A[i]>c[length-1])
      c[length++] = A[i];
    else{
      l = 0;
      r = length-1;
      idx = BinarySearch(c, l, r, A[i]);
      c[idx] = A[i];
    }
     
  }

  return length;


}
int main(){
  int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
  //int A[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  //int A[] = {1,8,4};
  int n = sizeof(A)/sizeof(A[0]);

  cout << LisBinarySearch(A, n) << endl;
  return 0;
}
