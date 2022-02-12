/**
 * @file sorted-search.cpp
 * @author nirmeet baweja
 * @brief Implement function countNumbers that accepts a sorted vector of
 * unique integers and, efficiently with respect to time used, counts the
 * number of vector elements that are less than the parameter lessThan.
 *
 * For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4)
 * should return 2 because there are two vector elements less than 4.
 *
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int> &sortedVector, int lessThan)
{
  // first element is greater than lessThan, return 0
  if (sortedVector[0] >= lessThan)
  {
    return 0;
  }

  // last element is smaller than lessThan, return n
  int n = sortedVector.size();
  if (sortedVector[n - 1] < lessThan)
  {
    return n;
  }

  int left = 0;
  int right = n;
  int mid = (left + right) / 2;
  // use the variation of binary search algorithm
  while ((mid > left) && (mid < right))
  {

    if (sortedVector[mid] < lessThan)
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
    mid = (left + right) / 2;
  }

  return mid + 1;
}

#ifndef RunTests
int main()
{
  std::vector<int> v{1, 3, 5, 7};
  std::cout << countNumbers(v, 5) << '\n';
}
#endif