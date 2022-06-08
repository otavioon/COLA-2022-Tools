#include <cstdio>
#include <queue>
using namespace std;

int main(){
  int c[4][4];
  for (int i = 1; i < 4; i++){
    for (int j = 1; j < 4; j++){
      int k;
      scanf("%d", &k);
      c[i][j] = k;
    }
  }

  int a[4];
  int b[4];

  a[1] = 0;
  for (int i = 1; i < 4; i++){
    b[i] = c[1][i] - a[1];
    a[i] = c[i][1] - b[1];
  }
  for (int i = 1; i < 4; i++){
    for (int j = 1; j < 4; j++){
      if (c[i][j] != a[i] + b[j]) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  return 0;
}
