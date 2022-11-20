#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool can_construct_tab(string target_string, vector<string> dict)
{
  vector<bool> table(target_string.size() + 1, false);

  table[0] = true;

  for (int i = 0; i < table.size(); i++)
  {
    if(table[i])
    {
      for (int j = 0; j < dict.size(); j++)
      {
        if(target_string.substr(i, dict[j].size()) == dict[j])
        {
          if(i + dict[j].size() < table.size())
            table[i + dict[j].size()] = true;
        }
      }
    }
  }

  return table[table.size() - 1];
}

int main()
{
  cout << can_construct_tab("abcdef", {"ab", "abc", "cd", "def", "abcd"})
       << endl;
  cout << can_construct_tab("skateboard",
                            {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
       << endl;

  cout << can_construct_tab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
                        {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeee"})
       << endl;
}