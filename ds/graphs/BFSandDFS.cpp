#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

  void bfs() {
    unordered_map<T,bool> visited;
    for(auto it:adj) {
      visited[it.first] = 0;
    }

    for ( auto i : adj ) {
      if (!visited[i.first]) {
        queue<T> q;
        q.push(i.first);
        visited[i.first] = 1;

        while(!q.empty()) {
          auto n = q.front();
          cout << n << " ";
          q.pop();
          for(auto l : adj[n]) {
            if(!visited[l]){
              q.push(l);
              visited[l] = 1;
            }
          }
        }
      }
    }
  }

  void dfsHelper(T node, unordered_map<T,bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto &nbr : adj[node]) {
        if (!visited[nbr]) {
            dfsHelper(nbr, visited);
        }
     }
  }

  void dfs() {
      unordered_map<T,bool> visited;

      for (auto p : adj) {
          visited[p.first] = 0;
      }

      for (auto p : adj) {
          if (!visited[p.first]) {
              cout << "[ Component starting at " << p.first << " ] ";
              dfsHelper(p.first, visited);
              cout << "\n";
          }
      }
  }
};
