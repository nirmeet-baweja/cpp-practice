#include<iostream>
#include<stdio.h>
#include<utility>
#include<typeinfo>
#include<tuple>

void nested_func(unsigned int* num)
{
  *num = 32;
}

int func()
{
  unsigned int num;
  nested_func(&num);
  return num;
}

int main()
{
  printf("%d", func());
  std::pair<std::string, double> pair1;

  pair1 = std::make_pair<std::string, double>("Word", 2.0);

  std::cout << " \n" << typeid(pair1.first).name() << " : " << pair1.second << std::endl;

  int myint;
  char mychar;

  std::tuple<int,float,char> mytuple;

  mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  std::tie (myint, std::ignore, mychar) = mytuple;   // unpacking tuple into variables

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';

  myint = 30;

  std::cout << "\n" << std::get<0>(mytuple) << std::endl;
  std::cout << "myint contains: " << myint << '\n';
  
  return 0;
}