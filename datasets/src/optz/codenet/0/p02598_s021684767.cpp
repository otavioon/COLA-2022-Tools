#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*pi*/double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;}
llfor;ll ans=0;////////////////////////////////////////////////////////////
ll n,k,a[300010];

ll f(ll c){//全ての木の高さをc以下にする
 ll x=0;
 rep(i,0,n)x+=(a[i]-1)/c;
return x;}


int main(){
 ll mx=0;
 cin>>n>>k;
 rep(i,0,n){
  cin>>a[i];
  mx=max(a[i],mx);
 }
 map<ll,bool>visited;
 ll now=mx;
 ll b1=0,b2;
 ll ans=0;
 while(f(now)!=k){
  //b1:一つ前, b2=nowをb1に移すためにメモ
  //cout<<now<<" "<<f(now)<<" "<<b1<<" "<<ans<<endl;
  b2=now;
  if(now<=0||now>mx)break;
  if(f(now)<k){
   now-=abs(now-b1)/2;
  }
  else if(f(now)>k){
   now+=abs(b1-now)/2;
  }
  b1=b2;
 }
 while(f(now)==k){
 // cout<<now<<" "<<f(now)<<" "<<b1<<" "<<ans<<endl;  
  now--;
 }
 ans=now+1;
 pr(ans);
 
 return 0;}

