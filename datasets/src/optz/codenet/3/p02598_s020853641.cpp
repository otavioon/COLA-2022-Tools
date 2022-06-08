#include <bits/stdc++.h>
#define ll long long
#define db double
#define iosks std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=5e5+10,M=3e4+10;
const ll inf=INT_MAX,mod=1e9+7;
const db pi=atan(1)*4;
ll pow2(ll a,ll b) {ll s=1; while(b) {if(b&1) s=(s*a)%mod; a=(a*a)%mod; b/=2; } return s;}
ll lcm(ll a,ll b) {return a/__gcd(a,b)*b; }
int read()
{
    int s=0,f=1; char ch=getchar();
    while(ch<'0'&&ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {s=s*10+ch-'0'; ch=getchar();} return s*f;
}

int n,k;
long double a[N];

int main()
{
    iosks;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    db l=0,r=1e9+10,mid;
    while(fabs(r-l)>0.0001){
        mid=(l+r)/2;
        int c=0;
        for(int i=0;i<n;i++) c+=ceil(a[i]/mid)-1;
        if(c>k) l=mid;
        else r=mid;
    }
    int ans=floor(mid+0.501);
    cout<<ans<<endl;
    return 0;
}
