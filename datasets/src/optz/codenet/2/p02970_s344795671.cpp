
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef vector< pii > vii;

#define ll          long long
#define ff          first
#define ss          second
#define pb          push_back
#define mkp         make_pair
#define sz          size()

#define forf(a,b,c)    for(int i=a;i<=b;i+=c)
#define forr(a,b,c)    for(int i=a;i>=b;i-=c)
#define all(a)      a.begin(),a.end()
#define mem(a,b)    memset(a,b,sizeof(a))
#define pi          2*acos(0.0)
#define End         return 0;
#define nl endl

#define scan1(a)    scanf("%d",&a)
#define scan2(a,b)  scanf("%d %d",&a,&b)
#define scan3(a,b,c)  scanf("%d %d %d",&a,&b,&c)
#define scanl(a)    scanf("%lld",&a)
#define scanll(a,b) scanf("%lld %lld",&a,&b)
#define scanlll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define print1(a)    printf("%d",a)
#define print2(a,b)  printf("%d %d",a,b)
#define print3(a,b,c)  printf("%d %d %d",a,b,c)
#define printl(a)    printf("%lld",a)
#define printll(a,b) printf("%lld %lld",a,b)
#define printlll(a,b,c) printf("%lld %lld %lld",a,b,c)

#define MAXN        100000007
#define INF 0x3f3f3f3f
bool mark[100005];vi prime;
void seive(ll N){for(int i=2;i<=N;i++){if(mark[i]==false){prime.pb(i);for(int j=i+i;j<N;j+=i)mark[j]=true;}}}
//freopen("input.txt", "r", stdin);

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,d;
    cin>>n>>d;
    ll res=d*2+1;
    res=ceil(n/(double)res);
    cout<<res<<endl;
    End;
}
