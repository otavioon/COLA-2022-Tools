#include <bits/stdc++.h>
 
#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        2000005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
 
using namespace std;
 
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
int power(int a,int n)
{
    a %= mod;
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a)%mod,n/2)%mod))%mod;
    return power((a*a)%mod,n/2)%mod;
}
const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2)%mod;//little fermat....
}

signed main()
{
    showoff;
    string s;
    int k,ans = 0;
    cin >> s >> k;
    if(sz(s) == 1){
        cout << k/2;
        return 0;
    }
    if(s[0] != s[sz(s)-1] || k == 1){
        FOR(i,0,sz(s)-1)if(s[i] == s[i+1])++ans,++i;
        cout << ans*k;
        return 0;
    }
    else{
        int ans1 = 0,fo = 0,fi = 0;
        FOR(i,0,sz(s)){
            if(i == sz(s)-1){fo = 1;break;}
            if(s[i] == s[i+1])++ans1,++i;
        }
        if(fo == 0){cout << ans1*k;return 0;}
        FOR(i,1,sz(s)){
            if(i == sz(s)-1){fi = 1;break;}
            if(s[i] == s[i+1])++ans,++i;
        }
        if(fi == 0)cout << (1+ans)*(k/2)+ans1*(k-k/2);
        else cout << ans1+ans*(k-1)+k-1;
        return 0;
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ... 