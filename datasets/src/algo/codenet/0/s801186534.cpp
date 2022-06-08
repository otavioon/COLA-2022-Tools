#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();
  ll cnt = 1;
  ll ans = 0;
  if(s[0]!=s[n-1]){
    rep(i,n-1){
      if(s[i]==s[i+1])cnt++;
      if(s[i]!=s[i+1] || i==n-2) {
        ans+=cnt/2*k;
        cnt = 1;
        //cout << i << " " << ans <<endl;
      }
    }
    cout << ans << endl;
  }
  else{
    bool ok = true;
    rep(i,n){
      if(s[i]!=s[0])ok =false;
    }
    if(ok){
      cout << (n*k)/2 << endl;
      return 0;
    }
    ll p = 0;
    ll j = 0;
    while(s[j]==s[0]){
      if(j==n)break;
      p++;
      j++;
      
    }
    ll l = n-1;
    while(s[l]==s[n-1]){
      if(l<=j)break;
      l--;
      p++;
    }
    //cout << p << endl;
    ans+=p/2*(k-1);
    rep(i,n){
      if(i<j || i>l)continue;
      if(s[i]==s[i+1])cnt++;
      if(s[i]!=s[i+1] || i==l-1) {
        //cout << i << " " << (cnt+1)/2*k << endl;
        ans+=(cnt)/2*k;
        cnt = 1;
      }
    }
    //cout << p/2*(k-1) << endl;
    //cout << j/2*k << " " << (n-1-l)/2 << endl;
    ans+= j/2+(n-1-l)/2;
    cout << ans << endl;
  }
  
      
}




