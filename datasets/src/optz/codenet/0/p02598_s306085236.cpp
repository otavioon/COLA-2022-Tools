#include<bits/stdc++.h>
using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef pair<int,int> P;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lowbit(x) (x&-x)
const ll INF=0x3f3f3f3f;
const double EPS=1e-6;
const int N=2e5+10;
const ll mod=1e9+7;
inline ll read()
{  ll f=1,x=0;char ch=getchar();
   for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-') f=-1;
   for(;ch<='9'&&ch>='0';ch=getchar()) x=x*10+ch-'0';
   return x*f;
}
ll n,k;
double a[N];
bool check(double mid)
{  ll cnt=0;
   for(ll i=1;i<=n;i++)
   {  if(a[i]<=mid)continue;
      cnt=cnt+ceil((a[i]/mid));
      cnt--;
      if(cnt>k)return 0;
   }
   if(cnt>k)return 0;
   else return 1;
}
int main()
{  cin>>n>>k;
   for(int i=1;i<=n;i++)cin>>a[i];
   double l=0.0001,r=1e9+5,ans;
   while(r-l>=EPS)
   {  double mid=(l+r)/2;
      if(check(mid))
      {  ans=mid;
         r=mid-0.00000001;
      }
      else
      {  l=mid+0.00000001;
      }
   }
   printf("%.0f\n",max(1.0,ceil(ans-0.000001)));
}