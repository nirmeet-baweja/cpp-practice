#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool can_construct_memo(string target_string, vector<string> dict,
                        unordered_map<string, bool>& memo)
{
  if(memo.find(target_string) != memo.end())
  {
    return memo[target_string];
  }

  if(target_string == "")
  {
    return true;
  }

  for (int i = 0; i < dict.size(); i++)
  {
    if(target_string.find(dict[i]) == 0)
    {
      string new_target_string = target_string.substr(dict[i].size());
      if(can_construct_memo(new_target_string, dict, memo))
      {
        memo[target_string] = true;
        return memo[target_string];
      }
    }
  }

  memo[target_string] = false;
  return memo[target_string];
}

bool can_construct(string target_string, vector<string> dict)
{
  unordered_map<string, bool> memo;
  return can_construct_memo(target_string, dict, memo);
}

int main()
{
  cout << can_construct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
  cout << can_construct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
  cout << can_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                        {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeee"})
       << endl;
}