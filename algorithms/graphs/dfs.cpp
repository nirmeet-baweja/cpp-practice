#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

void depth_first_traversal(unordered_map<char, vector<char>>& graph,
                            char source)
{
  stack<char> node_stack;
  node_stack.push(source);

  while(!node_stack.empty())
  {
    char current_node = node_stack.top();
    node_stack.pop();

    cout << current_node << endl;

    vector<char> neighbours = graph[current_node];
    for (int i = 0; i<neighbours.size(); i++)
    {
      node_stack.push(neighbours[i]);
    }
  }
}

void depth_first_recursive(unordered_map<char, vector<char>>& graph, char node)
{
    cout << node << endl;
    vector<char> neighbours = graph[node];
    for (int i = 0; i < neighbours.size(); i++)
    {
      depth_first_recursive(graph, neighbours[i]);
    }
}

int main()
{
  unordered_map<char, vector<char>> graph;

  // graph represented as an adjacency list
  graph = {
      {'a', {'b', 'c'}},
      {'b', {'d'}},
      {'c', {'e'}},
      {'d', {'f'}},
      {'e', {}},
      {'f', {}}};

  cout << "\nIterative approach: " << endl;
  depth_first_traversal(graph, 'a');
  cout << "\nRecursive approach: " << endl;
  depth_first_recursive(graph, 'a');
}