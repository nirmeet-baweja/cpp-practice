#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>

using namespace std;

vector<int> best_sum_memo(int target_sum, vector<int> nums,
                            unordered_map<int,vector<int>>& memo)
{
  if(memo.find(target_sum) != memo.end())
  {
    return memo[target_sum];
  }

  if(target_sum < 0)
  {
    return vector<int>(1, INT_MIN);
  }

  vector<int> result;
  vector<int> temp;

  if (target_sum == 0)
  {
    return result;
  }

  for(int i = 0; i < nums.size(); i++)
  {
    int remaining_sum = target_sum - nums[i];
    temp = best_sum_memo(remaining_sum, nums, memo);
    if(temp != vector<int>(1,INT_MIN))
    {
      temp.push_back(nums[i]);
      if(result.size() == 0 || temp.size() < result.size())
      {
        result = temp;

      }
    }
  }

  if(result.size() == 0)
  {
    result = vector<int>(1, INT_MIN);
  }

  memo[target_sum] = result;

  return memo[target_sum];
}

vector<int> best_sum(int target_sum, vector<int> nums) {
  unordered_map<int, vector<int>> memo;
  vector<int> result = best_sum_memo(target_sum, nums, memo);
  return result;
}

int main()
{
  vector<int> result = best_sum(7, {2, 4, 6, 8});
  cout << "\n[ ";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << "]" << endl;

  cout << "*****************************************************";
  vector<int> result2 = best_sum(100, {1, 2, 5, 24});
  cout << "\n[ ";
  for (int i = 0; i < result2.size(); i++) {
    cout << result2[i] << " ";
  }
  cout << "]" << endl;
}