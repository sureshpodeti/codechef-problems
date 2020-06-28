#include<iostream>
#include<set>

using namespace std;

int main(){
  set<int> a;
  set<int> b;
  set<int> c;
  a.insert(10);
  a.insert(20);

  b.insert(30);
  b.insert(40);
  b.insert(50);

  for(auto it=a.begin();it!=a.end();++it){
    c.insert(*it);
  }

   for(auto it=b.begin();it!=b.end();++it){
    c.insert(*it);
  }



   for(auto it=c.begin();it!=c.end();++it)
     cout << *it << " ";
   cout << endl;

  

  cout << c.size() << endl;
  return 0;
}
