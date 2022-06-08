#include <iostream>

int main()
{
  int c[9];
  for ( int i = 0; i < 9; i++ ) std::cin >> c[i];

  if ((c[1] - c[0] == c[4] - c[3]) && (c[4] - c[3] == c[7] - c[6]) && (c[2] - c[1] == c[5] - c[4]) &&(c[5] - c[4] == c[8] - c[7])) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
