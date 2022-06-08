#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 100000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;

/*---------------------------------------------------*/

int n,a,b,H;
ll l,r,mid;
vi h;

bool check(int cnt){
  ll index=upper_bound(all(h),cnt*b)-h.begin();
  ll con=cnt*b;
  for(ll i=index;i<n;i++){
    cnt-=(h[i]-con)/(a-b);
    if((h[i]-con)%(a-b)!=0)cnt--;
    if(cnt<0)return false;
  }
  return true;
}

int main(){
  scanf("%d%d%d",&n,&a,&b);
  rep(i,n){scanf("%d",&H);h.pb(H);}
  sort(all(h));
  l=0;r=1000000001;mid=(l+r)/2;
  while(l<r){
    if(check(mid))r=mid;
    else l=mid+1;
    mid=(l+r)/2;
  }
  printf("%lld\n",mid);
  return 0;
}
