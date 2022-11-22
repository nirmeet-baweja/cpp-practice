#include<iostream>
#include<queue>
#include<unordered_set>
#include<string>
#include<tuple>
#include<unordered_map>
#include<vector>

using namespace std;

void display_graph(unordered_map<string, vector<string>>& graph)
{
  for (auto it = graph.begin(); it != graph.end(); it++)
  {
    cout << "\n{ " << it->first << " : ";
    for (int i = 0; i < it->second.size(); i++)
    {
      cout << it->second[i] << " ";
    }
    cout << "}"<< endl;
  }
}

unordered_map<string, vector<string>> build_graph(
                                        vector<tuple<string, string>>& edges)
{
  unordered_map<string, vector<string>> graph;

  // for (int i = 0; i < edges.size(); i++)
  for (auto edge : edges)
  {
    // string first;
    // string second;
    // std::tie(first, second) = edges[i];
    auto [ first, second ] = edge;
    graph[first].push_back(second);
    graph[second].push_back(first);
  }

  display_graph(graph);
  return graph;
}

// use the visited set to avoid infinite cycles
int shortest_path_bfs(unordered_map<string, vector<string>>& graph,
                      string start, string end)
{
  queue<pair<string, int>> node_queue;
  unordered_set<string> visited;

  // each time you add to queue, mark the node as visited
  node_queue.push(pair<string, int>{start, 0});
  visited.insert(start);

  while(!node_queue.empty())
  {
    pair<string, int> current_node = node_queue.front();
    int current_dist = current_node.second;
    node_queue.pop();

    if(current_node.first == end)
    {
      return current_dist;
    }

    vector<string> neighbours = graph[current_node.first];
    for (int i = 0; i < neighbours.size(); i++)
    {
      if (visited.count(neighbours[i]) == 0)
      {
        node_queue.push(pair<string, int>{neighbours[i], current_dist + 1});
        visited.insert(neighbours[i]);
      }
    }
  }

  // no path exists
  return -1;
}

int shortest_path(vector<tuple<string, string>> &edges,
                  string start, string end)
{
  unordered_map<string, vector<string>> graph = build_graph(edges);
  return shortest_path_bfs(graph, start, end);
}

int main()
{
  cout << "\n******************Test-00******************\n";
  std::vector<std::tuple<std::string, std::string>> edges {
    {"w", "x"},
    {"x", "y"},
    {"z", "y"},
    {"z", "v"},
    {"w", "v"}
  };
  cout << shortest_path(edges, "w", "z") << endl; // -> 2

  cout << "\n******************Test-01******************\n";
  edges = {
    {"w", "x"},
    {"x", "y"},
    {"z", "y"},
    {"z", "v"},
    {"w", "v"}
  };
  cout << shortest_path(edges, "y", "x") << endl; // -> 1

  cout << "\n******************Test-02******************\n";
  edges = {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
  };
  cout << shortest_path(edges, "a", "e") << endl; // -> 3

  cout << "\n******************Test-03******************\n";
  edges = {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
  };
  cout << shortest_path(edges, "e", "c") << endl; // -> 2

  cout << "\n******************Test-04******************\n";
  edges = {
    {"a", "c"},
    {"a", "b"},
    {"c", "b"},
    {"c", "d"},
    {"b", "d"},
    {"e", "d"},
    {"g", "f"}
  };
  cout << shortest_path(edges, "b", "g") << endl; // -> -1
}