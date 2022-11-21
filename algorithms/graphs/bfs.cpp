#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>

using namespace std;

void breadth_first_traversal(unordered_map<char, vector<char>>& graph,
                              char source)
{
  queue<char> node_queue;
  node_queue.push(source);

  while(!node_queue.empty())
  {
    char current_node = node_queue.front();
    node_queue.pop();

    cout << current_node << endl;

    vector<char> neighbours = graph[current_node];
    for (int i = 0; i < neighbours.size(); i++)
    {
      node_queue.push(neighbours[i]);
    }
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

  cout << "\nBreadth first traversal: " << endl;
  breadth_first_traversal(graph, 'a');
}