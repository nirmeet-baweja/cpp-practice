#include<iostream>
#include<algorithm> // for std::find()
#include <unordered_map>
#include <vector>

using namespace std;

// depth first traversal
bool did_traverse_node(unordered_map<int, vector<int>>& graph, int source,
          vector<int>& visited)
{
  if(find(visited.begin(), visited.end(), source) != visited.end())
  {
    return false;
  }

  visited.push_back(source);

  vector<int> neighbours = graph[source];

  for (int i = 0; i < neighbours.size(); i++)
  {
    did_traverse_node(graph, neighbours[i], visited);
  }

  return true;
}

int connectedComponentsCount(unordered_map<int, vector<int>> graph) {
  int count = 0;
  vector<int> visited;

  for (auto node : graph)
  {
    if(did_traverse_node(graph, node.first, visited))
    {
      count += 1;
    }
  }
  return count;
}

int main()
{
  cout << "\n******************Test-00******************\n";
  unordered_map<int, vector<int>> graph0 {
    { 0, { 8, 1, 5 } },
    { 1, { 0 } },
    { 5, { 0, 8 } },
    { 8, { 0, 5 } },
    { 2, { 3, 4 } },
    { 3, { 2, 4 } },
    { 4, { 3, 2 } }
  };

  cout << connectedComponentsCount(graph0) << endl; // -> 2

  cout << "\n******************Test-01******************\n";
  std::unordered_map<int, std::vector<int>> graph1 {
    { 3, { } },
    { 4, { 6 } },
    { 6, { 4, 5, 7, 8 } },
    { 8, { 6 } },
    { 7, { 6 } },
    { 5, { 6 } },
    { 1, { 2 } },
    { 2, { 1 } }
  };

  cout << connectedComponentsCount(graph1) << endl; // -> 3

  cout << "\n******************Test-02******************\n";
  unordered_map<int, vector<int>> graph2 {
    { 1, { 2 } },
    { 2, { 1, 8 } },
    { 6, { 7 } },
    { 9, { 8 } },
    { 7, { 6, 8 } },
    { 8, { 9, 7, 2 } }
  };
  cout << connectedComponentsCount(graph2) << endl; // -> 1

  cout << "\n******************Test-03******************\n";
  std::unordered_map<int, std::vector<int>> graph3;
  cout << connectedComponentsCount(graph3) << endl; // -> 0

  cout << "\n******************Test-04******************\n";
  std::unordered_map<int, std::vector<int>> graph4 {
    { 0, { 4, 7 } },
    { 1, { } },
    { 2, { } },
    { 3, { 6 } },
    { 4, { 0 } },
    { 6, { 3 } },
    { 7, { 0 } },
    { 8, { } },
  };
  cout << connectedComponentsCount(graph4) << endl; // -> 5
}