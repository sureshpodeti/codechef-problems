#include<iostream>


using namespace std;

class PathCompressionQuickUnionUF{
  int *A;
  int *sz; // store #.of items in the tree that is rooted at i
  int no_of_objects;
public:
  PathCompressionQuickUnionUF(int);
  bool Find(int, int);
  void Union(int,int);
  int GetParent(int);
};


PathCompressionQuickUnionUF::PathCompressionQuickUnionUF(int n){
  no_of_objects = n;
  A = new int[ no_of_objects];
  sz = new int[ no_of_objects];
  

  for(int i=0;i< no_of_objects;++i){
    A[i] = i;
    sz[i] = 1;
  }
}

int PathCompressionQuickUnionUF::GetParent(int obj){
  //path compression logic goes here
  while(A[obj] != obj){
    A[obj] = A[A[obj]];
     obj = A[obj];
  }
   
  return obj;
}

bool PathCompressionQuickUnionUF::Find(int p, int q){
  int parent_p = GetParent(p);
  int parent_q = GetParent(q);

  return parent_p == parent_q;
}
void PathCompressionQuickUnionUF::Union(int p,int q){
  // get the value stored in q
  int pid = GetParent(p);
  int qid = GetParent(q);

  //weighted algorithm logic goes here
  if(sz[pid] < sz[qid]){
    A[pid] = qid;
    sz[qid] += sz[pid];
  }else{
    A[qid] = pid;
    sz[pid] += sz[qid];
  }
 
}
int main(){
  int n, query_type, p, q;
 
  cin >> n;
  
  PathCompressionQuickUnionUF path_compression_quick_unionobj = PathCompressionQuickUnionUF(n);

  //convention query type 1: to union
  // query type 2: to find
  
  while(cin >> query_type >> p >> q){

    if(query_type==1){
       path_compression_quick_unionobj.Union(p,q);
    }else{
      cout << path_compression_quick_unionobj.Find(p,q) << endl;
    }
    

  }
  return 0;
}
