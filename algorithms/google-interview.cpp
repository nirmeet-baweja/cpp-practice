#include<iostream>
#include<vector>
#include<utility>

using namespace std;

template<typename T> void display_2Dvector(vector<vector<T>> v)
{
  for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}

pair<int, bool> travel(vector<vector<char>>& skiMap, int r, int c, int path = 0) {
  cout << "\nCalling the travel function for r=" << r << ", c=" << c;

  cout << "\nPath is : " << path;

  bool reachedEnd = false;
  if (r == skiMap.size() - 1)
  {
    reachedEnd = true;
  }

  if(r<0 || r>= skiMap.size() || c<0 || c>=skiMap[0].size() || skiMap[r][c] == 'T') {
    return make_pair(0, false);
  }

  skiMap[r][c] = 'T';

  auto pathLeft = travel(skiMap, r, c - 1, path);
  auto pathRight = travel(skiMap, r, c + 1, path);
  auto pathDown = travel(skiMap, r + 1, c, path);

  reachedEnd = reachedEnd || pathLeft.second || pathRight.second || pathDown.second;

  path += pathLeft.first + pathRight.first + pathDown.first + 1;

  return make_pair(path, reachedEnd);
}

int longestPath(vector<vector<char>>& skiMap) {
  cout << "\nFinding the longest path.";

  int longest = 0;
  for (int c = 0; c < skiMap[0].size(); c++)
  {
    cout << "\nIn the for loop.";
    auto path = travel(skiMap, 0, c);
    if(path.second && path.first > longest) {
      longest = path.first;
    }
  }
  return longest;
}

int main() {
  // vector<vector<char>> skiMap{{'T', '.'}, {'T', '.'}};
  // display_2Dvector(skiMap);

  // int path = longestPath(skiMap);

  // cout << "\nPath is : " << path << endl;

  // cout << "\n**************************************\n";

  // vector<vector<char>> skiMap2{{'.', '.'}, {'T', '.'}};
  // display_2Dvector(skiMap2);

  // path = longestPath(skiMap2);

  // cout << "\nPath is : " << path << endl;


  cout << "\n**************************************\n";

  vector<vector<char>> skiMap3{{'.', 'T'}, {'.', 'T'}};
  display_2Dvector(skiMap3);

  int path = longestPath(skiMap3);

  cout << "\nPath is : " << path << endl;

  cout << "\n**************************************\n";

  vector<vector<char>> skiMap4{{'T', '.', 'T', '.', '.'},
                                {'.', '.', '.', 'T', '.'},
                                {'T', '.', 'T', '.', '.'},
                                {'T', '.', 'T', '.', '.'}};
  display_2Dvector(skiMap4);

  path = longestPath(skiMap4);

  cout << "\nPath is : " << path << endl;
}