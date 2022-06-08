#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
//ll longinf=1ll<<60;
int inf=1<<29;
int dh[4]={1,0,-1,0};
int dw[4]={0,1,0,-1};
ll longinf=(1ll<<31)-1;

int main(){
      ll n,a,b;
      cin>>n>>a>>b;
      ll ok = 1e18;
      ll ng = -1;
      ll h[n];
      rep0(i,n) cin>>h[i];
      sort(h,h+n);
      while(ok - ng > 1){
            ll pos=(ok+ng)/2;
            ll pp=pos;
            ll q[n]; 
            rep0(i,n){
                  q[i]=h[i]-(b*pos);
            }
            rep0(i,n){
                  pp-=max(0ll,((q[i]+a-b-1)/(a-b)));
            }
            if(pp>=0) ok=pos;
            else ng=pos;
      }
      cout<<ok<<endl;


      return 0;
}