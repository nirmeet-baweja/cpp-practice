#include<iostream>
#include<vector>
#include<string>

using namespace std;

void display_vector(vector<vector<string>>& v)
{
  for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}

vector<vector<string>> all_construct_tab(string target_string,
                                          vector<string> dict)
{
  /*
   * each element in table contains a 2D vector of strings.
   * each element of this 2D vector is a list of substrings from dict
   * that form the target_string
   */
  vector<vector<vector<string>>> table(target_string.size()+1);
  table[0] = {{}};

  // loop over each element in table
  for (int i = 0; i < table.size(); i++)
  {
    // if the position is reachable then only proceed
    if(table[i].size() > 0)
    {
      // loop through dict of words
      for (int j = 0; j < dict.size(); j++)
      {
        // if the target_string starts with substring dict[j]
        if(target_string.substr(i, dict[j].size()) == dict[j])
        {
          // check for the bounds
          if(i+dict[j].size() < table.size())
          {
            // table[i] is a 2D vector, loop through it
            for (int k = 0; k < table[i].size(); k++)
            {
              // table[i][k] refers to one possible combination of substrings
              vector<string> temp(table[i][k]);
              temp.push_back(dict[j]);
              table[i + dict[j].size()].push_back(temp);
            }
          }
        }
      }
    }
  }
  return table[table.size()-1];
}

int main()
{
  vector<vector<string>> result = all_construct_tab("abcdef",
                                                    {
                                                      "ab", "abc", "cd",
                                                      "def", "abcd", "ef"
                                                    });

  cout << "\n*****************************************" << endl;
  display_vector(result);
  cout << "\n*****************************************" << endl;

  result = all_construct_tab("skateboard",
                            {
                              "bo", "rd", "ate", "t", "ska", "sk", "boar"
                            });

  cout << "\n*****************************************" << endl;
  display_vector(result);
  cout << "\n*****************************************" << endl;

}