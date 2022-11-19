#include<iostream>
#include<vector>

using namespace std;

void display_vector(vector<bool> v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

bool can_sum_tab(int target_sum, vector<int> nums)
{
  vector<bool> table(target_sum + 1, false);

  table[0] = true;

  for (int i = 0; i < table.size(); i++)
  {
    if(table[i])
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if(i + nums[j] < table.size())
          table[i + nums[j]] = true;
      }
    }
  }
  display_vector(table);

  return table[target_sum];
}

int main()
{
  cout << can_sum_tab(7, { 3, 4, 5 }) << endl;
}