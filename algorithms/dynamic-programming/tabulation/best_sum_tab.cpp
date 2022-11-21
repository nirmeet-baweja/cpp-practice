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

vector<int> best_sum_tab(int target_sum, vector<int> nums)
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
          vector<int> *temp = new vector<int>{};
          temp->assign(table[i]->begin(), table[i]->end());
          temp->push_back(nums[j]);

          if(table[i + nums[j]] == nullptr ||
              temp->size() < table[i + nums[j]]->size())
          {
            delete table[i + nums[j]];
            table[i + nums[j]] = temp;
          }
        }
      }
    }
  }

  return *table[target_sum];
}

int main()
{
  vector<int> result = best_sum_tab(7, {2, 3, 4, 5});
  display_vector(result);
}