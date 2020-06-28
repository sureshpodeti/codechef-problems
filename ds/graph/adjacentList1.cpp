#include<iostream>
#include<vector>
using namespace std;

class Graph{
  int no_of_vertices;
  vector<int> *graph;
public:
  Graph(int);
  void AddEdge(int,int);
  void PrintGraph();
};


Graph::Graph(int n){
  no_of_vertices = n;

  graph = new vector<int>[no_of_vertices];

}


void Graph::AddEdge(int a, int b){
  graph[a-1].push_back(b-1);
  graph[b-1].push_back(a-1);
}

void Graph::PrintGraph(){
  for(int i=0;i<no_of_vertices;++i){
    cout << "Adjacency list for node:" << i << "\n" << 
      "head";

    for(auto vertex: graph[i]){
      cout << "->" << vertex;
    }

    cout << endl;
  }

}


int main(){
 
  Graph graph = Graph(5);

  graph.AddEdge(1, 2); 
  graph.AddEdge(1, 5); 
  graph.AddEdge(2, 3); 
  graph.AddEdge(2, 4); 
  graph.AddEdge(2, 5); 
  graph.AddEdge(3, 4); 
  graph.AddEdge(4, 5); 
  graph.PrintGraph(); 
  
  
  return 0;
}
