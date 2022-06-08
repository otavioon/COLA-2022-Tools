#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(signed i=0;i<n;++i)
#define repi(n) rep(i,n)
#define int long long
#define str string
#define vint vector<int>
#define pint pair<int,int>
#define pb(a) push_back(a)
#define all(v) v.begin(),v.end()
#define yn(b) cout<<((b)?"Yes":"No")<<endl
#define YN(b) cout<<((b)?"YES":"NO")<<endl
#define call(a) for(auto t:a)cout<<t<<" ";cout<<endl
#define ENDL printf("\n");
#define debg(a) cout<<#a<<":"<<a<<endl;
#define SORT(a) sort(all(a));
#define INF 1LL<<60
#define inf INF
#define out(i) cout<<i<<endl;
#define allSum(a) accumulate(a.begin(),a.end(),0)
int min(int a,int b){if(a>b)return b;return a;}
int max(int a,int b){if(a>b)return a;return b;}

bool check(int n,vector<char> d){
  str s=to_string(n);
  rep(i,s.length()){
    rep(j,d.size()){
      if(s[i]==d[j])return false;
    }
  }
  return true;
}

signed main(){
  int n,k;
  cin>>n>>k;
  vector<char> a(k);
  rep(i,k)cin>>a[i];
  int ans;
  for(ans=n;ans<=100000;++ans){
    if(check(ans,a))break;
  }
  cout<<ans<<endl;
  return 0;
}

