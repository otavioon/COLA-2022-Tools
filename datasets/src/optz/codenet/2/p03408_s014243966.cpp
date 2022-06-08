#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;

int main(){
    int n,m;
    cin >> n;
    vector<string>s(n),t(m);
    rep(i,n)cin >>s[i];
    cin>>m;
    rep(i,m)cin >>t[i];
    map<string,int>mp;
    rep(i,n){
        mp[s[i]]++;
    }
    rep(i,m) if(mp[t[i]]>0)mp[t[i]]--;
    int ans = 0;
    for(auto x:mp){
        if(x.second>ans) ans=x.second;
    }
    cout << ans <<endl;
}