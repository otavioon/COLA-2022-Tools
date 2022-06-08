//こだわり者いろはちゃん

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

set<int>t;
int n;
priority_queue<int,vector<int>,greater<int>>ans;

void dfs(string s){
    if(s.size()>6)return;
    for(auto i:t){
        string c=s;
        c.pb(i+'0');
        if(stoi(c)>=n)ans.push(stoi(c));
        else dfs(c);
    }
}

signed main (){
    int k;cin>>n>>k;
    vector<int>c(10,0);
    rep(i,0,k){
        int r;cin>>r;
        c[r]++;
    }
    rep(i,0,10)if(c[i]==0)t.insert(i);
    string s="";
    dfs(s);
    cout<<ans.top()<<nnn;
    return 0;
}