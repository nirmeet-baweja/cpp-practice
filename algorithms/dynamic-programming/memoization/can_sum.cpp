#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, bool> memo;

bool can_sum_memo(int target_sum, vector<int> nums) {

  if(memo.find(target_sum) != memo.end())
    return memo[target_sum];

  if (target_sum == 0)
    return true;

  if(target_sum < 0 )
    return false;

  for (int i = 0; i < nums.size(); i++) {
    int new_target_sum = target_sum - nums[i];
    if(can_sum_memo(new_target_sum, nums)) {
      memo[target_sum] = true;
      return memo[target_sum];
    }
  }

  memo[target_sum] = false;
  return memo[target_sum];
}

bool can_sum(int target_sum, vector<int> nums) {
  memo.clear();
  return can_sum_memo(target_sum, nums);
}

int main() {

  cout << can_sum(7, { 2, 3, 4, 5 }) << endl;
  for(auto it : memo) {
    cout << "\nmemo[" << it.first << "] : " << it.second << endl;
  }

  cout << can_sum(8, {2, 3, 4, 5}) << endl;
  for(auto it : memo) {
    cout << "\nmemo[" << it.first << "] : " << it.second << endl;
  }

  cout << can_sum(300, { 7, 14 });
  for(auto it : memo) {
    cout << "\nmemo[" << it.first << "] : " << it.second << endl;
  }
}