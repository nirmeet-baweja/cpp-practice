#include<iostream>
#include<vector>

using namespace std;

void display_vector(vector<int>& v)
{
  cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << " }\n";
}

int cut_rod(int target_length, vector<int> prices)
{
  if(target_length == 0)
  {
    return 0;
  }

  if(target_length == 1)
  {
    return prices[0];
  }

  vector<int> best_prices(prices);

  for (int i = 1; i < target_length; i++)
  {
    int start = 0;
    int end = i - 1;
    int max_price = prices[i];

    while(start <= end)
    {
      int current_price = best_prices[start] + best_prices[end];
      if(current_price > max_price)
      {
        max_price = current_price;
      }
      start++;
      end--;
    }

    best_prices[i] = max_price;
  }

  cout << "\n*************************\n";
  display_vector(prices);
  cout << "\n*************************\n";
  display_vector(best_prices);
  cout << "\n*************************\n";

  return best_prices[target_length - 1];
}

int main()
{
  cout << cut_rod(8, {1, 5, 8, 9, 10, 17, 17, 20}) << endl;
  cout << cut_rod(8, {3, 5, 8, 9, 10, 17, 17, 20}) << endl;
}