#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
constexpr double pi=3.14159265358979;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

void solve(){
 int n;
 cin>>n;
 vector<int>l(n);
 rep(i,n){
   cin>>l[i];
 }
 sort(l.begin(),l.end());
 int ans=0;
 rep(i,n-2){
   for(int j=i+1;j<n-1;++j){
     int x=l[i]+l[j];
     auto itr=lower_bound(l.begin()+j+1,l.end(),x);
     ans+=distance(l.begin()+j+1,itr);
   }
 }
 cout<<ans<<"\n";
 return;
}
 
signed main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<fixed<<setprecision(20);
	solve();
	return 0;
}
