#include<iostream>
#include<vector>
using namespace std;

int compute_lis(int *A, int n){
  // define dp array; ith element will store LIS value of array[0..i]
  int *dp = new int[n];

  for(int i=0;i<n;++i)
    dp[i] = 1;


  for(int i=1;i<n;++i){
    for(int j=0;j<i;++j){
      if(A[j]<=A[i] && dp[j]+1>dp[i]){
	dp[i]++;
      }
    }
  }

  int index = 0;
  int value = 0;
  //get the index of maximum value of dp array
  for(int i=0;i<n;++i){
    if(value<dp[i])
      index = i;
  }
 
  vector<int> vect;
  int curr = 1;
  for(int i=0;i<=index;++i){
    if(dp[i]+1>curr && A[i]<=A[index]){
      curr++;
      vect.push_back(A[i]);
    }
  }

  //print the vector
  for(auto it=vect.begin();it!=vect.end();++it)
    cout << *it << " ";
  cout << endl;

  
  return dp[index];

}



int main(){
  //int A[] = {1,3,2,4};
  //int A[] = {3,10,2,1,20};
  int A[] = {50, 3, 10, 7, 40, 80};
  int n = sizeof(A)/sizeof(A[0]);
  cout << compute_lis(A, n) << endl;
  return 0;
}
