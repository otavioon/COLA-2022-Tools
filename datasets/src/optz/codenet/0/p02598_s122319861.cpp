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
#include<deque>
#include<iomanip>
#include<utility>
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
#define S 21 
llfor;
const ll mod=1000000007;
/*pi*/const double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll ans=1;rep(i,0,n){ans*=x;}return ans;}
/*階乗*/ll fact(ll x){ll ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)*fact(n-r)/fact(r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=1,tmp=n;while(tmp/10>0){tmp/=10;d++;}return d;}
/*行列のコピー*/void matcpy(ll a[S][S],ll b[S][S]){ll t=i;rep(i,0,S)rep(j,0,S)b[i][j]=a[i][j];/*(aをbに)*/i=t;}
/*行列のリセット*/void matrst(ll a[S][S]){ll t=i;rep(i,0,S)rep(j,0,S)a[i][j]=0;i=t;}
/*行列の2乗*/void matpow(ll a[S][S]){ll ans[S][S];matrst(ans);ll t=i,k;rep(i,0,S)rep(j,0,S)rep(k,0,S)ans[i][j]+=a[i][k]*a[k][j];matcpy(ans,a);i=t;}
/*行列の乗算*/void matmul(ll a[S][S],ll b[S][S], ll as[S][S]){ll t=i,k;matrst(as);rep(i,0,S)rep(j,0,S)rep(k,0,S)as[i][j]+=a[i][k]*b[k][j];i=t;}
//ll ans=0;
////////////////////////////////////////////////////////////
int main(){
 ll a,b;cin>>a>>b;
 ll n;
 priority_queue<ll>log;
 ll sum=0;
 rep(i,0,a){
  cin>>n;
  log.emplace(n);
  sum+=n;
 }
 ll cnt=0,tmp;
 ll a1,tp,a2;
 ll ave=cei(sum,a+b);
 while(cnt<b){
  tp=log.top();
  log.pop();
  cnt++;
  if(cnt*2<b){
   a1=cei(tp,3);
   cnt++;
  }
  else a1=cei(tp,2);
  log.emplace(a1);
 // cout<<cnt<<" "<<tp<<" "<<a1<<" "<<tmp<<" "<<ave<<endl;
 }
 ll ans=log.top();
 pr(ans);
return 0;}
// (10^x -1)*7/9=n*k
// (10^x -1)*7=n*k*9
// nが7の倍数じゃないときは、kは7の倍数