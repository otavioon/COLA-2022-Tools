#include<bits/stdc++.h>
using namespace std;
#define num 1000000007
//#define num 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define inarr(i,a,n,A) for(ll i=a;i<n;i++) { cin>>A[i]; }
#define vll vector<long long>
#define pii pair <int,int>
#define pll pair<long long, long long>
#define vpii vector< pair <int,int>>
#define vpll vector< pair<long long, long long>>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define avg(a,b) ((a)+(b))/2
#define push push_back
#define pop pop_back
#define mp make_pair
#define sf int flag=0     //Remember semicolon
#define assmin(a,b) if(b<=a) { a=b; }
#define assmax(a,b) if(b>=a) { a=b; }
#define f first
//#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
typedef long long ll;
ll mod(ll a, ll b)
{
	if(a%b<0)
	{
		return a%b + b;
	}
	return a%b;
}
 
 
ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;
	a=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll mymod(ll a,ll b)
{
    return ((a%b)+b)%b;
}
bool prime[200000];
vll v;
void SieveOfEratosthenes() 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
    for (int p=2; p*p<=200000; p++) 
    { 
        if (prime[p] == true) 
        { 
            v.push(p);
            for (int i=p*p; i<=200000; i += p) 
                prime[i] = false; 
        } 
    } 
}
ll powe[60];
void power()
{
    powe[0]=1;
    REP(i,1,15)
    {
        powe[i]=2*powe[i-1];
    }
}
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
        ll res = (x%m + m) % m;
        return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
ll fact[100005];
void factorial()
{
    fact[0]=1;
    REP(i,1,100002)
    {
        fact[i]=mymod(i*fact[i-1], num);
    }
}
void solve(ll h1,ll m1,ll h2,ll m2)
{
    ll h=h1-h2;
    ll m=m1-m2;
    if(m<0)
    {
        m+=60;
        h--;
    }
    if(h<10)
    {
        cout<<"0"<<h<<":";
    }
    else
    {
        cout<<h<<":";
    }
    if(m<10)
    {
        cout<<"0"<<m<<"\n";
    }
    else
    {
        cout<<m<<"\n";
    }
    return;
}
ll func(ll i)
{
    ll ans=1;
    for(ll k=4;k<=i;k+=2)
    {
        ans*=3;
        ans--;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    if(n*500<k) cout<<"No\n";
    else cout<<"Yes\n";
	return 0;
}
