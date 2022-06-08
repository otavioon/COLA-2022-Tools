#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ll N; cin >>N;
  ll a[N],b[N],c[N],ap,bp,cp,r;
  for(int i=0;i<N;i++){ cin >> a[i]; }
  for(int i=0;i<N;i++){ cin >> b[i]; }
  for(int i=0;i<N;i++){ cin >> c[i]; }
  sort(a,a+N);
  sort(b,b+N);
  sort(c,c+N);
  ap=bp=cp=N-1;
  r=0;
  while(cp>=0)
    {
    while( (bp>=0) && (b[bp]>=c[cp]) ){--bp;}
    while( (ap>=0) && (a[ap]>=b[bp]) ){--ap;}
    if(ap<0 || bp<0){break;}
    r += (ap+1)*(bp+1);
    --cp;
  }
  cout << r <<"\n";
  return 0;
}
