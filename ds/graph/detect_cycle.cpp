#include<iostream>
#include<list>
using namespace std;


class Graph{
  int no_of_nodes;
  list<int> *graph;
  bool *visited;
  bool *stack_node;
public:
  Graph(int);
  void AddEdge(int, int);
  bool IsGraphCyclicUtil(int);
  bool IsGraphCyclic();
};


Graph::Graph(int n){
  no_of_nodes = n;

  graph = new list<int>[no_of_nodes];

  visited = new bool[no_of_nodes];
  stack_node = new bool[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i){
    visited[i] = false;
    stack_node[i] = false;
  }
}

void Graph::AddEdge(int p, int q){
  graph[p].push_back(q);
}


bool Graph::IsGraphCyclicUtil(int node){
  if(!visited[node]){
    //visit the node, and mark it updated
    visited[node] = true;
    stack_node[node] = true;

    for(auto itr=graph[node].begin();itr!=graph[node].end();++itr){ 
      if(!visited[*itr] && IsGraphCyclicUtil(*itr)){
	return true;
      }else if(stack_node[*itr]){
	return true;
      }
    }

  }
  stack_node[node] = false;
  return false;
}



bool Graph::IsGraphCyclic(){
  for(int i=0;i<no_of_nodes;++i){
    // check if there any cycle that ends at the curr node
    if(IsGraphCyclicUtil(i)){
      return true;
    }

  }
  return false;  
}



int main(){
   Graph g(4); 
   g.AddEdge(0, 1); 
   g.AddEdge(0, 2); 
   g.AddEdge(1, 2); 
   g.AddEdge(2, 0); 
   g.AddEdge(2, 3); 
   g.AddEdge(3, 3); 
  
    if(g.IsGraphCyclic()) 
        cout << "Graph contains cycle\n"; 
    else
        cout << "Graph doesn't contain cycle\n";
  return 0;
}
