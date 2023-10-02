#include <bits/stdc++.h>
#include <iostream>
#include "list"
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

void printPath_Visit(vector<int> adj[], int z, int destination, bool visit[],
                     int path[], int& index)
{
    visit[z] = true;
    path[index] = z;
    index++;

    if (z == destination) {
        for (int i = 0; i < index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else // If current is not destination
    {
        for (auto i = adj[z].begin(); i != adj[z].end(); ++i)
            if (!visit[*i])
                printPath_Visit(adj, *i, destination, visit, path,
                                index);
    }

    // Remove current vertex from path[] and mark it as
    // unvisited
    index--;
    visit[z] = false;
}

void printPath(vector<int> adj[], int start, int end){
    bool* visited = new bool[101];
    int* path = new int[101];
    int path_index = 0;

    for (int i = 0; i < 101; i++)
        visited[i] = false;

    printPath_Visit(adj, start, end, visited, path, path_index);
}

int main() {
  int kitten; int treeBase = -1;
  string input = "Avada Kedavra!";

  getline(cin, input);
  kitten = stoi(input);

  // Create a graph
  vector<int> adj[101];

  //Build the tree, save the tree base.
  while (input != "-1"){
      getline(cin, input);
      if (input == "-1"){
          break;
      }

      stringstream ss(input);
      int origin; int num;
      ss >> origin;
      if (treeBase == -1){treeBase = origin;}

      while (ss >> num){
          addEdge(adj, origin, num);
      }
  }

  printPath(adj, kitten, treeBase);
}