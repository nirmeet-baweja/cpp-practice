#include<iostream>
#include<vector>

using namespace std;

void display_vector(vector<vector<int>> v)
{
  for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}

int grid_traveller_tab(int m, int n)
{
  vector<int> row(n+1, 0);
  vector<vector<int>> table(m+1, row);

  table[1][1] = 1;

  cout << "\n*****************************************\n";
  display_vector(table);
  cout << "\n*****************************************\n";

  for (int i = 0; i < table.size(); i++)
  {
    for (int j = 0; j < table[i].size(); j++)
    {
      // current pos contributes to the cell right and below it
      if(i+1 < table.size())
        table[i + 1][j] += table[i][j];

      if(j+1 < table[i].size())
        table[i][j + 1] += table[i][j];
    }
  }

  cout << "\n*****************************************\n";
  display_vector(table);
  cout << "\n*****************************************\n";

  return table[m][n];
}


int main()
{
  cout << grid_traveller_tab(3, 2) << endl;
  cout << grid_traveller_tab(5, 5) << endl;
}