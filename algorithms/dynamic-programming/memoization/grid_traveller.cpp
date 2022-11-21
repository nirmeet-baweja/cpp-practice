#include<iostream>
#include<unordered_map>

using namespace std;

int grid_traveler_memo(int m, int n, unordered_map<string, int>& memo) {
  string key = "";
  if (m <= n) {
  key = to_string(m) + "-" + to_string(n);
  } else {
    key = to_string(n) + "-" + to_string(m);
  }

  if(memo.find(key) != memo.end()) {
    return memo[key];
  }

  if (m == 0 || n == 0) {
    return 0;
  }

  // if either dim is 1, then we have either a row or column vector.
  // that means we can move only in one direction and
  // hence there is only one way to reach destination i.e. bottom right
  if(m==1 || n==1) {
    return 1;
  }

  memo[key] = grid_traveler_memo(m - 1, n, memo)
              + grid_traveler_memo(m, n - 1, memo);

  return memo[key];
}

int grid_traveler(int m, int n) {
  unordered_map<string, int> memo;
  int result = grid_traveler_memo(m, n, memo);
  cout << "\nMemo:" << endl;
  for(auto it: memo) {
    cout << "memo[" << it.first << "]: " << it.second << endl;
  }

  return result;
}

int main() {
  cout << grid_traveler(5, 3) << endl;
  cout << grid_traveler(2, 3) << endl;
}