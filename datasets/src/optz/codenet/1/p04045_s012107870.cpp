#include<bits/stdc++.h>
#define fastio     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x)     (x).begin() , (x).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl       '\n'
#define MAX        1000000
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
typedef long long int ll;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


const ll mod = 1e9+7;
const double eps = 1e-9;
const double pi = acos(-1);

void solve(){
    int k;
    int n;
    cin>>n>>k;
    bool arr[11];
    memset(arr,false,sizeof(arr));
    for(int i=0;i<k;i++) {
        int t;
        cin>>t;
        arr[t]=true;
    }
    for(int i=n;i<10000;i++) {
        string ans=to_string(i);
        bool flag=true;
        for(char j:ans) {
            if(arr[j-'0']==true) {
                flag=false;
                break;
            }
        }
        if(flag) {
            cout<<ans<<"\n";
            return;
        }
    }
}





int main(){
    fastio
    int test=1;
    while(test--)
        solve();
    return 0;
}
