/* https://atcoder.jp/contests/abc088/tasks/abc088_c */

#include <iostream>

int main(int argc, char *argv[])
{
  int sum = 0;

  // Input
  for (int i = 0; i < 9; ++i) {
    int c;
    std::cin >> c;
    sum += c;
  }

  // Output
  if (sum%3 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
