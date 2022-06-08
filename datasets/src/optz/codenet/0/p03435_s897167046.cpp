#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }
void ans1(bool x){
  if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){
  if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){
  if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){
  if(x) cout<<y<<endl;else cout<<z<<endl;}   


int main(){
  ll i,j;
  //ll n; cin>>n;
  //ll a,b,c,d,e,f; cin>>a>>b;
  //ll a,b,c,d,e,f; cin>>a>>b>>c;
  //ll a,b,c,d,e,f; cin>>a>>b>>c>>d;
  //string s; cin >> s;
  ll result = 0;
  ll buf = 0;
  bool judge = true;

  ll a[4][4];
  for(i=1;i<=3;i++){
    for(j=1;j<=3;j++)cin>>a[i][j];
  }
  vector<ll> p={a[1][1]-a[1][2],a[1][1]-a[1][3]};
  vector<ll> q={a[2][1]-a[2][2],a[2][1]-a[2][3]};
  vector<ll> r={a[3][1]-a[3][2],a[3][1]-a[3][3]};
  judge=p[0]==q[0]&&p[0]==r[0]&&
        p[1]==q[1]&&p[1]==r[1];
  ans1(judge); 
  //cout<<p[0] spa p[1] spa q[0] spa q[1] spa r[0] spa r[1]<<endl;    

  return 0;
}