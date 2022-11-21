#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

unsigned long fib_tab(unsigned int n)
{
  vector<unsigned long> table(n + 1, 0);
  table[1] = 1;

  for (int i = 0; i < table.size(); i++)
  {
    if(i+1 < table.size())
      table[i + 1] += table[i];

    if(i+2 < table.size())
      table[i + 2] += table[i];
  }

  return table[n];
}

int main()
{
  cout << fib_tab(6) << endl;
  cout << fib_tab(50) << endl;
}