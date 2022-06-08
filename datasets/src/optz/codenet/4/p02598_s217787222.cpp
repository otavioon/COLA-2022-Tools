#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline int my_getchar_unlocked(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread_unlocked(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
int N;
int K;
int A[200000];
int main(){
  long long ok;
  long long res;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  long long e98WHCEY;
  long long cTE1_r3A;
  long long RZTsC2BF;
  e98WHCEY = 1;
  {
    int FmcKpFmN;
    int xr20shxY;
    if(N==0){
      xr20shxY = 0;
    }
    else{
      xr20shxY = A[0];
      for(FmcKpFmN=(1);FmcKpFmN<(N);FmcKpFmN++){
        xr20shxY = max_L(xr20shxY, A[FmcKpFmN]);
      }
    }
    cTE1_r3A =xr20shxY;
  }
  while(e98WHCEY < cTE1_r3A){
    int i;
    if((e98WHCEY + cTE1_r3A)%2==0){
      RZTsC2BF = (e98WHCEY + cTE1_r3A) / 2;
    }
    else{
      RZTsC2BF = (e98WHCEY + cTE1_r3A - 1) / 2;
    }
    ok = 0;
    for(i=(0);i<(N);i++){
      ok += (A[i]-1) / RZTsC2BF;
    }
    if(ok <= K){
      cTE1_r3A = RZTsC2BF;
    }
    else{
      e98WHCEY = RZTsC2BF + 1;
    }
  }
  res =cTE1_r3A;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// int N, K, A[2d5];
// {
//   ll ok, res;
//   rd(N,K,A(N));
//   res = bsearch_min[ll,x,1,max(A(N))][
//     ok = 0;
//     rep(i,N) ok += (A[i]-1) / x;
//   ](ok <= K);
//   wt(res);
// }
