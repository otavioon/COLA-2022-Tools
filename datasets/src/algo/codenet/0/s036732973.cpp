#include<bits/stdc++.h>
using namespace std;
namespace mine
{
    typedef long long ll;
    #define pr pair<int,int>
    #define FR first
    #define SE second
    #define MP make_pair
    #define PB push_back
    #define vc vector
    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())
    #define bin(x) (1ll<<(x))
    #define GG(x) if(x) {puts("error");exit(666);}
    #define fo(i,l,r) for(int i=(l),I=(r);i<=I;i++)
    #define fd(i,r,l) for(int i=(r),I=(l);i>=I;i--)
    ll qread()
    {
        ll ans=0,f=1;char c=getchar();
        while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
        while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
        return ans*f;
    }
    void write(ll num)
    {
        if(num<0) putchar('-'),num=-num;
        if(num>=10) write(num/10);
        putchar('0'+num%10);
    }
    void write1(ll num){write(num);putchar(' ');}
    void write2(ll num){write(num);putchar('\n');}
    template<typename T> void chmax(T &x,const T y) {x=(x>y?x:y);}
    template<typename T> void chmin(T &x,const T y) {x=(x<y?x:y);}
    ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

    const int INF=0x3f3f3f3f;
    const int MOD=998244353;
    inline int mm(const int x){return x>=MOD?x-MOD:x;}
    template<typename T> inline void add(T &x,const T y){x=mm(x+y);}
    inline ll qpower(ll x,ll e,int mod=MOD){ll ans=1;GG(e<0)while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
    ll invm(ll x){return qpower(x,MOD-2);}
    const int N=3e5+10;

    char str[N];int fuk[N],ln[N];
    void main()
    {
        scanf("%s",str+1);int n=strlen(str+1);
        int k=qread();
        if(n==1){write(k/2);return;}
        int nowlen=0,cnt=0;ll ans=0;
        fo(i,2,n) if(str[i-1]==str[i])
        {
            if(nowlen==0) nowlen=2,fuk[i-1]=fuk[i]=++cnt;
            else nowlen++,fuk[i]=cnt;
        } else ans+=nowlen/2,ln[cnt]=nowlen,nowlen=0;
        ans+=nowlen/2;ln[cnt]=nowlen;

        if(str[1]==str[n])
        {
            if(fuk[1]==fuk[n] and fuk[1]>0) {write(1ll*n*k/2);return;}
            if(fuk[1]+fuk[n]==0) {write(1ll*(ans)*k+k-1);return;}
            if(fuk[1]>0 and fuk[n]>0) {write(1ll*(ans)*k+(k-1)*(ln[1]%2+ln[cnt]%2==2) );return;}
            if(fuk[1]>0) {write(1ll*(ans)*k+(k-1)*(ln[1]&1));return;}
            if(fuk[n]>0) {write(1ll*(ans)*k+(k-1)*(ln[cnt]&1));return;}
        }
        write(1ll*(ans)*k);
    }
};//(ans+MOD)%MOD
signed main()
{
    srand(time(0));
    mine::main();
}
