#include <cstdio>
using namespace std;
int c[4][4];
int main() {
  for(int i = 1; i <= 3; i++) {
    scanf("%d %d %d", &c[i][1], &c[i][2], &c[i][3]);
  }
  int j1 = c[1][1]-c[1][2]==c[2][1]-c[2][2]&&c[2][1]-c[2][2]==c[3][1]-c[3][2];
  int j2 = c[1][2]-c[1][3]==c[2][2]-c[2][3]&&c[2][2]-c[2][3]==c[3][2]-c[3][3];
  if(j1 && j2) printf("Yes");
  else printf("No");
}