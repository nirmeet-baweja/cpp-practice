#include<iostream>
#include<limits.h>
#include<vector>

int calc_size(std::vector<std::vector<char>>& grid, int r, int c)
{
  if(r<0 || c<0 || r>=grid.size() || c>=grid[r].size() || grid[r][c] == 'W')
  {
    return 0;
  }

  grid[r][c] = 'W';
  int size = 1;

  size += calc_size(grid, r + 1, c) +
          calc_size(grid, r - 1, c) +
          calc_size(grid, r, c + 1) +
          calc_size(grid, r, c - 1);

  return size;
}

int smallest_island(std::vector<std::vector<char>> grid) {
  std::vector<std::vector<char>> copy_grid(grid);

  int smallest = INT_MAX;

  for (int i = 0; i < copy_grid.size(); i++)
  {
    for (int j = 0; j < grid[i].size(); j++)
    {
      int current_size = calc_size(copy_grid, i, j);
      if(current_size > 0 && current_size < smallest)
      {
        smallest = current_size;
      }
    }
  }

  if(smallest == INT_MAX)
  {
    smallest = 0;
  }

  return smallest;
}

int main()
{
  std::cout << "\n******************Test-00******************\n";
  std::vector<std::vector<char>> grid {
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'W', 'W', 'L', 'W'},
    {'W', 'W', 'L', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'L', 'L', 'W', 'W', 'W'}
  };

  std::cout << smallest_island(grid) << std::endl; // -> 2

  std::cout << "\n******************Test-01******************\n";
  grid = {
    {'W', 'W'},
    {'L', 'L'},
    {'W', 'W'},
    {'W', 'L'}
  };

  std::cout << smallest_island(grid) << std::endl; // -> 1

  std::cout << "\n******************Test-02******************\n";
  grid = {
    {'L', 'W', 'W', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'W', 'L', 'W', 'L', 'W'},
    {'W', 'W', 'W', 'W', 'W'},
    {'W', 'W', 'L', 'L', 'L'}
  };

  std::cout << smallest_island(grid) << std::endl; // -> 1

  std::cout << "\n******************Test-03******************\n";
  grid = {
    {'L', 'L', 'L'},
    {'L', 'L', 'L'},
    {'L', 'L', 'L'}
  };
  std::cout << smallest_island(grid) << std::endl; // -> 9

  std::cout << "\n******************Test-04******************\n";
  grid = {
    {'W', 'W', 'W'},
    {'W', 'W', 'W'},
    {'W', 'W', 'W'}
  };
  std::cout << smallest_island(grid) << std::endl; // -> 0
}