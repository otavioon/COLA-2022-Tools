#include <iostream>
#include <algorithm>

#define N_MAX 100000

using namespace std;



int main() {
  int N;
  int A[N_MAX], B[N_MAX], C[N_MAX];
  int ia, ib, ic;
  long long ans = 0;

  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", A + i);
  for(int i=0; i<N; i++) scanf("%d", B + i);
  for(int i=0; i<N; i++) scanf("%d", C + i);

  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);

  ia = ib = ic = 0;
  for(; ib < N; ib++) {
    for(; ia < N; ia++){
      if(A[ia] >= B[ib]) break;
    }
    for(; ic < N; ic++){
      if(C[ic] > B[ib]) break;
    }
    ans += ia * (N - ic);
  }

  printf("%llu\n", ans);

  return 0;
}
