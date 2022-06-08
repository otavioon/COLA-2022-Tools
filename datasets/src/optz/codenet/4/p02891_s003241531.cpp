#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
 
int main() {
  string s;
  int k;
  cin>>s>>k;
  bool ok=true;
  int n=s.size();
  for(int i=0;i<n-1;i++){
    if(s[i+1]!=s[i]){ok=false;}
  }
  if(ok){cout<<(int64_t)n*k/2<<endl;return 0;}
  int64_t sum=0;
  int cnt=0;
  for(int i=0;i<n-1;i++){
   if(s[i]==s[i+1]){cnt++;}
   else{sum+=(cnt+1)/2;cnt=0;}
  }

  if(s[0]!=s[n-1]){
   cout<<sum*k<<endl;
  }
  else{
    int64_t a=0,b=0;
    for(int i=0;i<n;i++){
      if(s[i]==s[0]){a++;}
      else{break;}
    }
    for(int i=n-1;i>=0;i--){
      if(s[i]==s[n-1]){b++;}
      else{break;}
    }
    cout<<sum*k-((a/2)+(b/2)-(a+b)/2)<<endl;
  }
  return 0;
}