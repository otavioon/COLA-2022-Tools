#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  multiset<int> st;
  rep(i,n){
    int x;cin >> x;
    st.insert(x);
  }
  int res = 0;
  while(!st.empty()){
    int k = *st.begin();
    st.erase(st.begin());
    int j = 0;
    for(int i = 32;i >= 0;i--)if(k >> i & 1){
      j = i;
      break;
    }
    int l = (~k) + (1 << (k & -k));
    auto iter = st.find(l);
    if(iter == st.end())for(int i = 32;i <= j+1;i--){
      l -= 1 << i;
      iter = st.find(l);
      if(iter != st.end())break;
    }
    if(st.end() == iter)continue;
    st.erase(iter);
    res++;
  }
  cout << res << endl;
  


  return 0;
}