#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//s[i]-'0'でchar文字→int数に;
//string s = to_string(int数);
//int n = stoi(string文字列)
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  int n,m;
  
  cin >> n;
  vector<string> p(n);
  rep(i,n) {
  cin >> p[i];
  }
  sort(all(p));
  
  cin >> m;
  vector<string> q(m);
  rep(i,m) {
  cin >> q[i];
  }
  sort(all(q));
  
  int ans = 0;
  rep(i,n) {
    int cnt = 0;
    rep(j,n) {
      if(p[i]==p[j])cnt++;
    }
    rep(j,m) {
      if(p[i]==q[j])cnt--;
    }
    ans = max(ans,cnt);
  }
  
  cout << ans << endl;  
  
}