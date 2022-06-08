#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n+2];
  for(int i=0;i<n-1;i++){
    cin>>a[i];
  }
  int sum=0;
  sum=sum+a[0];
  int last=a[0];
  for(int i=1;i<n-1;i++){
    if(last>a[i]){
      sum=sum+a[i];
    }
    if(last<=a[i]){
      sum=sum+last;
    }
    last=a[i];
  }
  cout<<sum+a[n-2]<<endl;
  return 0;
}
    
