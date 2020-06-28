#include<iostream>
#include<vector>
using namespace std;


int main(){
  int A[] = {5, 8, 7, 7, 8, 5, 5, 8};
  int n = sizeof(A)/sizeof(A[0]);
  vector<int> v(A, A+n);

  sort(v.begin(), v.end());
  // sorte list: 5, 5, 5, 6, 6, 6, 7, 7

  vector<int>::iterator low_itr, upper_itr;

  low_itr = lower_bound(v.begin(), v.end(), 6);
  upper_itr = upper_bound(v.begin(), v.end(), 6);

  cout << "lower bound:" << (low_itr - v.begin()) << endl;
  cout << "upper bound:" << (upper_itr - v.begin()) << endl; 
  return 0;
}
