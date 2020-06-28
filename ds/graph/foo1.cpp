#include<iostream>
#include<list>
using namespace std;


class Graph{
  int no_of_nodes;
  list<int> *graph;

public:
  Graph(int);
  void AddEdge(int,int);
  void PrintGraph();
  bool FindCycleUtil(int, bool*, bool*);
  bool FindCycle();
};


Graph::Graph(int n){
  no_of_nodes = n;

  graph = new list<int>[no_of_nodes];
}

void Graph::AddEdge(int a, int b){
  graph[a].push_back(b);
}


void Graph::PrintGraph(){
  for(int i=0;i<no_of_nodes;++i){
    cout << "node #:" << i << endl;
    for(auto itr=graph[i].begin();itr!=graph[i].end();++itr){
      cout << *itr << " ";
    }
    cout << endl;
  }
}

bool Graph::FindCycleUtil(int node, bool *visited_status, bool *stack_node){

  if(!visited_status[node]){
    // add the node, mark it visited
    visited_status[node] = true;
    stack_node[node] = true;

    // do dfs, if the nodes are not visited
    for(auto it=graph[node].begin();it!=graph[node].end();++it){
      if(!visited_status[*it] && FindCycleUtil(*it, visited_status, stack_node)){
	return true;
      }else if(stack_node[*it]){
	return false;
      }    
    }
  }

  stack_node[node] = false;
  return false;
}


bool Graph::FindCycle(){

  // visited status array
  bool *visited_status = new bool[no_of_nodes];
  // array to keep track of it is a stack node 
  bool *stack_node = new bool[no_of_nodes];

  //initialize all to false
  for(int i=0;i<no_of_nodes;++i){
    visited_status[i] = false;
    stack_node[i] = false;
  }
  // traverse using depth first search
  for(int i=0;i<no_of_nodes;++i){
    if(FindCycleUtil(i,visited_status, stack_node)){
      return true;
    }
  }
  return false;
}

int main(){

  
  Graph graph(4);
  graph.AddEdge(0,1);
  graph.AddEdge(1,2);
  graph.AddEdge(2,0);
  graph.AddEdge(3,0);

  graph.PrintGraph();

  cout << graph.FindCycle() << endl;

  return 0;
}
