#include <cstdlib>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
#define pb push_back
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const double PI  =3.141592653589793238463;
long long MOD = 1000000007;

int stringToInteger(string x){
    int gg=0;
    //stringstream geek(x);
    //geek >> gg;
    return gg;
}

ll powmod(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0){ if(b%2)
        {ans*=a; ans%=m;}
         b/=2; a=a*a; a=a%m;
        }
        return ans%m;
}
ll gcd(ll a,ll b)
{

    return __gcd(a,b);
}
ll mulmod(ll a,ll b,ll m)
{  ll ans=0;
    a %=m;
    while (b>0)
    {       if(b&1) ans = (ans + a) % m;
        a = (a * 2)%m;
        b /= 2;
    }
    return ans % m;
}

ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a;
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD;
 	b /= 2;
 	}
 return x;
}
ll modInverse(ll a, ll m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
ll maxDivide(ll a, ll b)
{
  while (a%b == 0)
   a = a/b;
  return a;
}
  set<ll>ans;
void primeFactors(ll n)
{

    while (n % 2 == 0)
    {
       ans.insert(2);
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans.insert(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans.insert(n);
}
ll is(ll no)
{   if(no==1) return 0;
    set<ll>::iterator it;
for(it=ans.begin();it!=ans.end();it++){
  no = maxDivide(no, *it);
  if(no==1) return 1;
//  if()
 // no = maxDivide(no, 3);
 // no = maxDivide(no, 5);
}
//if(no==1) return 1;
//for(it=ans.begin();it!=ans.end();it++){
//if(no==*it) return 1;
//}
  return 0;
}

int comp(string a,string b)
{
    string aa = a.append(b);
    string bb = b.append(a);

    return aa.compare(bb) > 0 ? 1: 0;

}
vector<pair<int,int> >adj[100005];
int colors[100005]={0};
void dfs(int i,int color,int prev1=-1)
{
 for(int j=0;j<adj[i].size();j++)
 {
     if(adj[i][j].first==prev1) continue;
//cout<<adj[i][j].second<<endl;
     if(adj[i][j].second&1)
     {

         colors[adj[i][j].first]=1-color;
     }
     else
         colors[adj[i][j].first]=color;
     dfs(adj[i][j].first,colors[adj[i][j].first],i);

 }
}
bool com(const pair<string,pair<int,int> >&a, const pair<string,pair<int,int> >&b )
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second.first>b.second.first;

}
int main()
{

  int n,d;
  cin>>n>>d;
  if(n%(2*d+1)==0) cout<<n/(2*d+1)<<endl;
  else cout<<(n/(2*d+1))+1 <<endl;
}
