#include <stdio.h>
#include <algorithm>

int main(void) {
  int i, c[3][3], j;
  for(i = 0; i < 3; ++i) for(j = 0; j < 3; ++j) scanf("%d", &c[i][j]);
  for(i = 0; i < 3; ++i) for(j = 2; j >= 0; --j) c[i][j] -= c[i][0];
  int s = 0;
  for(i = 0; i < 3; ++i) {
    for(j = 1; j < 3; ++j) {
      if(c[j][i] != c[0][i]) {
        s = 1;
        break;
      }
      if(s) break;
    }
  }
  if(s) printf("No");
  else printf("Yes");
  return 0;
}