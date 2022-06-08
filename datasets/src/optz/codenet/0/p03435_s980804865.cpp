#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  bool ans=false;
  int a,b,c,d,e,f,g,h,i,a1,a2,a3,b1,b2,b3;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
  for(int i=0;i<=a;i++){
    a1=i,b1=a-i;
    a2=d-b1,a3=g-b1;
    b2=b-a1,b3=c-a1;
    if(e==a2+b2&&f==a2+b3&&h==a3+b2&&i==a3+b3) ans=true;
  }
  if(ans) cout<<"Yes";
  else cout<<"No";
    
}