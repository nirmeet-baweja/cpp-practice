#include<iostream>
#include"Node.h"
#include<queue>


int treeSum(Node<int>* root) {
  int sum = 0;

  if(root == nullptr)
  {
    return sum;
  }

  std::queue<Node<int> *> nodeQueue;
  nodeQueue.push(root);

  while(!nodeQueue.empty())
  {
    Node<int> *currentNode = nodeQueue.front();
    nodeQueue.pop();
    sum += currentNode->getVal();
    if(currentNode->getLeft() != nullptr)
    {
      nodeQueue.push(currentNode->getLeft());
    }

    if(currentNode->getRight() != nullptr)
    {
      nodeQueue.push(currentNode->getRight());
    }
  }
  return sum;
}

int main()
{
  Node<int> a(3);
  Node<int> b(11);
  Node<int> c(4);
  Node<int> d(4);
  Node<int> e(-2);
  Node<int> f(1);

  a.setLeft(&b);
  a.setRight(&c);

  b.setLeft(&d);
  b.setRight(&e);

  c.setRight(&f);

  std::cout << treeSum(&a) << std::endl; // -> 21

  std::cout << treeSum(nullptr) << std::endl; // -> 21
}
