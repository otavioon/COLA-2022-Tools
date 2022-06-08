#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
  string s;
  ll k;
  cin >> s >> k;
  string ss = s + s;
  int n = s.size();

  set<char> st;
  rep(i,n){
    st.insert(s[i]);
  }
  if(st.size()==1){
    cout << (n*k)/2 << endl;
  }

  else{
  ll tmp = 0;
  ll ans1 = 0;
  for(int i=1; i<n; i++){
    if(s[i-1]==s[i]){
      tmp++;
    }
    else{
      ans1 += (tmp+1)/2;
      tmp = 0;
    }
  }
  ans1 += (tmp+1)/2;

  tmp = 0;
  ll ans2 = 0;
  for(int i=1; i<n*2; i++){
    if(ss[i-1]==ss[i]){
      tmp++;
    }
    else{
      ans2 += (tmp+1)/2;
      tmp = 0;
    }
  }
  ans2 += (tmp+1)/2;
  cout << ans1 << " " << ans2 << endl;

  cout << (ans2-ans1)*(k-1) + ans1 << endl;
  }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}