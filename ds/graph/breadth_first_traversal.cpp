#include<iostream>
#include<list>
using namespace std;

class Graph{
  int no_of_vertices;
  list<int> *graph;
public:
  Graph(int);
  void AddEdge(int,int);
  void Breadth_first_traversal(int);
};


Graph::Graph(int n){
  no_of_vertices = n;

  graph = new list<int>[no_of_vertices];
  
}

void Graph::AddEdge(int a, int b){
  graph[a].push_back(b);
}

void Graph::Breadth_first_traversal(int a){

  bool *visited = new bool[no_of_vertices];
  for(int i=0;i<no_of_vertices;++i)
    visited[i] =false;


  list<int> queue;
  list<int>::iterator itr;

  //pick the node, mark it visited
  visited[a] = true;

  queue.push_back(a);

  while(!queue.empty()){
    //get the front value
    int front_value = queue.front();
    queue.pop_front();
    cout << front_value << " ";
    
    //get the nodes adjacent to the current node
    for(itr=graph[front_value].begin();itr!=graph[front_value].end();++itr){
      //pick the unvisited node

      if(!visited[*itr]){
	//mark it as visited
	visited[*itr] = true;
	queue.push_back(*itr);
       

      }

    }
  }
  cout << endl;
}




int main(){

  Graph g(4); 
    g.AddEdge(0, 1); 
    g.AddEdge(0, 2); 
    g.AddEdge(1, 2); 
    g.AddEdge(2, 0); 
    g.AddEdge(2, 3); 
    g.AddEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.Breadth_first_traversal(2);
  

  return 0;
}
