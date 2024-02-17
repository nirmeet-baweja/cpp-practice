#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

void display_vector(vector<char>& v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

void display_graph(unordered_map<char, vector<char>>& graph)
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

unordered_map<char, vector<char>> build_graph(vector<vector<char>>& edges)
{
  unordered_map<char, vector<char>> graph;

  for (int i = 0; i < edges.size(); i++)
  {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }

  display_graph(graph);

  return graph;
}

// checking if path exists using BFS
bool has_path(unordered_map<char, vector<char>>& graph,
              char source, char dest, vector<char>& visited)
{
  cout << "\nFunction call:" << endl;
  cout << "\nSource: " << source << endl;
  cout << "\nDestination: " << dest << endl;
  if (source == dest)
  {
    return true;
  }

  cout << "\nVisited vector before push: " << endl;
  display_vector(visited);

  visited.push_back(source);

  cout << "\nVisited vector after push: " << endl;
  display_vector(visited);

  vector<char> neighbours = graph[source];

  for (int i = 0; i < neighbours.size(); i++)
  {
    if (find(visited.begin(), visited.end(), neighbours[i]) ==
        visited.end())
    {
      cout << "\nRecursive call: " << endl;
      cout << "\nVisited just before call: " << endl;
      display_vector(visited);

      if (has_path(graph, neighbours[i], dest, visited))
      {
        return true;
      }
    }
  }

  return false;
}

bool undirected_path(vector<vector<char>>& edges, char source, char dest)
{
  unordered_map<char, vector<char>> graph = build_graph(edges);
  vector<char> visited;
  return has_path(graph, source, dest, visited);
}

int main()
{
  vector<vector<char>> edges{{'i', 'j'}, {'k', 'i'}, {'m', 'k'}, {'k', 'l'}, {'o', 'n'}, {'j', 'k'}};

  char source = 'k';
  char dest = 'l';
  char dest2 = 'o';
  cout << "\n*******************************************\n";
  cout << "\n"
       << undirected_path(edges, source, dest) << endl;
  cout << "\n*******************************************\n";
  cout << "\n"
       << undirected_path(edges, source, dest2) << endl;
}
