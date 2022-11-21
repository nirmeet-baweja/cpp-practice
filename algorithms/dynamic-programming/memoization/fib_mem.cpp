#include<iostream>
#include<stdlib.h> // for strtol function
#include<unordered_map>

using namespace std;

unordered_map<int, int> memo;

int fib_memo(int n) {
  if(n <= 1) {
    memo[n] = n;
    return memo[n];
  }
  memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
  return memo[n];
}

int main(int argc, char* argv[]) {
  if(argc < 1) {
    cout << "\n"<< fib_memo(6) << endl;
    return 0;
  }

  long n = strtol(argv[1], NULL, 10);

  cout << "\nInbuilt number is : "<< 20 << " fib(n):"
       << fib_memo(20) << endl;

  cout << "\nNumber is : "<< n << " fib(n):"
       << fib_memo(n) << endl;

  cout << "\nMemo map:";

  for (auto it : memo)
  {
    cout << "memo[" << it.first << "] : " << it.second << endl;
  }

  return 0;
}
