#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, K;
  cin>>N>>K;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll l=0,r=mod,m;
  int tmp;
  while(l<r) {
    m = (l+r)/2;
    if(m==0) {
      l = 1;
      break;
    }
    tmp = 0;
    for(int i=0;i<N;++i) {
      if(A[i]<=m) continue;
      if(A[i]%m==0) {
        tmp += A[i]/m-1;
      }
      else {
        tmp += A[i]/m;
      }
    }
    if(tmp<=K) r = m;
    else l = m+1;
  }
  cout<<l<<endl;
}

