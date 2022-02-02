/**
 * @file merge-names.cpp
 * @author nirmeet baweja
 * @brief Implement the unique_names method. When passed two vectors of names,
 * it will return a vector containing the names that appear in either or both
 * vectors. The returned vector should have no duplicates.
 * For example, calling
 * unique_names(
 *  std::vector<std::string>{"Ava", "Emma", "Olivia"},
 *  std::vector<std::string>{"Olivia", "Sophia", "Emma"}
 * )
 * should return a vector containing Ava, Emma, Olivia, and Sophia in any order.
 *
 * @version 0.1
 * @date 2022-02-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <cstring>

bool vector_includes_name(const std::vector<std::string> &names, std::string name)
{
  for (std::string i : names)
  {
    if (i == name)
    {
      return true;
    }
  }
  return false;
}

std::vector<std::string> remove_duplicate_names(const std::vector<std::string> &names)
{
  std::vector<std::string> result;
  for (std::string i : names)
  {
    if (!vector_includes_name(result, i))
    {
      result.push_back(i);
    }
  }
  return result;
}

std::vector<std::string> unique_names(const std::vector<std::string> &names1, const std::vector<std::string> &names2)
{
  std::vector<std::string> result(remove_duplicate_names(names1));
  // ranged loop
  for (std::string i : names2)
  {
    if (!vector_includes_name(result, i))
    {
      result.push_back(i);
    }
  }
  return result;
  // throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
  std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
  std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

  std::vector<std::string> result = unique_names(names1, names2);
  for (auto element : result)
  {
    std::cout << element << ' '; // should print Ava Emma Olivia Sophia
  }
  std::cout << '\n';
}
#endif