#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<pair<string,int>> S;
  set<string> S2;
  for (int i = 0; i < N; i++){
    string s;
    cin >> s;
    if (S2.count(s)){
      for (int j = 0; j < S.size(); j++){
        if (S[j].first == s) S[j].second++;
      }
    } else {
      S.push_back(make_pair(s,1));
      S2.insert(s);
    }
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++){
    string t;
    cin >> t;
    if (S2.count(t)){
      for (int j = 0; j < S.size(); j++){
        if (S[j].first == t) S[j].second--;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < S.size(); i++) res = max(res,S[i].second);
  cout << res;
}