#include<bits/stdc++.h>
using namespace std;
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug_x(x) cout<< #x <<"---> : "<<x<<endl;
#define debug_ve(x) for(auto it: x) cout<<it<<" ";
#define rep(i,a,n) for (int i=a;i<n;i++)
#define _rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
//std::mt19937 mrand(random_device{}());
//int rnd(int x) { return mrand() % x ; }
const ll mod=1e7;
ll ksm(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

/***********************/

int main(){
    ssd;
    int n,k;cin>>n>>k;
    set<int> se;
    rep(i,0,k){
        int x;
        cin>>x;
        se.insert(x);
    }
    string s1,ans;
    while(n){
        int cur = n%10;
        for(int i=0;i<=9;i++){
            if(!se.count(i) && i >= cur) {
                ans+= i + '0';
                break;
            }
        }
        n /=10;
    }
    reverse(all(ans));
    cout<<ans<<endl;
    return 0;
}