/**
 * @file has_path.cpp
 * @author nirmeet baweja
 * @brief functions to check if there exists a path between two given nodes
 * of an acyclic directed graph.
 * @version 0.1
 * @date 2022-11-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

bool has_path_dfs(unordered_map<char, vector<char>>& graph,
                  char source, char dest)
{
  bool has_path = false;
  stack<char> node_stack;
  node_stack.push(source);

  while(!node_stack.empty())
  {
    char current_node = node_stack.top();
    node_stack.pop();
    if(current_node == dest)
    {
      has_path = true;
      break;
    }

    vector<char> neighbours = graph[current_node];
    for (int i = 0; i < neighbours.size(); i++)
    {
      node_stack.push(neighbours[i]);
    }
  }

  return has_path;
}

bool has_path_dfs_recursive(unordered_map<char, vector<char>>& graph,
                            char source, char dest)
{
  if(source == dest)
  {
    return true;
  }

  vector<char> neighbours = graph[source];
  for (int i = 0; i < neighbours.size(); i++)
  {
    if(has_path_dfs_recursive(graph, neighbours[i], dest))
      return true;
  }

  return false;
}

bool has_path_bfs(unordered_map<char, vector<char>>& graph,
                  char source, char dest)
{
  bool has_path = false;
  queue<char> node_queue;
  node_queue.push(source);

  while(!node_queue.empty())
  {
    char current_node = node_queue.front();
    node_queue.pop();

    if(current_node == dest)
    {
      has_path = true;
      break;
    }

    vector<char> neighbours = graph[current_node];
    for (int i = 0; i < neighbours.size(); i++)
    {
      node_queue.push(neighbours[i]);
    }
  }

  return has_path;
}

int main()
{
  unordered_map<char, vector<char>> graph;

  // graph represented as an adjacency list
  graph = {
      {'f', {'g', 'i'}},
      {'g', {'h'}},
      {'h', {}},
      {'i', {'g', 'k'}},
      {'j', {'i'}},
      {'k', {}}};

  char source = 'f';
  char dest1 = 'k';
  char dest2 = 'j';

  cout << "\nCheck if there exist a path between source and destination using DFS." << endl;
  cout << has_path_dfs(graph, source, dest1) << endl;
  cout << has_path_dfs(graph, source, dest2) << endl;

  cout << "\nCheck if there exist a path between source and destination using DFS recursive." << endl;
  cout << has_path_dfs_recursive(graph, source, dest1) << endl;
  cout << has_path_dfs_recursive(graph, source, dest2) << endl;

  cout << "\nCheck if there exist a path between source and destination using BFS." << endl;
  cout << has_path_bfs(graph, source, dest1) << endl;
  cout << has_path_bfs(graph, source, dest2) << endl;
}