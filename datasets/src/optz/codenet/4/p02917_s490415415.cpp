#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int N;
int B[102];
int sum;

int main() {
  cin >> N;
  rep(i, N-1) {
    cin >> B[i];
  }
  sum += B[0];
  sum += B[N-2];
  for(int i=1; i<N-1; i++) {
    sum += min(B[i], B[i-1]);
  }
  cout << sum << endl;
  return 0;
}

