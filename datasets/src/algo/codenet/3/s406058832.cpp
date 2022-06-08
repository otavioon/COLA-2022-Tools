# include <iostream>
# include <algorithm>

using namespace std;

int main() {
  int N, A[100000], B[100000], C[100000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);
  
  long ans = 0;
  for (int a_i = 0; a_i < N; a_i++) {
    for (int b_i = 0; b_i < N; b_i++) {
      	if (A[a_i] >= B[b_i]) continue;
        for (int c_i = 0; c_i < N; c_i++) {
          if (B[b_i] >= C[c_i]) continue;
          ans += 1;
        }
    }
  }
  cout << ans << endl;
  
  return 0;
}