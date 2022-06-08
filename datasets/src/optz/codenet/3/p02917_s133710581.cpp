#include<bits/stdc++.h>
using namespace std;
int main(){ 
  long long n,a[100],b[100],c=0;
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
     if(i==0){
        if(a[i]<a[i+1]){
          b[i]=a[i];
          b[i+1]=a[i];
        }
        else{
          b[i]=a[i];
          b[i+1]=a[i+1];
        }
      }
      if(a[i]<a[i+1]){
         b[i+1]=a[i];
      }
      else{
        b[i+1]=a[i+1];
      }
  }
  for(int i=0;i<n;i++)
    c+=b[i];
 
  cout<<c<<endl;
  return(0);
}