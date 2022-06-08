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
  sort(c,c+N);
  
  int sum=0;
  
  for(int i=0;i<N;i++){
    int l=0;
    int u=0;
    
    for(int j=0;a[j]>=b[j];j++){l++;}
    for(int k=0;b[k]<=c[k];k++){u++;}
    
    sum += l * (N-u);
  }
  
  cout << sum << endl;
  
  return 0;
}
    

