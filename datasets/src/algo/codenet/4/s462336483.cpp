#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    ll n,k;
    cin>>n>>k;
    set<ll> s;
    ll a;
    while(k--)
    {
        cin>>a;
        s.insert(a);
    }
    while(1)
    {
        ll tmp = n;
        ll f = 0;
        while(tmp>0)
        {
            if(s.find(tmp%10)!=s.end()) {f=1;break;}
            tmp/=10;
        }
        if(f) n++;
        else {cout<<n;break;}
    }
}
