#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
multiset<int> s;
multiset<int>::iterator it;
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k = 1<<30;
  int res = 0;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    s.insert(rd_int());
  }
  while(s.size()){
    it = s.end();
    i = *(--it);
    s.erase(it);
    while(k/2 > i){
      k /= 2;
    }
    j = k - i;
    it = s.lower_bound(j);
    if(j == *it){
      res++;
      s.erase(it);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// multiset<int> s;
// multiset<int>::iterator it;
// {
//   int i, j, k = 1<<30, res = 0;
// 
//   REP(rd_int()) s.insert(rd_int());
// 
//   while(s.size()){
//     it = s.end();
//     i = *(--it);
//     s.erase(it);
//     
//     while(k/2 > i) k /= 2;
//     j = k - i;
//     it = s.lower_bound(j);
//     if(j == *it){
//       res++;
//       s.erase(it);
//     }
//   }
// 
//   wt(res);
// }
