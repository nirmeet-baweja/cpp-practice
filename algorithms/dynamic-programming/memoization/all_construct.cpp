#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<string>> all_construct(string target_string, vector<string> dict)
{
  if(target_string == "")
  {
    return vector<vector<string>>{{}};
  }

  vector<vector<string>> result;

  for (int i = 0; i < dict.size(); i++)
  {
    if(target_string.find(dict[i]) == 0)
    {
      string suffix = target_string.substr(dict[i].size());
      vector<vector<string>> suffix_ways = all_construct(suffix, dict);
      // vector<vector<string>> target_ways(suffix_ways.size());
      for (int j = 0; j < suffix_ways.size(); j++)
      {
        suffix_ways[j].insert(suffix_ways[j].begin(), dict[i]);
        result.push_back(suffix_ways[j]);
      }
    }
  }
  return result;
}

void display_vector(vector<vector<string>> v)
{
  for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
  vector<vector<string>> result = all_construct("abcdef", {"ab", "abc", "cd",
                                                "def", "abcd", "ef"});

  display_vector(result);


  result = all_construct("skateboard",
                         {"bo", "rd", "ate", "t", "ska", "sk", "boar"});

  cout << "\n*****************************************" << endl;
  cout << "\n" << result.size() << endl;
  display_vector(result);
  cout << "\n*****************************************" << endl;

  // result = all_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
  //                        {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeeee", "eeeeeeeeee"});
  // cout << "\n*****************************************" << endl;
  // cout << "\n" << result.size() << endl;
  // display_vector(result);
  // cout << "\n*****************************************" << endl;
}