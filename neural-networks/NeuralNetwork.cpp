#include <iostream>
#include "./MLP.h"

int main()
{
  srand(time(NULL));
  rand();

  cout << "\n\n------------------Logic AND Gate Example------------------\n\n";
  Perceptron *p_and = new Perceptron(2);
  p_and->set_weights({10, 10, -15}); // AND gate

  cout << "Gate: " << endl;
  cout << p_and->run({0, 0}) << endl;
  cout << p_and->run({0, 1}) << endl;
  cout << p_and->run({1, 0}) << endl;
  cout << p_and->run({1, 1}) << endl;

  cout << "\n\n------------------Logic OR Gate Example-------------------\n\n";
  Perceptron *p_or = new Perceptron(2);
  p_or->set_weights({20, 20, -10}); // OR gate

  cout << "Gate: " << endl;
  cout << p_or->run({0, 0}) << endl;
  cout << p_or->run({0, 1}) << endl;
  cout << p_or->run({1, 0}) << endl;
  cout << p_or->run({1, 1}) << endl;
}