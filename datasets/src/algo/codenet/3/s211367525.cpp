#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  
  ll a[N], b[N], c[N];
  for(int i=0;i<N;i++){cin >> a[i];}
  for(int i=0;i<N;i++){cin >> b[i];}
  for(int i=0;i<N;i++){cin >> c[i];}
  
  sort(a,a+N);
  sort(b,b+N);
  sort(c,c+N);
  
  ll sum=0;
  ll l=0;
  ll u=0;
  
  for(int i=0;i<N;i++){
    for(int j=l;a[j]<b[i] && j<N;j++){l++;}
    for(int k=u;b[i]>=c[k] && k<N;k++){u++;}
    sum += l * (N-u);
  }
  cout << sum << endl;
  
  return 0;
}
