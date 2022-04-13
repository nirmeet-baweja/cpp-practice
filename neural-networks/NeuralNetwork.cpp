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

  cout << "\n\n------------------Logic XOR Gate Example------------------\n\n";
  MultiLayerPerceptron mlp = MultiLayerPerceptron({2, 2, 1});
  mlp.set_weights({{{-10, -10, 15}, {15, 15, -10}}, {{10, 10, -15}}});
  cout << "Hard-coded weights:";
  mlp.print_weights();

  cout << "XOR Gate: " << endl;
  cout << "(0,0): " << mlp.run({0, 0})[0] << endl;
  cout << "(0,1): " << mlp.run({0, 1})[0] << endl;
  cout << "(1,0): " << mlp.run({1, 0})[0] << endl;
  cout << "(1,1): " << mlp.run({1, 1})[0] << endl;

  cout << "\n\n------------------Trained XOR Example------------------\n\n";
  MultiLayerPerceptron trained_mlp = MultiLayerPerceptron({2, 2, 1});

  cout << "\nTraining NN as XOR Gate\n";
  double mse;
  for (int i = 0; i < 3000; i++)
  {

    mse = 0.0;
    mse += trained_mlp.bp({0, 0}, {0});
    mse += trained_mlp.bp({0, 1}, {1});
    mse += trained_mlp.bp({1, 0}, {1});
    mse += trained_mlp.bp({1, 1}, {0});

    mse = mse / 4.0;

    if (i % 100 == 0)
    {
      cout << "MSE : " << mse << endl;
    }
  }

  cout << "\nTrained weights:\n";
  trained_mlp.print_weights();

  cout << "XOR Gate: " << endl;
  cout << "(0,0): " << trained_mlp.run({0, 0})[0] << endl;
  cout << "(0,1): " << trained_mlp.run({0, 1})[0] << endl;
  cout << "(1,0): " << trained_mlp.run({1, 0})[0] << endl;
  cout << "(1,1): " << trained_mlp.run({1, 1})[0] << endl;

}