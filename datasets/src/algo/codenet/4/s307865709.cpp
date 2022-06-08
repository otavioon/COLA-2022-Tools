#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
const int N=200005;

ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }

bool ch(int num, set <int> st) {
    while(num>0) {
        int dig=num%10;
        if(st.find(dig)!=st.end()) return 0;
        num/=10;
    }
    return 1;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cout<<fixed<<setprecision(15);
    
    int n,k;
    cin>>n>>k;
    set <int> st;

    for(int i=0;i<k;i++) {
        int x;
        cin>>x;
        st.insert(x);
    }

    for(int i=n;i<1000000;i++) {
        if(ch(i, st)) {
            cout<<i;
            return 0;
        }
    }


    return 0;
}
