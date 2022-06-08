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
  long long ans=0;
  long long check=0;
  long long check1=0;
 for(long long i=0;i<n;i++){
   check=0;
   check1=0;
 for(long long j=check;j<n;j++){
   if(a[i]<b[j]){
 for(long long k=check1;k<n;k++){
   if(b[j]>=c[k]){
   }
   else{
     //cout<<"n-k="<<n-k<<endl;
   ans+=n-k;
     check1=k;
     check=j;
     break;
   }
 }
   }
 }
 }

  cout<<ans;
return 0;
}
