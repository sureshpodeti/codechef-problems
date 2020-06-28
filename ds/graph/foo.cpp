#include<iostream>

using namespace std;

class Graph{
  int **graph;
  int no_of_vertices;
public:
  Graph(int);
  void AddEdge(int, int);
  bool IsConnected(int, int);

};

Graph::Graph(int n){
  no_of_vertices = n;
  graph = new int*[no_of_vertices];
  for(int i=0;i<no_of_vertices;++i)
    graph[i] = new int[no_of_vertices];

  //initialize all elements with 0's
  for(int i=0;i<no_of_vertices;++i){
    for(int j=0;j<no_of_vertices;++j){
      graph[i][j] = 0;
    }
  }


    for(int i=0;i<no_of_vertices;++i){
    for(int j=0;j<no_of_vertices;++j){
      cout <<  graph[i][j] << " ";
    }
    cout << endl;
  }


}

void Graph::AddEdge(int a, int b){
  graph[a-1][b-1] = 1;

  // undirected graph, symmetric
  graph[b-1][a-1] = 1;
}


bool Graph::IsConnected(int a, int b){

  return graph[a-1][b-1];
}



int main(){
  int n;
  cin >> n;

  Graph graph = Graph(n);


  int query_type, a, b;
  while(cin >> query_type >> a >> b){
    if(query_type==1)
      graph.AddEdge(a, b);
    else
      cout << graph.IsConnected(a, b) << endl;


  }


 
  

  return 0;
}

