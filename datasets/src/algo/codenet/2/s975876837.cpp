#include <cstdio>
#include <math.h>
#include <algorithm>
 
const int MAX_N = 200000;
 
long long int p[MAX_N];

long long int c = 0;
int n = 0;
long long int ret = 0;
int lowid, midid, highid;
long long int target = 0;

long long int nearPow = 1;

int find = 0;
 
void quickSort(long long int numbers[], int array_size) {
  std::sort(numbers, numbers + array_size);
}


void solve(int x) {
  if (x > 0){
    if ((p[x - 1] & (p[x - 1] - 1)) == 0) {
      if (p[x - 2] == p[x - 1]) {
        c += 1;
        solve(x - 2);
      } else {
        solve(x - 1);
      }
    } else if (p[x-1] % 2 == 0) {
      nearPow = pow(2.0, (floor(log2(p[x - 1] - 1)) + 1.0));
      target = nearPow - p[x - 1];
  
      highid = x;
      lowid = 0;
      find = 0;

      while (lowid <= highid) {
        midid = (lowid + highid) / 2;
        if (p[midid] == target) {
          while (p[midid] == p[midid - 1]) {
            midid -= 1;
          }
          c += 1;
          find = 1;
          break;
        } else if (p[midid] < target) {
          lowid = midid + 1;
        } else {
          highid = midid - 1;
        }
      }
      if (find == 1) {
        solve(x - 2);
      } else {
        solve(x - 1);
      }
    }
  }
}
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = 0; i < n; i++) {
    p[i] *= 2;
  }
  quickSort(p, n);
  solve(n);
  printf("%lld\n", c);
 
  return 0;
}
