#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100;

char s[N+9];
int n,m;

void into(){
  scanf("%s%d",s+1,&m);
  n=strlen(s+1);
}

LL ans;

void Get_ans(){
  int c0=0,c1=0,l,r;
  for (int i=1;i<=n;++i){
	if (s[i]^s[1]) {l=i;break;}
	++c0;
  }
  if (c0==n) {ans=(LL)n*m>>1;return;}
  for (int i=n;i>=1;--i){
	if (s[i]^s[n]) {r=i;break;}
	++c1;
  }
  int lst=l,now=0;
  for (int i=l;i<=r+1;++i)
	if (s[i]==s[lst]) ++now;
    else{
	  ans+=(LL)m*(now>>1);
	  lst=i;now=1;
	}
  if (s[1]==s[n]){
    ans+=c0>>1;
    ans+=c1>>1;
    ans+=(LL)(m-1)*(c0+c1>>1);
  }else{
	ans+=(LL)m*(c0>>1);
	ans+=(LL)m*(c1>>1);
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}