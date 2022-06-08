#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acs(const void *a, const void *b) { 
  return *(int*)a - *(int*)b;
} /* 1,2,3,4.. */
int des(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
} /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b) { 
  return *(char*)a - *(char*)b;
} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007

typedef long long int lli;

int main(void) {
  int c[10];
  rep(i, 0, 9) scanf("%d", &c[i]);

  int ok = 1;
  rep(j, 1, 3) {
    rep(i, 0, 2) {
      if (c[i+j*3] - c[i] == c[i+j*3+1] - c[i+1]) continue;
      ok = 0;
    }
  }
  printf(ok ? "Yes\n" : "No\n");
  return 0;
}
