#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template < typename T>
class graph {
public:
  unordered_map<T,list<T>> adj;

  void addEdge(T u,T v,bool direction) {
    // direction = 0 --> undirected graph
    // direction = 1 --> directed graph
    adj[u].push_back(v);

    if(!direction){
      adj[v].push_back(u);
    }

    return;
  }

  void printAdjList() {
    cout << "---- The Adjacency List ----" << endl;
    for(auto it : adj ){
      cout << it.first << " -> ";
      for(auto it2:it.second) {
        cout << it2 << " ";
      }
      cout << endl;
    }
  }

};

int main() {
  graph<int> g;

  int n,m;
  cout << "Enter the number of nodes : ";
  cin >> n;

  cout << "Enter the number of edges : ";
  cin >> m;

  cout << endl;

  for ( int i = 0 ; i < m ; i++ ) {
    int u,v;
    cout << "Enter the edge nodes (u) -> (v) : " << endl;
    cin >> u >> v;
    g.addEdge(u,v,0); // Making a undirected graph
  }

  g.printAdjList();
}