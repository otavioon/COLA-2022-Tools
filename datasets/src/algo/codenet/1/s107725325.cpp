/*
  AtCoder Beginner Contest 088
  C - Takahashi's Information
*/

#include<iostream>
using namespace std;

int c;

int main() {
  int sum = 0, diag = 0;
  for (int i = 0; i < 9; ++i) {
    scanf("%d", &c);
    sum += c;
    if (i == 0 || i == 4 || i == 8) diag += c;
  }

  if (sum == diag * 3) printf("Yes\n");
  else printf("No\n");
  return 0;
}