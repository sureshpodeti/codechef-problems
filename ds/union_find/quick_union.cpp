
#include<iostream>


using namespace std;

class QuickUnionUF{
  int *A;
  int no_of_objects;
public:
  QuickUnionUF(int);
  bool Find(int, int);
  void Union(int,int);
  int GetParent(int);
};


QuickUnionUF::QuickUnionUF(int n){
  no_of_objects = n;
  A = new int[ no_of_objects];
  

  for(int i=0;i< no_of_objects;++i)
    A[i] = i;
}

int QuickUnionUF::GetParent(int obj){
  while(A[obj] != obj)
    obj = A[obj];
  return obj;
}

bool QuickUnionUF::Find(int p, int q){
  int parent_p = GetParent(p);
  int parent_q = GetParent(q);

  return parent_p == parent_q;
}
void QuickUnionUF::Union(int p,int q){
  // get the value stored in q
  int pid = GetParent(p);
  int qid = GetParent(q);

  A[pid] = qid;
}
int main(){
  int n, query_type, p, q;
 
  cin >> n;
  
  QuickUnionUF quick_unionobj = QuickUnionUF(n);

  //convention query type 1: to union
  // query type 2: to find
  
  while(cin >> query_type >> p >> q){

    if(query_type==1){
      quick_unionobj.Union(p,q);
    }else{
      cout << quick_unionobj.Find(p,q) << endl;
    }
    

  }


  


  return 0;
}
