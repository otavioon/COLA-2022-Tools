#include<bits/stdc++.h>
using namespace std;
void rd(int &x){
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
void wt_L(int x){
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
multiset<int> s;
multiset<int>::iterator it;
int main(){
  int Lj4PdHRW, i, j, k=1<<30, res=0;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
    rd(i);
    s.insert(i);
  }
  while(s.size()){
    it = s.end();
    it--;
    i = *it;
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
  putchar_unlocked('\n');
  return 0;
}
// cLay varsion 20180730-1

// --- original code ---
// int N;
// multiset<int> s;
// multiset<int>::iterator it;
// {
//   int i, j, k = 1<<30, res = 0;
// 
//   rd(N);
//   rep(N){
//     rd(i);
//     s.insert(i);
//   }
// 
//   while(s.size()){
//     it = s.end();
//     it--;
//     i = *it;
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
