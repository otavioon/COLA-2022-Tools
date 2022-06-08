#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct pass {
  int l;
  int r;
  bool isQ;
  int index;
  bool operator<( const pass& right ) const {
    if (r == right.r) {
      return right.isQ;
    }
    return r < right.r;
  }
};

int main(int argc, char const *argv[]) {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  pass ps[M + Q + 1];
  // int L[M];
  // int R[M];
  // int p[Q];
  // int q[Q];
  int c[N + 1];
  int r[Q + 1];
  for (int i = 0; i <= N; i++) {
    c[i] = 0;
  }
  for (int i = 0; i <= Q; i++) {
    r[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d",&ps[i].l, &ps[i].r);
    ps[i].index = i;
    ps[i].isQ = false;
  }
  for (int i = M; i < M + Q; i++) {
    scanf("%d %d", &ps[i].l, &ps[i].r);
    ps[i].index = i - M;
    ps[i].isQ = true;
  }
  sort(ps, ps+M+Q);
  // for (int i = 0; i < M + Q; i++) {
  //   printf("%d %d %d\n", ps[i].l, ps[i].r, ps[i].isQ);
  // }
  for (int i = 0; i < M + Q; i++) {
    if (!ps[i].isQ) {
      c[ps[i].l]++;
    } else {
      for (int k = ps[i].l; k <= ps[i].r; k++) {
        r[ps[i].index + 1] += c[k];
      }
    }
  }
  for (int i = 1; i <= Q; i++) {
    printf("%d\n", r[i]);
  }
}
