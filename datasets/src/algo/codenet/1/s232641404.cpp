/* https://atcoder.jp/contests/abc088/tasks/abc088_c */

#include <iostream>

int sum = 0;

void solve()
{
  if (sum%3 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return;
}

int main(int argc, char *argv[])
{
  // Input
  int c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cin >> c;
      sum += c;
    }
  }

  // Output
  solve();

  return 0;
}
