#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
  ll N;
  ll A[2*200000];
  ll used[2*200000];
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    used[i] = 0;
  }

  ll sum;
  ll bit_sum;
  int counter = 0;
  for (int i = 0; i < N; i++) {
    if (used[i] == 1) {
      continue;
    }
    for (int j = i+1; j < N; j++) {
      if (used[j] == 1) {
	continue;
      }
      sum = A[i] + A[j];
      if ((sum & 0x01) == 0x01) continue;
      bit_sum = 0;
      for (int k = 1; k < 64; k++) {
	bit_sum += ((sum >> k) & 0x01);
      }
      if (bit_sum == 1) {
	used[i] = 1;
	used[j] = 1;
	counter += 1;
      }
    }
  }
  cout << counter << endl;
}
