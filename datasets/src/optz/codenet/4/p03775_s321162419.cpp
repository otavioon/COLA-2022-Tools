#include <bits/stdc++.h>
using namespace std;
#define rep(i,c,n) for(int i=c;i<n;i++)

int ketacnt(long long x){
  int cnt=0;
  while(x>0){
    x=x/10;
    cnt++;
  }
  
  return cnt;
}

int main(){
  long long n;
  int ans=0;
  cin>>n;
  
  ans=ketacnt(n);
  
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      const long long j=n/i;
      const int tmpmax=max(ketacnt(i),ketacnt(j));
      ans=min(ans,tmpmax);
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
