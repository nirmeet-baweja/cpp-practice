#include<iostream>
#include<vector>

using namespace std;

void display_vector(vector<int>& v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

vector<int> how_sum_tab(int target_sum, vector<int> nums)
{
  vector<vector<int> *> table(target_sum + 1, nullptr);

  table[0] = new vector<int>{};

  for (int i = 0; i < table.size(); i++)
  {
    if(table[i] != nullptr)
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if(i + nums[j] < table.size())
        {
          table[i + nums[j]] = new vector<int>{};
          table[i + nums[j]]->assign(table[i]->begin(), table[i]->end());
          table[i + nums[j]]->push_back(nums[j]);
        }
      }
    }
  }

  return *table[target_sum];
}

int main()
{
  vector<int> result = how_sum_tab(7, {2, 3, 4, 5});
  display_vector(result);
}