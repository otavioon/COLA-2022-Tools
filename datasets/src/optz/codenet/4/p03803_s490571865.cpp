#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, M;
  scanf("%d %d%*c", &N, &M);
  int i, j;
  int** A, **B;
  A = (int**)malloc(sizeof(int) * N);
  for (i = 0; i < N; i++)
    A[i] = (int*)malloc(sizeof(int) * N);
  B = (int**)malloc(sizeof(int) * M);
  for (i = 0; i < M; i++)
    B[i] = (int*)malloc(sizeof(int) * M);
  char c;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%c", &c);
      if (c == '.')
        A[i][j] = 0;
      else
        A[i][j] = 1;
    }
    scanf("%*c");
  }
  for (i = 0; i < M; i++) {
    for (j = 0; j < M; j++) {
      scanf("%c", &c);
      if (c == '.')
        B[i][j] = 0;
      else
        B[i][j] = 1;
    }
    scanf("%*c");
  }
  int k, l;
  int success;
  for (i = 0; i <= N - M; i++) {
    for (j = 0; j <= N - M; j++) {
      success = 1;
      for (k = 0; k < M; k++) {
        for (l = 0; l < M; l++) {
          if (A[i + k][j + l] != B[k][l]) {
            success = 0;
            break;
          }
          if (!success) break;
        }
      }
      if (success) break;
    }
    if (success) break;
  }
  if (success) printf("Yes\n");
  else printf("No\n");
  for (i = 0; i < N; i++)
    free(A[i]);
  for (i = 0; i < M; i++)
    free(B[i]);
  free(A);
  free(B);
  return 0;
}

