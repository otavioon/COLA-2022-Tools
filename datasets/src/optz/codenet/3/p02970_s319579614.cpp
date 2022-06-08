#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long int
#define db long double
#define vlli vector<long long int >
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define cnl cout<<"\n";
#define fr(i,b) for(ll i=0; i<=b; i++)
#define frr(i,b) for(ll i=0;i<b;i++)
#define fb(i,b) for(ll i=b-1; i>=0; i--)
#define PI 3.14159265



 long int gcd(long long int a,long long int b){
  if(a<b) swap(a,b);
    if(b==0) return a;
    else return gcd(a%b,b);
 }

 bool comp(pair<long int ,long int>v1,pair<long int ,long int>v2){
          if(v1.ft==v2.ft) return v1.sd>v2.sd;
          else return v1<v2;
 }

 typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll i,j,k;
 

int main(){
   ll n,d; cin>>n>>d;
   ll x=n-2*d;
   if(x<=0) cout<<1<<endl;
   else {
    ll y;
    if(x%(d+1)==0) cout<<x/(d+1)<<endl;
    else cout<<(x/(d+1))+1<<endl;
   }




return 0;
}
