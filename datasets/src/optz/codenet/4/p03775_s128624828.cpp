#include <bits/stdc++.h>
using namespace std;
#define rep(i,c,n) for(int i=c;i<n;i++)

int ketacnt(long long int x){
  int cnt=0;
  while(x>0){
    x=x/10;
    cnt++;
  }
  
  return cnt;
}

int main(){
  long long int n;
  int ans=0;
  cin>>n;
  
  ans=ketacnt(n);
  
  for(long long int i=1;i*i<n;i++){
    if(n%i==0){
      int lena,lenb,tmpmax;
      lena=ketacnt(i);
      lenb=ketacnt(n/i);
      tmpmax=max(lena,lenb);
      ans=min(ans,tmpmax);
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
