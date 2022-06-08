#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector< vector<int> > vv32;
typedef vector< vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

// if needed
void solve()
{

}

int main()
{
    //variables
    string s,t;
    ll k;
    ll flag=0;
    //inputs
    cin>>s>>k;
    t = s;
  

    // logic
    char a,b;	
    ll ans=0,ans1=0;    
    ll num=0;
    if(s.length()==1)
    {
        cout<<k/2;
        return 0;
    }
    for(ll i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1])
        {
            flag=1;
        }
    }
    for(ll i=0;i<s.length();i++)
    {
        if(i==0)
        {
            a=t[i];
        }
        else
        {
            b=t[i];
        }
        if(i>0)
        {
            if(b==a)
            {
                ans+=1;
                a = '\0';
            }
            else
            {
                a=b;
            }
            
        }
    }
    t = s+s;
    for(ll i=0;i<t.length();i++)
    {
        if(i==0)
        {
            a=t[i];
        }
        else
        {
            b=t[i];
        }
        if(i>0)
        {
            if(b==a)
            {
                ans1+=1;
                a = '\0';
            }
            else
            {
                a=b;
            }
            
        }
    }
    if(k==1)
    {
        cout<<ans;
        return 0;
    }
    if(flag==0)
    {
        if(s.length()%2==0)
        {
            cout<<ans*k;
        }
        else
        {
            cout<< ans*k + k/2;    
        }
        return 0;
    }
    if(ans1==2*ans)
    {
        cout<<ans*k;
    }
    else
    {
        cout<<ans*k+ k-1;
    }
    

    // cout<<ans;

	return 0;
}
