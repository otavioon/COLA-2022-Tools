// Undone
#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
#define MOD 1000000007
#define FAST_IO {ios::sync_with_stdio(0);cin.tie(0);}
using namespace std;
signed main() {
  string S; int K;
  cin >> S >> K;
  int ans = 0;
  if (S.length() == 1) {
    ans = K/2;
  } else if (S.length() == 2) {
    if (S[0] == S[1]) {
      ans = K;
    } else {
      ans = 0;
    }
  } else {
    int one = 0, two = 0, three = 0;
    string twoS = S+S, threeS = S+S+S;
    for (int i = 0; i < S.length()-1; i++) {
      if (S[i] == S[i+1]) {
        one++;
        S[i+1] = '*';
      }
    }
    for (int i = 0; i < twoS.length()-1; i++) {
      if (twoS[i] == twoS[i+1]) {
        two++;
        twoS[i+1] = '*';
      }
    }
    for (int i = 0; i < threeS.length()-1; i++) {
      if (threeS[i] == threeS[i+1]) {
        three++;
        threeS[i+1] = '*';
      }
    }
    if (K == 1) {
      ans = one;
    } else if (K == 2) {
      ans = two;
    } else if (K == 3) {
      ans = three;
    } else {
      ans = two + ((three-two)*(K-2)); 
    }
  }
  cout << ans << endl; 
}

