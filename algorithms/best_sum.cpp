#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> best_sum(int target_sum, vector<int> nums) {
  if(target_sum < 0) {
    cout << "\nsum less than 0";
    return vector<int>(1, INT_MIN);
  }

  vector<int> result(target_sum, 1);
  vector<int> temp;

  if (target_sum == 0) {
    cout << "\nsum is 0";
    return result;
  }


  cout << "\nFor loop start !";
  for (int i = 0; i < nums.size(); i++) {
    cout << "\nnums[i]: " << nums[i];
    int remaining_sum = target_sum - nums[i];
    cout << "\n Loop running for target_sum : " << remaining_sum;
    temp = best_sum(remaining_sum, nums);
    if(temp != vector<int>(1,INT_MIN)) {
      temp.push_back(nums[i]);
      if (temp.size() < result.size()) {
        cout << "\n found a better ans!";
        result = temp;
      }
    }
  }
  if(result == vector<int>(target_sum, 1)) {
    result = vector<int>(1, INT_MIN);
  }

  return result;
}

int main() {
  vector<int> result = best_sum(7, {2, 4, 6, 8});
  cout << "\n[ ";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << "]" << endl;
}