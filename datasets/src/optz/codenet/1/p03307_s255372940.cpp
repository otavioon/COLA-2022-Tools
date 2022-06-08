#include <iostream>


using namespace std;


void eating_symbols_easy()
{
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < 4; ++i)
  {
    if (s[i] == '+') ++cnt;
    else --cnt;
  }
  cout << cnt << "\n";
}


void multiple_of_2_and_n()
{
  int n;
  cin >> n;

  if (n % 2 == 0) cout << n << "\n";
  else cout << 2 * n << "\n";
}


int main()
{
  //eating_symbols_easy();
  multiple_of_2_and_n();
}