#include <iostream>
#include <algorithm>
#include <vector>

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


void task_scheduling_problem()
{
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  cout << a[2] - a[0] << "\n";
}


void rated_for_me()
{
  int r;
  cin >> r;

  if (r < 1200) cout << "ABC\n";
  else if (r < 2800) cout << "ARC\n";
  else cout << "AGC\n";
}


void atcoder_crackers()
{
  int n, k;
  cin >> n >> k;

  if (n % k == 0) cout << 0 << "\n";
  else cout << 1 << "\n";
}


void garden()
{
  int a, b;
  cin >> a >> b;

  cout << (a - 1) * (b - 1) << "\n";
}


int main()
{
  //eating_symbols_easy();
  //multiple_of_2_and_n();
  //task_scheduling_problem();
  //rated_for_me();
  //atcoder_crackers();
  garden();
}