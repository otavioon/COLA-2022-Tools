#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin>>a;
  int64_t n;
  cin>>n;
  int w=1;
  int kk=0;
  a.push_back('<');
  for(int i=0;i<a.size()-1;i++){
    
    
    if(a[i]==a[i+1]){
      w++;
    }
    else if(w!=1){

      kk+=w/2;
      w=1;
    }
    
  }

  int64_t ans=kk*n;
  


  if(a[0]==a[a.size()-2]){
    
  int g=1;
  int e=1;
  
  for(int i=0;i<a.size()-1;i++){
    if(a[i]!=a[i+1]){
      if(i==0){
        g=0;
      }
      break;
    }
    else if(a[i]==a[a.size()-2]){
      g=0;
      break;
    }
    else{
      g++;
    }
    
  }
  for(int i=a.size()-2;i>0;i--){
    if(a[i]!=a[i-1]){
      if(i==a.size()-2){
        e=0;
      }
      break;
    }
    else if(a[i]==a[1]){
      e=0;
      break;
    }
    else{
      e++;
    }
  }
  if(g%2==1 && e%2==1){
    ans-=n-1;
  }
  }
  if(a==string(a.size(),a[0])){
    ans=a.size()*n/2;
  }
  cout<<ans<<endl;
}
