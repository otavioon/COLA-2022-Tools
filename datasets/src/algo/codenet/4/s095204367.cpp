#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
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
  int N,K;
  cin>>N>>K;
  vector<int>D(K);
  for(int i=0;i<K;i++){
      cin>>D[i];
  }
  for(int i=N;i<=10*N;i++){
      string s=to_string(i);
      int S=s.size();
      bool ok=true;
      for(int j=0;j<S;j++){
         for(int k=0;k<K;k++){
             if(s[j]-'0'==D[k]){ok=false;}
         }
      }
      if(ok){cout<<i<<endl;return 0;}
  }
  return 0;
}