#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define SZ(x) ((int)(x).size())
// #define endl "\n"
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
ll mod = 1e9 + 7;
//const double pi = acos(-1.0);
/*
ll kmp(string x)
{
    ll n= x.length();
    //cout<<x<<endl;
    vector<ll> lcp(x.length(), 0);
    for(ll i=1;i<n;i++)
    {
        ll j=lcp[i-1];
        while(j>0 && x[j]!=x[i])
            j=lcp[j-1];
        if(x[i]==x[j])
            j++;
        lcp[i]=j;
    }
    return lcp[n-1];
}

int N = 1000002;
int ar[100002];
void sieve()
{
    for(int i=1;i<=N;i++)
        ar[i] = 1;
    ar[0] = 0;
    for(int i=2;i*i<=N;i++)
    {
        if(ar[i] && i*i<=N)
        {
            for(int j = i*i; j<=N;j+=i)
                ar[j] = 0;
        }
    }
}

ll modex(ll a,ll b){
    if(b<=0){
        return 1;
    }
    if(b%2==0)
    {
        ll x = modex(a, b/2);
        return ((x*x)%mod);
    }
    else
        return ((a%mod * modex(a, b-1))%mod);
}

ll c[1010][1010];

ll combina(ll i, ll j){
        for (int i=0;i<=1005;i++)
        for (int j=0;j<=i;j++)
        {
            if (j==i||j==0)
                c[i][j]=1;
            else
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=mod;
        }
        return c[i][j];
}
void find_fac(int x){
    vector<ll> di;
    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i==0){
            di.push_back(i);
            while(x%i==0)
                x/=i;
        }
    }
    if(x > 1)
        di.push_back(x);
}
*/
ll n, k;
vector<ll> a;
ll fun(ll m){
    ll c = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<=m)
            continue;
        ll x = (a[i]+m-1)/m;
        c += (x-1);
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(12);
    cin>>n>>k;
    a.resize(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll l=1, r = 1e9, an=1e9;
    while(l<=r){
        ll m = (l+r)/2;
        if(fun(m)>k)
            l = m+1;
        else{
            an = min(an, m);
            r = m-1;
        }
    }
    cout<<an<<endl;
    return 0;
}
