#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i,N) {
    cin >> s.at(i);
  }
  int M;
  cin >> M;
  vector<string> t(M);
  rep(j,M) {
    cin >> t.at(j);
  }
  
  int cand = 0;
  vector<bool> sChecked(N,false);
  
  rep(i,N) {
    if ( sChecked.at(i) ) {
      continue;
    }
    int count = 0;
    string pivot = s.at(i);
    rep(ii,N) {
      if ( s.at(ii) == pivot ) {
        count++;
        if ( sChecked.at(ii) == false ) {
          sChecked.at(ii) = true;
        }
      }
    }
    rep(jj,M) {
      if ( t.at(jj) == pivot ) {
        count--;
      }
    }
    if ( count > cand ) {
      cand = count;
    }
  }
  int answer = cand;
  cout << answer << endl;
}
