#include<iostream>
#include<list>

using namespace std;

class Graph{
  int no_of_vertices;
  list<int> *graph;
  bool **transitive;
public:
  Graph(int);
  void TransitiveClosure();
  void AddEdge(int, int);
  void DFS(int, int);

};


Graph::Graph(int n){
  no_of_vertices = n;
  graph = new list<int>[no_of_vertices];
  transitive = new bool*[no_of_vertices];

  for(int i=0;i<no_of_vertices;++i){
    transitive[i] = new bool[no_of_vertices];

    for(int j=0;j<no_of_vertices;++j)
      transitive[i][j] = false;
  }

}

void Graph::DFS(int s, int v){
  transitive[s][v] = true;

  for(auto itr=graph[v].begin();itr!=graph[v].end();++itr){
    if(!transitive[s][*itr]){
      DFS(s, *itr);
    }
  }


}

void Graph::TransitiveClosure(){
  for(int i=0;i<no_of_vertices;++i)
    DFS(i,i);


  for(int i=0;i<no_of_vertices;++i){
    for(int j=0;j<no_of_vertices;++j){
      cout << transitive[i][j] << " ";
    }
    cout << endl;

  }

}


void Graph::AddEdge(int a, int b){
  graph[a].push_back(b);
}


int main(){

  Graph g(4);

  g.AddEdge(0,1);
  g.AddEdge(0,2);
  g.AddEdge(1,2);
  g.AddEdge(2,0);
  g.AddEdge(2,3);
  g.AddEdge(3,3);
  

  g.TransitiveClosure();

}
