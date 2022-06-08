#include <bits/stdc++.h>

#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

typedef long long ll;

inline int read(){
  int n=0,f=1;char c;
  for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
  if (c=='-') f=-1,c=getchar();
  for(;c>='0'&&c<='9';c=getchar()) n=(n<<3)+(n<<1)+(c&15);
  return n*f;
}

const int maxn=2e5+5;
int n,s,i,ans,a[maxn],j;
bool bz[maxn];

int main()
{
  n=read();
  fo(i,1,n) a[i]=read();
  sort(a+1,a+n+1);
  for(s=1<<30;s;s>>=1){
    j=n;
    fo(i,1,n) if (!bz[i]) {
      for(;j>i&&(a[j]>s-a[i]||bz[j]);j--);
      if (j<=i) break;
      if (a[j]==s-a[i]) bz[i]=bz[j]=1,ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}