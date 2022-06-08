#include<iostream>
#include<algorithm>
using namespace std;;
int main(){
  
  long long n;
  cin >>n;
  long long a[n],b[n],c[n];
  for(long long i=0;i<n;i++){
  cin >> a[i];}
  sort(a,a+n);
    for(long long i=0;i<n;i++){
  cin >> b[i];}
   sort(b,b+n);
  for(long long i=0;i<n;i++){
  cin >> c[i];}
   sort(c,c+n);/*
    for(long long i=0;i<n;i++){
  cout << a[i]<<" ";}
  cout<<endl;
    for(long long i=0;i<n;i++){
  cout << b[i]<<" ";}cout<<endl;
    for(long long i=0;i<n;i++){
  cout << c[i]<<" ";}*/
  long long ans=0;
 for(long long i=0;i<n;i++){
 for(long long j=0;j<n;j++){
   if(a[i]<b[j]){
 for(long long k=0;k<n;k++){
   if(b[j]>=c[k]){
   }
   else{
     //cout<<"n-k="<<n-k<<endl;
   ans+=n-k;
     break;
   }
 }
   }
 }
 }
  cout << ans;
return 0;
}