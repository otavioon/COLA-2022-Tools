#include<cstdio>
using namespace std;

int c[3][3];
int a[3];
int b[3];

void solve() {
  int a_0, a_1, a_2;
  for(a_0 = 0; a_0 < 100; a_0++) {
    for(a_1 = 0; a_1 < 100; a_1++) {
      for(a_2 = 0; a_2 < 100; a_2++) {
        b[0] = c[0][0] - a_0;
        b[1] = c[1][1] - a_1;
        b[2] = c[2][2] - a_2;
        if (a_0 + b[1] == c[0][1] && a_0 + b[2] == c[0][2] && a_1 + b[0] == c[1][0] && a_1 + b[2] == c[1][2] && a_2 + b[0] == c[2][0] && a_2 + b[1] == c[2][1]) {
          printf("Yes");
          return;
        }
      }
    }
  }
  printf("No");
  return;
}

int main() {
  int i;
  for(i = 0; i < 3; i++) {
    scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
  }
  solve();
  return 0;
}