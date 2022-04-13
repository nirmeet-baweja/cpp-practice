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

  // Seven Segment Display Reconintion
  cout << "\n\n------------------Trained SDR Example------------------\n\n";

  // Choose a NN model
  // Model with 7 inputs, 1 hidden layer with 7 perceptrons and 1 output
  MultiLayerPerceptron sdr_771 = MultiLayerPerceptron({7, 7, 1});
  // Model with 7 inputs, 1 hidden layer with 7 perceptrons and 10 outputs
  MultiLayerPerceptron sdr_7710 = MultiLayerPerceptron({7, 7, 10});
  // Model with 7 inputs, 1 hidden layer with 7 perceptrons and 7 outputs
  MultiLayerPerceptron sdr_777 = MultiLayerPerceptron({7, 7, 7});

  // Choose #epochs
  int epochs = 1000;

  // define the inputs
  vector<vector<double>> inputs = {
      {1, 1, 1, 1, 1, 1, 0}, // 0
      {0, 1, 1, 0, 0, 0, 0}, // 1
      {1, 1, 0, 1, 1, 0, 1}, // 2
      {1, 1, 1, 1, 0, 0, 1}, // 3
      {0, 1, 1, 0, 0, 1, 1}, // 4
      {1, 0, 1, 1, 0, 1, 1}, // 5
      {1, 0, 1, 1, 1, 1, 1}, // 6
      {1, 1, 1, 0, 0, 0, 0}, // 7
      {1, 1, 1, 1, 1, 1, 1}, // 8
      {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  // Train the network with the dataset
  // Dataset for 7 to 1 network

  // define the expected / actual output
  vector<vector<double>> y_771 = {
      {0.05}, {0.15}, {0.25}, {0.35}, {0.45}, {0.55}, {0.65}, {0.75}, {0.85}, {0.95}};

  cout << "\nTraining 7 to 1 network.\n";
  for (int i = 0; i < epochs; i++)
  {
    mse = 0.0;
    for (unsigned long int i = 0; i < inputs.size(); i++)
    {
      mse += sdr_771.bp(inputs[i], y_771[i]);
    }

    mse = mse / 10.0;

    if (i % 100 == 0)
    {
      cout << "MSE : " << mse << endl;
    }
  }

  cout << "\nTrained weights for 7 to 1:\n";
  sdr_771.print_weights();

  // Dataset for 7 to 10 network
  vector<vector<double>> y_7710 = {
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 2
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 3
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 4
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 5
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 6
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 7
      {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 8
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 9
  };

  cout << "\nTraining 7 to 10 network.\n";
  for (int i = 0; i < epochs; i++)
  {
    mse = 0.0;
    for (unsigned long int i = 0; i < inputs.size(); i++)
    {
      mse += sdr_7710.bp(inputs[i], y_7710[i]);
    }

    mse = mse / 10.0;

    if (i % 100 == 0)
    {
      cout << "MSE : " << mse << endl;
    }
  }

  cout << "\nTrained weights for 7 to 10:\n";
  sdr_7710.print_weights();

  // Dataset for 7 to 7 network
  cout << "\nTraining 7 to 7 network.\n";
  for (int i = 0; i < epochs; i++)
  {
    mse = 0.0;
    for (unsigned long int i = 0; i < inputs.size(); i++)
    {
      mse += sdr_777.bp(inputs[i], inputs[i]);
    }

    mse = mse / 10.0;

    if (i % 100 == 0)
    {
      cout << "MSE : " << mse << endl;
    }
  }

  cout << "\nTrained weights for 7 to 7:\n";
  sdr_777.print_weights();

  cout << "\n\n----------SDR Testing Comparing the three models----------\n\n";

  vector<double> output_7710 = sdr_7710.run({0.15, 0.95, 0.85, 0.05, 0.2, 0.08, 0});

  cout << "7710 output for number 1: " << endl;
  for (unsigned long int i = 0; i < output_7710.size(); i++)
  {
    cout << output_7710[i] << endl;
  }

  vector<double> output_777 = sdr_777.run({0.15, 0.95, 0.85, 0.05, 0.2, 0.08, 0});

  cout << "777 output for number 1: " << endl;
  for (unsigned long int i = 0; i < output_777.size(); i++)
  {
    cout << output_777[i] << endl;
  }

  cout << "Number 0 {0.75, 1, 1, 1, 1, 1, 0.15}: "
       << sdr_771.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << " "
       << sdr_7710.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << " "
       << endl;

  cout << "Number 1 {0.15, 0.95, 0.85, 0.05, 0.2, 0.08, 0}: "
       << sdr_771.run({0.15, 0.95, 0.85, 0.05, 0.2, 0.08, 0})[0] << endl;

  cout << "Number 2 {1, 1, 0, 1, 1, 0, 1}: "
       << sdr_771.run({1, 1, 0, 1, 1, 0, 1})[0] << endl;

  // cout << "Number 0 {1, 1, 1, 1, 1, 1, 0}: "
  //      << trained_mlp.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << endl;

  // cout << "Number 0 {1, 1, 1, 1, 1, 1, 0}: "
  //      << trained_mlp.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << endl;

  // cout << "Number 0 {1, 1, 1, 1, 1, 1, 0}: "
  //      << trained_mlp.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << endl;

  // cout << "Number 0 {1, 1, 1, 1, 1, 1, 0}: "
  //      << trained_mlp.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << endl;

  // cout << "Number 0 {1, 1, 1, 1, 1, 1, 0}: "
  //      << trained_mlp.run({0.75, 1, 1, 1, 1, 1, 0.15})[0] << endl;
}