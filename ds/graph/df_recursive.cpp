#include<iostream>
#include<list>
using namespace std;

class Graph{
  int no_of_vertices;
  list<int> *graph;
public:
  Graph(int);
  void AddEdge(int,int);
  void PrintGraph();
  void DFS(int, bool *);
  void InitializeFalse(bool *);
  int FindMother();

};
 

Graph::Graph(int n){
  no_of_vertices = n;
  graph = new list<int>[no_of_vertices];
}


void Graph::AddEdge(int a, int b){
  graph[a].push_back(b);
}

void Graph::PrintGraph(){
  for(int i=0;i<no_of_vertices;++i){

    cout << "connections to node:" << i << "\n";
    for(auto x: graph[i])
      cout << x << "->";
    cout << endl;
  }

}


void Graph::DFS(int x, bool *visited){
  //mark current node as visited
  visited[x] = true;

  //recurr for its children
  for(auto itr=graph[x].begin();itr!=graph[x].end();++itr){
    if(!visited[*itr])
      DFS(*itr, visited);
  }
}


void Graph::InitializeFalse(bool *visited){
   for(int i=0;i<no_of_vertices;++i)
     visited[i] = false;
}

int Graph::FindMother(){
  bool *visited = new bool[no_of_vertices];

  InitializeFalse(visited);
  
  // variable to store the mother node
  int mother_node = 0;

  for(int i=0;i<no_of_vertices;++i){
    if(!visited[i]){
      DFS(i, visited);
      mother_node = i;
    }  
  }

  InitializeFalse(visited);

  // perform depth-first traversal from v
  DFS(mother_node, visited);
  
  //check if v is mother vertex
  for(int i=0;i<no_of_vertices;++i){
    if(!visited[i])
      return -1;
  }


  return mother_node;

  
}
int main(){
  Graph g(5);
  g.AddEdge(0,1);
  g.AddEdge(0,2);
  g.AddEdge(2,3);
  g.AddEdge(2,4);

  //g.PrintGraph();
  cout << g.FindMother() << endl;
  return 0;
}
