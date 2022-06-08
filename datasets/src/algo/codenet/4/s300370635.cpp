#include<bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(ll i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define pb push_back
#define X first
#define Y second

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
const ll INF = 1e18+1;
const ll MOD = 1000000007L;

#ifdef umang99m
    #include "/home/umang/.templates/header.h"
#else
    #define dbg(args...)
    #define timer()
#endif

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    set<int>d;
    rep(i,k) {
        int p;
        cin>>p;
        d.insert(p);
    }
    for(int i=n; i<MOD;i++){
        int temp = i;
        bool pos =true;
        while(temp > 0){
            if(d.count(temp%10)) pos = false;
            temp /= 10;
        }
        if(pos) {
        cout<<i<<endl;
        break;
        }

    }

    timer();
    return 0;

}
