#include<iostream>
#include<vector>

using namespace std;

void display_vector(vector<int> v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

int count_sum_tab(int target_sum, vector<int>nums)
{
  vector<int> table(target_sum + 1, 0);

  table[0] = 1;
  cout << "\n*****************************************\n";
  display_vector(table);
  cout << "\n*****************************************\n";

  for (int i = 0; i < table.size(); i++)
  {
    if(table[i] > 0)
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if(i + nums[j] < table.size())
        {
          table[i + nums[j]] += 1;
        }
      }
    }
    cout << "\n*****************************************\n";
    display_vector(table);
    cout << "\n*****************************************\n";
  }

  return table[target_sum];
}

int main()
{
  cout << count_sum_tab(7, {2, 3, 4, 5}) << endl;
}