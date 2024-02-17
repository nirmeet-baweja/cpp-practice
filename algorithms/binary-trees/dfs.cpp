#include <iostream>
#include "Node.h"
#include <stack>
#include <string>
#include <vector>

std::vector<std::string> dfs(Node<std::string>* root)
{
  std::vector<std::string> values;
  if(root == nullptr)
  {
    return values;
  }
  std::stack<Node<std::string> *> node_stack;
  node_stack.push(root);

  while(!node_stack.empty())
  {
    Node<std::string> *current_node = node_stack.top();
    node_stack.pop();
    values.push_back(current_node->getVal());

    if(current_node->getLeft() != nullptr)
    {
      node_stack.push(current_node->getLeft());
    }

    if(current_node->getRight() != nullptr)
    {
      node_stack.push(current_node->getRight());
    }
  }

  return values;
}

std::vector<std::string> dfsRecursive(Node<std::string> *root)
{
  if(root == nullptr)
  {
    return {};
  }

  std::vector<std::string> result{root->getVal()};
  std::vector<std::string> leftValues{dfsRecursive(root->getLeft())};
  std::vector<std::string> rightValues{dfsRecursive(root->getRight())};

  result.insert(result.end(), leftValues.begin(), leftValues.end());
  result.insert(result.end(), rightValues.begin(), rightValues.end());

  return result;
}

int main()
{
  Node<std::string> a("a");
  Node<std::string> b("b");
  Node<std::string> c("c");
  Node<std::string> d("d");
  Node<std::string> e("e");
  Node<std::string> f("f");

  a.setLeft(&b);
  a.setRight(&c);

  b.setLeft(&d);
  b.setRight(&e);

  c.setRight(&f);

  std::vector<std::string> values = dfs(&a);
  display_vector(values);

  values = dfsRecursive(&a);
  display_vector(values);
}