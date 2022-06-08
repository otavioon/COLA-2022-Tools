#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
//#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n),c(n);
  REP(i,n)cin>>a[i];
  REP(i,n)cin>>b[i];
  REP(i,n)cin>>c[i];
  sort(ALL(a));
  sort(ALL(a));
  sort(ALL(c));
  int ans=0;
  REP(i,n){
    auto itr=lower_bound(ALL(a),b[i]);
    auto it=upper_bound(ALL(c),b[i]);
    auto x=itr-a.begin();
    auto y=c.end()-it;
    //cout<<x<<' '<<y<<endl;
    ans+=x*y;
  }
  cout<<ans<<endl;
  return 0;
}
