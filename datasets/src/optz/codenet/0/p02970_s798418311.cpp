#include <bits/stdc++.h>

#define infi            2e9
#define infl            5e18
#define MX              100005
#define pi              2*acos(0.0)
#define ll              long long int
#define rr              read()
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define ms(a,b)         memset(a, b, sizeof(a))
#define loop(i,n)       for(register int i=0;i<n;i++)
#define pool(i,n)       for(register int i=n-1;i>=0;i--)
#define loop1(i,n)      for(register int i=1;i<=n;i++)
#define pool1(i,n)      for(register int i=n;i>0;i--)

using namespace std;

inline ll read(){char c=getchar();ll num,sign=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;for(num=0;c>='0'&&c<='9';){c-='0';num=num*10+c;c=getchar();}return num*sign;}
// inline ll pw(ll b, ll p){ll ans=1;while(p>0){if(p&1)ans*=b;p>>=1;b*=b;}return ans;}
// inline bool isPrime(ll n){if(n==1)return false;if(n==2)return true;if(!(n%2))return false;for(ll i=3;i<=sqrt(n);i+=2)if(!(n%i))return false;return true;}
// inline ll gcd(ll a, ll b){if(a==0)return b;return gcd(b%a,a);}

// //*************************************  Bitmask Opereations  **********************************//
// int Set(int N,int pos){return N=N | (1<<pos);}
// int reset(int N,int pos){return N= N & ~(1<<pos);}
// bool check(int N,int pos){return (bool)(N & (1<<pos));}
// //********************************************************************************************//


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //#ifdef rid.dle
    //freopen("in.txt", "r", stdin);
    //#endif
    
    ll n=rr,d=rr;

    d=(d*2LL)+1LL;

    ll ans=n/d + (n%d==0?0:1);

    cout << ans << endl;

    return 0;
}