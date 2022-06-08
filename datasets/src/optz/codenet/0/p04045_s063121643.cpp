#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N, K; cin >> N >> K;
  vector<int> D;
  REP(i, K) {
    int k; cin >> k;
    D.push_back(k);
  }
  bool flag = false;
  while(true) {
    string s = to_string(N);
    for(int i = 0; i < s.size(); ++i) {
      if(vector_finder(D, char_to_int(s[i])) == 1) {
        break;
      }
      if(i == s.size() - 1) {
        flag = true;
      }
    }
    if(flag == false) N++;
    else break;
  }
  cout << N << endl;
}