#include<iostream>
#include<vector>
using namespace std;


int main(){

  vector<pair<int,int> > v;
  v.push_back(pair<int,int>(6,9));
  v.push_back(pair<int,int>(1,3));
  v.push_back(pair<int,int>(2,5));
  


  sort(v.begin(), v.end());
  for(int i=0;i<3;++i)
    cout << v[i].first << "-" << v[i].second << endl;
  

  return 0;
}
