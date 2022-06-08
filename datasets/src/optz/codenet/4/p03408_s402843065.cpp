#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) cin >> s[i];
  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < N; i++) cin >> t[i];
  vector<pair<string,int>> S;
  set<string> S2;
  for (int i = 0; i < N; i++){
    if (S2.count(s[i])){
      for (int j = 0; j < S.size(); j++){
        if (S[j].first == s[i]) S[j].second++;
      }
    } else {
      S.push_back(make_pair(s[i],1));
      S2.insert(s[i]);
    }
  }
  for (int i = 0; i < M; i++){
    if (S2.count(t[i])){
      for (int j = 0; j < S.size(); j++){
        if (S[j].first == s[i]) S[j].second--;
      }
    }
  }
  int res = 0 - M;
  for (int i = 0; i < S.size(); i++) res = max(res,S[i].second);
  cout << res;
}