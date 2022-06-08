#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using llong = long long;

llong h[100000];
llong tmph[100000];
llong N,A,B,dif;

bool iskilled(llong m){
  llong center_cnt = 0;
  for(int i=0;i<N;++i){
    tmph[i] = h[i]-B*m;
    if(center_cnt<=m&&h[i]>B*m){
      llong cnt = (tmph[i])/dif + ((tmph[i]%dif)?1:0);
      if(center_cnt+cnt>m) cnt = center_cnt-m;
      center_cnt += cnt;
      tmph[i] -= cnt * dif;
    }
  }

  int killed_num = 0;
  for(int i=0;i<N;++i){
    if(tmph[i] <= 0) killed_num++;
  }
  return killed_num==N;
}

int main(){
  cin >> N >> A >> B;
  dif = A-B;
  llong maxh = 0;
  for(int i=0;i<N;++i){
    cin >> h[i];
    if(maxh<h[i]) maxh = h[i];
  }

  sort(h,h+N);

  llong ml = 0 , mr = maxh/B + ((maxh%B)?1:0);
  llong m;

  while(ml+1<mr){
    m = (ml+mr)/2;
  
    bool b = iskilled(m);
    if(b){
      mr = m;
    }else{
      ml = m;
    }
  }
  
  cout << m << endl;
  return 0;
}