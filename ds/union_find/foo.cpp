#include<iostream>
using namespace std;

class UnionFind{
  int *A;
  int *B;
  int no_of_nodes;
public:
  UnionFind(int);
  int GetParent(int);
  void Union(int,int);
  bool Find(int, int);
};

UnionFind::UnionFind(int n){
  no_of_nodes = n;
  A = new int[no_of_nodes+1];
  B = new int[no_of_nodes+1];

  for(int i=1;i<=no_of_nodes;++i){
    A[i] = i;
    B[i] = 1;
  }
}

int UnionFind::GetParent(int node){
  while(node!=A[node])
    node = A[node];

  return node;
}


bool UnionFind::Find(int p, int q){
  int pid = GetParent(p);
  int qid = GetParent(q);

  return pid==qid;
}
void UnionFind::Union(int p, int q){
  //get the parent of the both p, q
  int pid = GetParent(p);
  int qid = GetParent(q);

  if(B[pid]>B[qid]){
    // q is connected to p
    A[qid] = pid;

    B[pid] += B[qid];

  }else{
    // p is connected to q
    A[pid] = qid;

    B[qid] += B[pid];
  }
}



int main(){
  int n, query_type, p,q;
  cin >> n;

  UnionFind uf(n);

  while(cin >> query_type >> p >> q){
    if(query_type==1){
      // union operation
      uf.Union(p,q);
    }else{
      // find operation
      cout << uf.Find(p, q) << endl;
    }

  }

 
  return  0;
}
