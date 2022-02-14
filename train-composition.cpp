/**
 * @file train-composition.cpp
 * @author nirmeet baweja
 * @brief A TrainComposition is built by attaching and detaching wagons from
 * he left and the right sides, efficiently with respect to time used.
 *
 * For example, if we start by attaching wagon 7 from the left followed by
 * attaching wagon 13, again from the left, we get a composition of two wagons
 * (13 and 7 from left to right). Now the first wagon that can be detached from
 * the right is 7 and the first that can be detached from the left is 13.
 *
 * Implement a TrainComposition that models this problem.
 *
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
private:
  std::deque<int> wagons;

public:
  void attachWagonFromLeft(int wagonId)
  {
    this->wagons.push_front(wagonId);
  }

  void attachWagonFromRight(int wagonId)
  {
    this->wagons.push_back(wagonId);
  }

  int detachWagonFromLeft()
  {
    int wagon = wagons[0];
    this->wagons.pop_front();
    return wagon;
  }

  int detachWagonFromRight()
  {
    int wagon = this->wagons[this->wagons.size() - 1];
    this->wagons.pop_back();
    return wagon;
  }
};

#ifndef RunTests
int main()
{
  TrainComposition train;
  train.attachWagonFromLeft(7);
  train.attachWagonFromLeft(13);
  std::cout << train.detachWagonFromRight() << "\n"; // 7
  std::cout << train.detachWagonFromLeft();          // 13
}
#endif