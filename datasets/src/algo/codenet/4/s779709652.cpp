#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define MOD 1000000007LL
#define calc_fact(n) tgamma(n+1)


signed main()
{
    FIO;
    ll n,k,a;
    cin>>n>>k;
    set<ll> s;
    for(ll i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    for(ll i=1;i<10;i++)
    {
        if(s.find(i)==s.end())
        {
            cout<<i*n;
            break;
        }
    }
}