#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
inline char tc(){
  static char fl[100],*A=fl,*B=fl;
  return A==B&&(B=(A=fl)+fread(fl,1,100,stdin),A==B)?EOF:*A++;  
}
inline int read(){
  int a=0;static char c;
  while((c=tc())<48||c>57);
  while(c>=48&&c<=57)a=a*10+c-48,c=tc();
  return a;
}
int h[100001];
int main(){
  int n=read(),a=read(),b=read();a-=b;
  double a_=1.0/a;
  rep(i,n)h[i]=read();
  int left=0,right=1000000000;
  ll temp,cnt=0,mid;
  while (right>left+1) {
    mid=(right+left)>>1;
    cnt=0;
    rep(i,n){
      temp=h[i]-b*mid+a-1;
      if(temp>0)cnt+=temp*a_;
    }
    if(cnt<=mid)right=mid;
    else left=mid;
  }
  printf("%d\n",right);
}