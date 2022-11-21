#include<iostream>
#include<vector>
#include<string>

using namespace std;

void display_vector(vector<unsigned long>& v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

unsigned long count_construct_tab(string target_string, vector<string> dict)
{
  vector<unsigned long> table(target_string.size() + 1, 0);

  table[0] = 1;

  for (int i = 0; i < table.size(); i++)
  {
    if(table[i] > 0)
    {
      for(int j=0; j < dict.size(); j++)
      {
        if(target_string.substr(i, dict[j].size()) == dict[j])
        {
          if(i + dict[j].size() < table.size())
          {
            table[i + dict[j].size()] += table[i];
          }
        }
      }
    }
  }

  display_vector(table);

  return table[table.size() - 1];
}

int main()
{
  cout << count_construct_tab("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef"})
       << endl;

  cout << count_construct_tab("skateboard",
                        {"bo", "rd", "ate", "t", "ska", "sk", "boar"})
        << endl;

  cout << count_construct_tab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
                        {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeee"})
       << endl;
}