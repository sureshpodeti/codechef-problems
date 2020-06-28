#include<iostream>
#include<list>
#include<stack>
using namespace std;


class Graph{
  int no_of_vertices;
  list<int> *graph;

public:
  Graph(int);
  void AddEdge(int, int);
  void DepthFirstTraversal(int);
  void PrintGraph();
};


Graph::Graph(int n){
  no_of_vertices = n;

  graph = new list<int>[no_of_vertices];

}

void Graph::AddEdge(int a, int b){
  graph[a].push_back(b);
  graph[b].push_back(a);
}

void Graph::DepthFirstTraversal(int start_node){
  bool *visited = new bool[no_of_vertices];
  for(int i=0;i<no_of_vertices;++i)
    visited[i] = false;

  stack<int> stk;
  // push the first element
  stk.push(start_node);
  visited[start_nodehe] = true;

  while(!stk.empty()){
     int top_node = stk.top();
     cout << top_node << "->";
     stk.pop();
  

  for(auto itr = graph[top_node].begin();itr!=graph[top_node].end();++itr){
    if(!visited[*itr]){
      stk.push(*itr);
      visited[*itr] = true;
     } 

  }
  }

  cout << endl;

}

void Graph::PrintGraph(){
  for(int i=0;i<no_of_vertices;++i){
    cout << "Connections for the vertex:" << i << endl;
    for(auto itr=graph[i].begin();itr!=graph[i].end();++itr){
      cout << *itr << " ";
    }

    cout << endl;

  }

}


int main(){

  /*
  Graph graph(4);
  graph.AddEdge(0,1);
  graph.AddEdge(0,2);
  graph.AddEdge(2,3);


  graph.PrintGraph();
  cout << endl;

  graph.DepthFirstTraversal(0);
  */


  Graph g(5);
  g.AddEdge(0, 1); 
    g.AddEdge(0, 2); 
    g.AddEdge(1,3);
    g.AddEdge(1,4);
    g.AddEdge(2,4);
    g.AddEdge(3,4);
    g.AddEdge(3,5);
    g.AddEdge(4,5);

    g.DepthFirstTraversal(0);
  return 0;
}
