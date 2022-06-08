#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  string s;
  cin>>s;
  ll k;
  cin>>k;
  ll n=s.size();
  ll co=0;
  ll co2=0;
  ll tmp=1;
  ll first=1;
  ll last=1;
  int i,j;
  for(i=0;i<n-1;i++){
      if(s[i]==s[i+1]){
          for(j=i+1;j<n;j++){
              if(s[i]==s[j]){
                  tmp++;
              }else{
                  co+=tmp/2;
                  i=j-1;
                  tmp=1;
                  break;
              }
              if(j==n-1){
                  co+=tmp/2;
                  i=j-1;
                  tmp=1;
                  break;
              }
          }
      }
  }
  if(s[0]==s[n-1]){
      for(i=1;i<n;i++){
          if(s[0]==s[i]){
              first++;
          }else{
            break;
          }
      }
      for(i=n-2;i>=0;i--){
          if(s[n-1]==s[i]){
              last++;
          }else{
            break;
          }
      }
  }
  if(first==n){
  cout<<n*k/2<<endl;
  }else if(first%2==1&&last%2==1&&s[0]==s[n-1]){
      cout<<co*k+k-1<<endl;
  }else{
      cout<<co*k<<endl;
  }
}