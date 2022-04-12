#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{
  double sqrt_D = sqrt(b * b - 4 * a * c);

  std::pair<double, double> result;

  result.first = (-b + sqrt_D) / (2 * a);
  result.second = (-b - sqrt_D) / (2 * a);
  return result;
}

#ifndef RunTests
int main()
{
  std::pair<double, double> roots = findRoots(2, 10, 8);
  std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif