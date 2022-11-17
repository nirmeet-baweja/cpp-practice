#include<iostream>
#include<vector>
#include<string>

using namespace std;

int count_construct(string target_string, vector<string> dict)
{
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
      count += count_construct(remaining_string, dict);
    }
  }
  return count;
}

int main()
{
  cout << count_construct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef"}) << endl;
  cout << count_construct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
}