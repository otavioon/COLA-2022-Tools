
/*
    AUTHOR:hruday pabbisetty
    NIT ROURKElA(My_College_Sucks)
*/
#include <bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(0)
#define lli long long int
#define ulli unsigned long long int
#define I int
#define S string
#define D double
#define rep(i,a,b) for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define in(n) scanf("%lld",&n)
#define in2(a,b) scanf("%lld %lld",&a,&b)
#define in3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define out(n) printf("%lld\n",n)
#define inu(a) scanf("%lld",&a)
#define outu(a) printf("%llu",a)
#define ins(s) scanf("%s",&s)
#define outs(s) printf("%s",s)
#define nl printf("\n")
#define mod 1000000007
#define inf 100000000000000
typedef long long       ll;
typedef pair<lli,lli>  plli;
typedef vector<lli>     vlli;
typedef vector<ulli>    vulli;
typedef vector<ll>      vll;
typedef vector<string>  vs;
typedef vector<plli>     vplli;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)       cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)     cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)     cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define sz() size()
#define nl cout<<"\n"
#define MX1 100005
#define MX2 1000005
#define sqr(a) a*a*a
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

lli power(lli a,lli b)
    {
    lli value;
    if(b==0)
        {
        return 1;
    }
    else if(b%2==0)
        {
        value=power(a,b/2)%mod;
        return(value*value)%mod;
    }
    else
        {
        value=power(a,b/2)%mod;
        return ((a*value)%mod*(value))%mod;
    }
}
lli a[100005],n,A,B;
lli f(lli k)
{
    lli i,moves=0;
    rep(i,0,n)
    {
        if(a[i]-k*B<=0)
        {
            continue;
        }
        lli temp=a[i]-k*B,temp1=A-B;
        moves+=ceil(temp*1.0/temp1);
        if(ceil(temp/temp1)>k)
        {
            return 0;
        }
    }
    if(moves<=k)
    {
        return 1;
    }
    return 0;
}
int main()
{
      /*  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif*/
    opt;
    lli i;
    cin>>n>>A>>B;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    lli l=0,r=1000000000;
    lli ans=-1;
    while(l<=r)
    {
        lli mid=(l+r)/2;
        if(f(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
}
