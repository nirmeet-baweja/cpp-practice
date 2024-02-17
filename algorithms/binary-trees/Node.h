#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
#include<vector>

template <typename T>
class Node
{
  private:
    Node *left;
    Node *right;
    T val;

  public:
    Node (T initialVal)
    {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }

    T getVal()
    {
      return val;
    }

    Node* getLeft()
    {
      return left;
    }

    Node* getRight()
    {
      return right;
    }

    void setLeft(Node* newLeft)
    {
      left = newLeft;
    }

    void setRight(Node* newRight)
    {
      right = newRight;
    }
};

template <typename T> void display_vector(std::vector<T>& v)
{
  std::cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << " " << v[i];
  }
  std::cout << " }\n";
}

#endif