/*  Success may not come to me immediately,
 *  but it will come definitely....
 */
#include<bits/stdc++.h>
//=====================================================================
using namespace std;
//=====================================================================
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//=====================================================================
#define li      int64_t
#define ld      double_t
#define ulli    uint64_t
//=====================================================================
#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define repi(i,v)   for(i=v.begin();i!=v.end();i++)
#define repir(i,v)  for(i=v.rbegin();i!=v.rend();i++)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))
#define nl          cout<<'\n'
//=====================================================================
typedef vector<li>       vli;
typedef vector<string>   vstr;
typedef pair<li,li>      pli;
typedef pair<li,pli >    ppli;
typedef pair<li,ppli >   pppli;
typedef vector<pli >     vpl;
typedef vector<ppli >    vppli;
typedef vector<pppli >   vpppli;
//=====================================================================
#define pb  push_back
#define pob pop_back
#define pf  push_front
#define pof pop_front
#define all(v)  v.begin(),v.end()
#define itr iterator
#define rtr reverse_iterator
#define sz  size()
#define lb  lower_bound
#define ub  upper_bound
#define bs  binary_search
#define mp  make_pair
#define F   first
#define S   second
//=====================================================================
#define mod (li)(1e9+7)
#define inf (li)(1e18)
#define MX1 (li)(1e5+5)
#define MX2 (li)(1e6+5)
#define pi  acos(-1)
//=====================================================================
li power(li a,li b){li ans=1;while(b){if(b&1){ans=(ans*a)%mod;}
a=(a*a)%mod;b>>=1;}return ans;}
//=====================================================================
li mmi(li n){return power(n,mod-2);}
//=====================================================================
li two(li n){return (1LL<<n);}
//=====================================================================
void onbit(li &n,li x){n|=two(x);}
//=====================================================================
void offbit(li &n,li x){n&=~two(x);}
//=====================================================================
li cntbit(li n){li res=0;while(n and ++res)n-=n&-n;return res;}
//=====================================================================
li dx[]={-1,0,1,0},dy[]={0,-1,0,1};
//=====================================================================
/*------------------------MAIN CODE BEGINS NOW!------------------------*/

li n,k;
set<li> st;

void solve(){
  li i;cin>>n>>k;
  rep(i,0,n){
    li x;cin>>x;
    st.insert(x);
  }
  rep(i,n,MX2){
    li t=i;
    while(t){
      if(st.find(t%10)!=st.end()){
        break;
      }
      t/=10;
    }
    if(t==0){
      cout<<i;
      return ;
    }
  }
}

int main(){
  opt
  #ifndef ONLINE_JUDGE
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  #endif
  li t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}