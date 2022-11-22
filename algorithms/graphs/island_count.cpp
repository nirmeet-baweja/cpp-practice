
#include<iostream>
#include <vector>

void display_vector(std::vector<std::vector<char>> v)
{
  for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			std::cout<<v[i][j]<<" ";
		std::cout<<std::endl;
	}
}

bool did_traverse_dfs(std::vector<std::vector<char>>& grid, int r, int c)
{
  // make sure out of bounds is checked correctly
  if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 'W')
  {
    return false;
  }

  grid[r][c] = 'W';
  did_traverse_dfs(grid, r + 1, c);
  did_traverse_dfs(grid, r - 1, c);
  did_traverse_dfs(grid, r, c + 1);
  did_traverse_dfs(grid, r, c - 1);
  return true;
}

int island_count(std::vector<std::vector<char>> grid) {

  std::vector<std::vector<char>> copy_grid(grid);
  int count = 0;

  for (int i = 0; i < copy_grid.size(); i++)
  {
    for (int j = 0; j < copy_grid[i].size(); j++)
    {
      if (did_traverse_dfs(copy_grid, i, j))
      {
        count += 1;
      }

    }
  }

  return count;
}

int main()
{
  std::vector<std::vector<char>> grid {
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'L', 'W', 'W', 'W'},
    {'W', 'W', 'W', 'L', 'W'},
    {'W', 'W', 'L', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'L', 'L', 'W', 'W', 'W'}
  };
  std::cout << island_count(grid) << std::endl; // -> 3
}