#include <iostream>
#include "Node.h"
#include <queue>
#include <string>
#include <vector>

std::vector<std::string> breadthFirstValues(Node<std::string>* root) {
  std::vector<std::string> values;
  std::queue<Node<std::string> *> nodeQueue;
  if(root == nullptr)
  {
    return values;
  }
  nodeQueue.push(root);
  while(!nodeQueue.empty())
  {
    Node<std::string> *currentNode = nodeQueue.front();
    nodeQueue.pop();
    values.push_back(currentNode->getVal());
    if (currentNode->getLeft() != nullptr)
    {
      nodeQueue.push(currentNode->getLeft());
    }
    if(currentNode->getRight() != nullptr)
    {
      nodeQueue.push(currentNode->getRight());
    }
  }
  return values;
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

  std::vector<std::string> values = breadthFirstValues(&a);
  display_vector(values);
}
