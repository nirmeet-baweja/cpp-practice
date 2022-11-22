#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void display_vector(vector<int>& v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

int calc_size_dfs(unordered_map<int, vector<int>>& graph, int node,
              vector<int>& visited)
{
  if (find(visited.begin(), visited.end(), node) != visited.end())
  {
    return 0;
  }

  visited.push_back(node);
  int size = 1;

  vector<int> neighbours = graph[node];

  for (int i = 0; i < neighbours.size(); i++)
  {
    size += calc_size_dfs(graph, neighbours[i], visited);
  }

  return size;
}

int largestComponent(unordered_map<int, vector<int>> graph)
{
  int max_size = 0;
  vector<int> visited;

  for( auto node : graph)
  {
    int current_size = calc_size_dfs(graph, node.first, visited);
    if (current_size > max_size)
    {
      max_size = current_size;
    }
  }

  return max_size;
}

int main()
{
  cout << "\n******************Test-00******************\n";
  std::unordered_map<int, std::vector<int>> graph {
    { 0, {8, 1, 5} },
    { 1, {0} },
    { 5, {0, 8} },
    { 8, {0, 5} },
    { 2, {3, 4} },
    { 3, {2, 4} },
    { 4, {3, 2} }
  };

  cout << largestComponent(graph) << endl; // -> 4
}