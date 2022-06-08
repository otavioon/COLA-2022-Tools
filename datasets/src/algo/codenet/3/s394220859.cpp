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
  cout << c[i]<<" ";}  cout <<endl; */
  long long d[n];
  long long sum=0;
  for(long long i=0;i<n;i++){
  for(long long j=0;j<n;j++){
  if(b[i]<c[j]){
  d[i]=n-j;
    sum+=d[i];
    break;
  }
  }
  }
  //cout <<sum<<endl;
long long ans=0;
  long long check=0;
  for(long long i=0;i<n;i++){
for(long long j=check;j<n;j++){
if(a[i]<b[j]){
ans+=sum;
  check=j;
  break;
}
  else{
  sum-=d[j];
  }
}
}
  cout<<ans;
return 0;
}
