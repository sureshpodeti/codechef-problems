#include<iostream>
using namespace std;


int found(int s, int *Q, int start, int end){

  if(start<=end){
    int mid = start + (end-start)/2;

    if(Q[mid]==s){
      return 1;
    }else if(Q[mid]>s){
      // check in  the left half
      return found(s, Q, start, mid-1);
    }else{
      return found(s, Q, mid+1, end);
    }
  }
 

  return 0;
}
int main(){
  int n,m;
  cin >> n;

  int S[n];
  for(int i=0;i<n;++i)
    cin >> S[i];

  cin >> m;
  int Q[m];
  for(int i=0;i<m;++i)
    cin >> Q[i];

  
  for(int i=0;i<n;++i){
    //check if S[i] in the Q
    if(!found(S[i], Q, 0, m-1)){
      cout << S[i] << " ";
    }
  }
  cout << endl;
   
  
  
  return 0;
}
