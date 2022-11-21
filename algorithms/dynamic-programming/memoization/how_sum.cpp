#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>

using namespace std;

vector<int> how_sum_memo(int target_sum, vector<int> nums,
                          unordered_map<int, vector<int>>& memo) {

  if(memo.find(target_sum) != memo.end()) {
    return memo[target_sum];
  }

  vector<int> result;
  if (target_sum == 0)
  {
    return result;
  }

  if(target_sum < 0) {
    return vector<int>(1,INT_MIN);
  }

  for (int i = 0; i < nums.size(); i++) {
    int remaining_sum = target_sum - nums[i];
    result = how_sum_memo(remaining_sum, nums, memo);
    if (result != vector<int>(1, INT_MIN))
    {
      result.push_back(nums[i]);
      memo[target_sum] = result;
      return memo[target_sum];
    }
  }

  memo[target_sum] = vector<int>(1, INT_MIN);
  return memo[target_sum];
}

vector<int> how_sum(int target_sum, vector<int> nums) {
  unordered_map<int, vector<int>> memo;
  vector<int> result = how_sum_memo(target_sum, nums, memo);
  return result;
}

int main() {
  vector<int> result = how_sum(300, {7, 14});
  cout << "[ ";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << "]" << endl;
}