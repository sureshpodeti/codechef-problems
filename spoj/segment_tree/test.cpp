#include<iostream>
using namespace std;

bool IncBySec(pair<int, int> p1, pair<int, int> p2){
  return p1.second<p2.second;
}
void SortArray(pair<int, int> *p, int n ){
  sort(p,p+n, IncBySec);

  for(int i=0;i<n;++i)
    cout << p[i].first << "-" << p[i].second << endl;
  cout << endl;

}
int main(){
  int n = 3;
  pair<int, int> p[n];

  p[0].first = 10;
  p[0].second = 9;

  p[1].first = 30;
  p[1].second = 1;

  p[2].first = 12;
  p[2].second =12;


  SortArray(p, n);
  
  
 
  return 0;
}
