#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define uni(e) e.erase(unique(e.begin(),e.end()),e.end())
#define double long double
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int INF=1e10;
int MOD=1e9+7;
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
int kurai(int a,int b){
  int m=pow(10,b),n=pow(10,b-1);
  return (a%m)/n;
}
int ketawa(int a){
  int k=0;
  rep(i,keta(a)){
  k+=kurai(a,i+1);
  }
  return k;
}
int gcd(int a,int b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int mid(int a,int b,int c){
  vector<int> k(3);
  k[0]=a;k[1]=b;k[2]=c;
  sort(all(k));
  return k[1];
}
bool sosuu(int a){
  bool b=1;
  if(a<=1)
    return 0;
  else{
  rep1(i,sqrt(a)-1){
  if(a%(i+1)==0)
  b=0;
  }
  return b;
  }
}
int modpow(int a,int b,int m=MOD){
 if(!b)return 1; if(b&1)return modpow(a,b-1,m)*a%m;
 int memo = modpow(a,b>>1,m);
 return memo*memo%m;
}
int fact_mod(int n) {
    int f=1; 
for(int i=2;i<n+1;i++) f=f*(i%MOD)% MOD;
    return f;
}
int mod_pow(int x,int n) {
    int res=1;
    while(n>0){
        if(n&1) res=(res*x)%MOD; 
        x=(x*x)%MOD;        
n>>=1; 
    }
    return res;
}
int c_mod(int n, int r) {
    if(r>n-r) r=n-r;
    if(r==0) return 1;
    int a=1;
    rep(i,r) 
a=a*((n-i)%MOD)%MOD;
    int b=mod_pow(fact_mod(r), MOD-2);
    return (a%MOD)*(b%MOD)%MOD;
}
signed main(){
  int a;
  cin>>a;
  vector<int> b(a);
  rep(i,a)
    cin>>b[i];
  int c;
  cin>>c;
  vector<int> d(c);
  rep(i,c)
    cin>>d[i];
  int h=0;
  rep(i,a){
    int g=0;
  rep(j,a){
  if(b[i]==b[j])
    g++;
  }
    rep(j,c){
    if(b[i]==d[j])
      g--;
    }
    chmax(h,g);
  }
  out(h);
}