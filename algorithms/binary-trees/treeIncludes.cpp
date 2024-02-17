#include<iostream>
#include"Node.h"

bool treeIncludes(Node<std::string>* root, std::string targetVal) {

  if(root == nullptr)
  {
    return false;
  }
  if(root->getVal() == targetVal)
  {
    return true;
  }

  bool result = false;
  if(root->getLeft() != nullptr)
    result = result || treeIncludes(root->getLeft(), targetVal);
  if(root->getRight() != nullptr)
    result = result || treeIncludes(root->getRight(), targetVal);

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

  std::cout << treeIncludes(&a, "x") << std::endl;

  std::string word = "This is a words";
  std::cout << word.size() << "\t" << word.length() << std::endl;
}
