#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) 
#define repi(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v) rep(i,v.size()) {cin >> v[i];}
//最終奥義
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

#define pint pair<int,int>

signed main(void){
  int n,q;cin >> n >> q;
  vint tree(n);
  vint ans(n,0);

  rep(i,n-1){
    int a,b;cin >> a >> b;
    tree[b-1]=a-1;
  }
  

  vector<pint> px(q);
  rep(i,q){
    int p,x;cin >> p >> x;
    pint t = make_pair(p-1,x);
    px[i]=t;
  }

  vsort(px);

  rep(i,q){
    if(px[i].first==0){
      ans[0]+=px[i].second;
      continue;
    }
    int t = px[i].first;
    if(ans[t]==0){
      ans[t]+=ans[tree[t]];
    }
    ans[t]+=px[i].second;
  }
  rep(i,n)
    if(ans[i]==0){
      ans[i]+=ans[tree[i]];
    }

  rep(i,n)
    cout << ans[i] << " ";
  cout << endl;
}
