#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
int N;
int B[99];
int main(){
  int i, res;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(B[Lj4PdHRW]);
    }
  }
  res = B[0] + B[N-2];
  for(i=(1);i<(N-1);i++){
    res +=min_L(B[i-1], B[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N, B[99];
// {
//   int res;
//   rd(N,B(N-1));
//   res = B[0] + B[N-2];
//   rep(i,1,N-1) res += min(B[i-1],B[i]);
//   wt(res);
// }
