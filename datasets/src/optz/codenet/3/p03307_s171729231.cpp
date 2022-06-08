#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define pvec(v) rep(i,v.size()){cout << v[i] << " ";};cout<<endl;
#define pb push_back
#define pf push_front
#define mod 1e9+7
#define m_p make_pair
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
const double pi = acos(-1.0);
 
ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n,ans=0;
    cin >> n;
    vll v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    cout << v[n-1] - v[0] << endl;
    return 0;
}
