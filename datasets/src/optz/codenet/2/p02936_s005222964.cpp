#include <bits/stdc++.h>;
using namespace std;
#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define REP(i,n) rep(i,0,n)
#define ll long long
#define ull unsigned long 

void dfs(vector<vector<ll>>& g,ll v,ll p,ll x,vector<ll>& con) //V子、P親
{
  con[v]+=x;
  for(auto next:g[v])
    if(next != p) 
      dfs(g,next,v,con[v],con);
}

int main()
{ 
  ll n,q;
  cin >> n >> q;
 vector<vector<ll>>  Ginf(n);
 REP(i,n-1)
 {
   ll a,b;
   cin >> a >> b;
   a--;
   b--;
   Ginf[a].push_back(b);
   Ginf[b].push_back(a);
 }
  vector<ll> con(n,0);
  
  REP(i,q)
  {
    ll p,x;
    cin >> p >> x;
    p--;
    con[p]=+x;
  }
  dfs(Ginf,0,-1,0,con);
  
 REP(i,n)
   cout << con[i] <<" ";
}