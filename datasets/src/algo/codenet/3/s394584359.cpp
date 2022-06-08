#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int a[N], b[N], c[N];
  for(int i=0;i<N;i++){cin >> a[i];}
  for(int i=0;i<N;i++){cin >> b[i];}
  for(int i=0;i<N;i++){cin >> c[i];}
  
  sort(a,a+N);
  sort(b,b+N);
  sort(c,c+N);
  
  int sum=0;
  int l=0;
  int u=0;
  
  for(int i=0;i<N;i++){
    
    for(int j=l;a[j]<b[i];j++){l++;}
    for(int k=u;b[i]>=c[k];k++){u++;}
    
    sum += l * (N-u);
  }
  
  cout << sum << endl;
  
  return 0;
}