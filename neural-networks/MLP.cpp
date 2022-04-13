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

/**
 * @brief Constructor for MultiLayerPerceptron class
 *
 */
MultiLayerPerceptron::MultiLayerPerceptron(vector<int> layers, double bias, double eta)
{
  this->layers = layers;
  this->bias = bias;
  this->eta = eta;

  for (unsigned long int i = 0; i < layers.size(); i++)
  {
    values.push_back(vector<double>(layers[i], 0.0));
    d.push_back(vector<double>(layers[i], 0.0));
    network.push_back(vector<Perceptron>());
    if (i > 0)
    {
      for (int j = 0; j < layers[i]; j++)
      {
        // for each value of j add a new perceptron to the network[i] layer
        // the value of previous layer becomes the number of inputs for current layer
        network[i].push_back(Perceptron(layers[i - 1], bias));
      }
    }
  }
}

/**
 * @brief set the weights of the multi-layer perceptron network
 *
 */
void MultiLayerPerceptron::set_weights(vector<vector<vector<double>>> w_init)
{
  /**
   * w_init will have one less layer because the input layer
   * is not a layer of perceptrons
   */
  for (unsigned long int i = 0; i < w_init.size(); i++)
  {
    for (unsigned long int j = 0; j < w_init[i].size(); j++)
    {
      network[i + 1][j].set_weights(w_init[i][j]);
    }
  }
}

/**
 * @brief print the weights of the multi-layer perceptron network
 *
 */
void MultiLayerPerceptron::print_weights()
{
  cout << endl;
  for (unsigned long int i = 1; i < network.size(); i++)
  {
    for (int j = 0; j < layers[i]; j++)
    {
      cout << "Layer " << i + 1 << " Neuron " << j << ": ";
      for (auto &it : network[i][j].weights)
      {
        cout << it << " ";
      }
      cout << endl;
    }
  }
}

/**
 * @brief feed a sample input x into the multilayer perceptron
 *
 */
vector<double> MultiLayerPerceptron::run(vector<double> x)
{
  values[0] = x;
  for (unsigned long int i = 1; i < network.size(); i++)
  {
    for (int j = 0; j < layers[i]; j++)
    {
      values[i][j] = network[i][j].run(values[i - 1]);
    }
  }
  return values.back();
}

/**
 * @brief function to calculate mean squared error
 *
 */
double mean_squared_error(vector<double> predicted_value, vector<double> actual_value)
{
  double sum = 0.0;
  for (unsigned long int i = 0; i < predicted_value.size(); i++)
  {
    double diff = predicted_value[i] - actual_value[i];
    sum += (diff * diff);
  }

  return sum / predicted_value.size();
}

/**
 * @brief run a single (x,y) pair with backpropagation algorithm.
 *
 */
double MultiLayerPerceptron::bp(vector<double> x, vector<double> y)
{
  // Backpropagation step by step

  // Step 1 : Feed a sample input to the network
  vector<double> outputs = run(x);

  // Step 2 : Calculate the MSE
  // double mse = mean_squared_error(outputs, y);
  vector<double> error;
  double mse = 0.0;
  for (unsigned long int i = 0; i < y.size(); i++)
  {
    error.push_back(y[i] - outputs[i]);
    mse += error[i] * error[i];
  }

  mse /= layers.back();

  // Step 3 : Calculate the o/p error terms
  for (unsigned long int i = 0; i < outputs.size(); i++)
  {
    d.back()[i] = outputs[i] * (1 - outputs[i]) * error[i];
  }

  // Step 4 : Calculate the error term of each unit on each layer
  for (unsigned long int i = network.size() - 2; i > 0; i--)
  {
    for (unsigned long int h = 0; h < network[i].size(); h++)
    {
      double fwd_error = 0.0;

      for (int k = 0; k < layers[i + 1]; k++)
      {
        fwd_error += network[i + 1][k].weights[h] * d[i + 1][k];
      }
      d[i][h] = values[i][h] * (1 - values[i][h]) * fwd_error;
    }
  }

  // Step 5 & 6 : Calculate the deltas and update the weights
  for (unsigned long int i = 1; i < network.size(); i++)
  {
    for (int j = 0; j < layers[i]; j++)
    {
      for (int k = 0; k < layers[i - 1] + 1; k++)
      {
        double delta;
        if (k == layers[i - 1])
        {
          delta = eta * d[i][j] * bias;
        }
        else
        {
          delta = eta * d[i][j] * values[i - 1][k];
        }
        network[i][j].weights[k] += delta;
      }
    }
  }

  return mse;
}