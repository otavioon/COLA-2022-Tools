#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define int ll

int a[1000000];
bool b[1000000];

int binary_search(int v[],int x,int n){
  int l = 0;
  int r = n-1;

  while(r > l){
    int m = (r+l)/2;
    if(v[m] == x) return m;
    else if(v[m] > x) r = m-1;
    else l = m+1;
  }

  if(v[r]==x) return r;
  if(v[l]==x) return l;
  return -1;
}


int f(int a){
  int res=0;
  int k=1;
  int b = a;

  while(b&a){
    if(a&k){
      res+=k;
      a+=k;
    }
    k*=2;
  }

  return res;
}




signed main(){

  int n;
  cin>>n;

  rep(i,n){
    cin>>a[i];
  }

  sort(a,a+n);
  int ans=0;

  rrep(i,n-1){
    if(b[i]) continue;
    int c = f(a[i]);
    int k = binary_search(a,c,n);
    if(k!=-1&&k!=i&&!b[k]){
      b[i]=true;
      b[k]=true;
      ans++;
    }
  }



  cout<<ans<<endl;
}