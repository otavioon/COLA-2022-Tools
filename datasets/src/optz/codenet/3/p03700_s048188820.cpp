#include<bits/stdc++.h>
using namespace std;
int main(){
  #define int long
  long n,a,b,head=0,tail=1e+12;
  cin>>n>>a>>b;
  vector<int> h(n);
  for(int i=0;i<n;++i)cin>>h[i];
  int t,sum;
  while(tail-head>1){
    sum=0;
    t=(head+tail)/2;
    for(int i=0;i<n;++i){
      if(h[i]>b*t){
        int damt=(h[i]-b*t)/(a-b);
        if((h[i]-b*t)>damt*(a-b))damt++;
        sum+=damt;
      }
    }
    if(sum>t)head=t;
    else tail=t;
  }
  sum=0;
  t=head;
  for(int i=0;i<n;++i){
    if(h[i]>b*t){
      int damt=(h[i]-b*t)/(a-b);
      if((h[i]-b*t)>damt*(a-b))damt++;
      sum+=damt;
    }
  }
  if(sum>t)t=tail;
  else t=head;
  cout<<t;
  return 0;
}
