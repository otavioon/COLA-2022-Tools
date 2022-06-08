#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
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
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int N;
int A;
int B;
int H[100000];
int main(){
  int KL2GvlyY, Q5VJL1cS, e98WHCEY, res;
  long long ok, t;
  rd(N);
  rd(A);
  rd(B);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(H[Lj4PdHRW]);
    }
  }
  KL2GvlyY = 1;
  Q5VJL1cS = 1000000000;
  while(KL2GvlyY < Q5VJL1cS){
    int i;
    if((KL2GvlyY + Q5VJL1cS)%2==0){
      e98WHCEY = (KL2GvlyY + Q5VJL1cS) / 2;
    }
    else{
      e98WHCEY = (KL2GvlyY + Q5VJL1cS - 1) / 2;
    }
    ok = e98WHCEY;
    for(i=0;i<(N);i++){
      t = H[i] - (long long) B * e98WHCEY;
      if(t > 0){
        ok -=divup_L(t,(A-B));
      }
    }
    if(ok >= 0){
      Q5VJL1cS = e98WHCEY;
    }
    else{
      KL2GvlyY = e98WHCEY + 1;
    }
  }
  res =Q5VJL1cS;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190827-1

// --- original code ---
// int N, A, B, H[1d5];
// {
//   int res;
//   ll ok, t;
//   rd(N,A,B,H(N));
//   res = bsearch_min[int,x,1,1d9][
//     ok = x;
//     rep(i,N){
//       t = H[i] - (ll) B * x;
//       if(t > 0) ok -= t /+ (A-B);
//     }
//   ](ok >= 0);
//   wt(res);
// }
