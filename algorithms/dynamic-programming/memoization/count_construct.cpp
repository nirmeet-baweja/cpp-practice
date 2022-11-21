#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int count_construct_memo(string target_string, vector<string> dict,
                        unordered_map<string, int>& memo)
{
  if(memo.find(target_string) != memo.end())
  {
    return memo[target_string];
  }
  if(target_string == "")
  {
    return 1;
  }
  int count = 0;
  for (int i = 0; i < dict.size(); i++)
  {
    if(target_string.find(dict[i]) == 0)
    {
      string remaining_string = target_string.substr(dict[i].size());
      count += count_construct_memo(remaining_string, dict, memo);
    }
  }

  memo[target_string] = count;
  return memo[target_string];
}

int count_construct(string target_string, vector<string> dict)
{
  unordered_map<string, int> memo;
  return count_construct_memo(target_string, dict, memo);
}

int main()
{
  cout << count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef"})
       << endl;

  cout << count_construct("skateboard",
                        {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
        << endl;

  cout << count_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                        {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeee"})
       << endl;
}