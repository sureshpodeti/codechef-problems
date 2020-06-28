/*
  Time complexity: O(nlog(n))
 */


#include<iostream>
#include<cmath>
#include<ctime>
#include<iomanip>
//#include "segment.h"
#include "random.h"

using namespace std;

int main(){
  srand(time(NULL));
  int n = 100000;
  int A[n];
  for(int i=0;i<n;++i)
    A[i] = rand()%100;

  time_t start, end;
  time(&start);
  long long int value = CountInversions(A, n);
  time(&end);

  double time_diff = double(end - start);

  cout << "ans:"<< value << " | time:" << setprecision(5) << (end-start);
  cout << "sec" << endl;
   
  

  
  
  

  return 0;
}
