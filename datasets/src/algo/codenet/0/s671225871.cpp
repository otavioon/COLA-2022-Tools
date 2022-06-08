#include<bits/stdc++.h>
#include<array>
#define nguyendz the_best


#define ll long long
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
#define setpre(x) fixed<<setprecision(x)
//do not use "\n" in interactive problem
// ((x|y)-y) (x&(~y))
// __gcd(fibo(x),fibo(y)=fibo(__gcd(x,y))
//so luong tap hop gom d phan tu khac nhau dc tao tu k so phan biet la k mu d
// a+b=(a^b)+2*(a&b)
using namespace std;
const ll maxn=5e5+100;

const ll maxx=1e13;
const ll mod1=1000000007;
const ll mod2=998244353;
bool dd[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
    //  freopen("COUPONS.INP", "r", stdin);
    //  freopen("COUPONS.OUT", "w", stdout);
    string s;
    ll  k;
    cin>>s>>k;
    bool x=true;
    ll n= s.length();
    for (int i=1;i<n;i++)
    {
        if (s[i]!=s[i-1]) x=false;

    }
 if (x)
 {
     ll t= (ll)(s.length())*k;
     cout <<t/2;
     return 0;
 }
//  s.pb(s[0]);

  //   s=" "+s;
  ll bonus=0 ;
    if (s[n-1]==s[0])
    {
       ll l=0;
       char c= s[0];
       while (s[l]==c) l++;
       ll a= l;
       l=n-1;
       while (s[l]==c) l--;
       ll b= n-1-l;
       bonus=a/2+b/2-(a+b)/2;

    }
    ll dem=0;
     for (int i=0;i<n;)
     {
         char c= s[i];
         ll cnt=0;
         ll j=i;
         while (j<n&&s[j]==c)
         {
             cnt++;
             j++;
         }
         dem=dem+cnt/2;

         i=j;
     }
       ll t= (dem*k)+bonus*(k-1);
       cout <<t;






}

























