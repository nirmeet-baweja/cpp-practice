#include "MLP.h"

double frand()
{
  return (2.0 * (double)rand() / RAND_MAX) - 1.0;
}

/**
 * @brief Return a new Perceptron object with the specified number of inputs
 * and +1 for the bias
 * @param inputs number of external inputs
 * @param bias value of the bias term
 */
Perceptron::Perceptron(int inputs, double bias)
{
  this->bias = bias;
  weights.resize(inputs + 1);
  generate(weights.begin(), weights.end(), frand);
}

/**
 * @brief Run the perceptron
 * @param x a vector with input values
 */
double Perceptron::run(vector<double> x)
{
  x.push_back(bias); // add bias term as the last input
  // calculate dot product of vector x and weights vector
  double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
  return sigmoid(sum);
}

/**
 * @brief set the weights of the perceptron with given weights
 */
void Perceptron::set_weights(vector<double> w_init)
{
  weights = w_init;
}

/**
 * @brief Return the sigmoid of given number
 * @param x can be any value i.e. negative, positive or zero
 */
double Perceptron::sigmoid(double x)
{
  return 1.0 / (1.0 + exp(-x));
}