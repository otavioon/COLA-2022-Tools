#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  ll K;
  cin>>S>>K;
  if(S.size()==1) {
    cout<<K/2<<endl;
    return 0;
  }
  ll ans = 0;
  if(S[0]!=S[S.size()-1]) {
    for(int i=0;i<S.size()-1;++i) {
      if(S[i]==S[i+1]) {
        ans++;
        i++;
      }
    }
    cout<<ans*K<<endl;
    return 0;
  }
  bool haji1 = false, haji2 = false;
  ll ans1 = 1, ans2 = 0;
  for(int i=1;i<S.size()-1;++i) {
    if(S[i]==S[i+1]) {
      if(i+1==S.size()-1) haji1 = true;
      ans1++;
      i++;
    }
  }
  for(int i=0;i<S.size()-1;++i) {
    if(S[i]==S[i+1]) {
      if(i+1==S.size()-1) haji2 = true;
      ans2++;
      i++;
    }
  }
  if(haji1 && haji2) {
    cout<<ans2*K<<endl;
  }
  else if(haji1 && !haji2) {
    cout<<ans2*((K+1)/2)+ans1*(K/2)<<endl;
  }
  else if(!haji1 && haji2) {
    cout<<ans2*K<<endl;
  }
  else {
    if(S[0]==S[1]) {
    cout<<ans1*K<<endl;
    }
    else {
    cout<<ans1*K-1<<endl;
    }
  }
}
