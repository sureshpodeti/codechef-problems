#include<iostream>
#include<sstream>
using namespace std;

int main(){
  int n,q;

  cin >> n >> q;

  string seq;
  cin >> seq;

  int seq_array[n];

  for(int i=0;i<n;++i){
    seq_array[i] = seq[i] - '0';
  }

  
  return 0;
}
