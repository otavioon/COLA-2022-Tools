#include<iostream>
#include<sstream>
#include<iomanip>
#include<bitset>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#define lli long long int
#define uli unsigned long long int
#define inf 999999999999999999
#define rep(i,n,m) for(lli i=(lli)(n);i<(lli)(m);++i)
#define reep(i,n,m) for(int i=(int)(n);i<=(int)(m);++i)
#define per(i,m,n) for(lli i=(int)(m)-1;i>=(int)(n);--i)
#define st(n) sort(n.begin(), n.end())
#define rev(n) reverse(n.begin(),n.end())
#define ou(S) cout << S << endl
#define pb(n) push_back(n)
#define ue(N) N.erase(unique(N.begin(),N.end()),N.end());
#define nou(S) cout << S
#define hou(S) cout << setprecision(30) << S << endl
#define vec(K,L,N,S) vector<L> K(N,S)
#define dv(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define tv(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define maxx 5100000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
using namespace std;
int main(){
  int n,d;cin>>n>>d;
  rep(i,0,8){
    n-=d*2+1;
    if(n<=0){
      cout<<i+1<<endl;
      return 0;
    }
  }
 // cout<<((n/(d*2+d-1)==0)?n/(d*2+d-1):n/(d*2+1)+1)<<endl;
}