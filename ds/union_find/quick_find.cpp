/*
 QuickFindUF: 
   Find operaiton takes O(1)
   Union operation takes O(N)

 */


#include<iostream>


using namespace std;

class QuickFindUF{
  int *A;
  int no_of_objects;
public:
  QuickFindUF(int);
  bool Find(int, int);
  void Union(int,int);


};


QuickFindUF::QuickFindUF(int n){
  no_of_objects = n;
  A = new int[ no_of_objects];
  

  for(int i=0;i< no_of_objects;++i)
    A[i] = i;
}


bool QuickFindUF::Find(int p, int q){
  return A[p] == A[q];

}
void QuickFindUF::Union(int p,int q){
  // get the value stored in q
  int pid = A[p];
  int qid = A[q];

  for(int i=0;i< no_of_objects;++i)
    if(A[i] == pid) A[i] = qid;  
}
int main(){
  int n, query_type, p, q;
 
  cin >> n;
  
  QuickFindUF quick_findobj = QuickFindUF(n);

  //convention query type 1: to union
  // query type 2: to find
  
  while(cin >> query_type >> p >> q){

    if(query_type==1){
      quick_findobj.Union(p,q);
    }else{
      cout << quick_findobj.Find(p,q) << endl;
    }
    

  }


  


  return 0;
}
