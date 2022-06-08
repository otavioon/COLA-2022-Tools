#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define M 1000000007
#define fors(i,n) for(int i=0;i<n;++i)
#define fore(i,a,b) for(int i=a;i<=b;++i)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vv vector<int>
#define endl "\n"
#define test(i) cout<<i<<endl
#define tests(i) cout<<"i: "<<i<<endl;
#define itrt int t; cin>>t; fors(i,t)
#define itr1 int t; cin>>t;
#define ff first
#define ss second
#define pb push_back
#define vmp make_pair
#define ppb pop_back
#define sorta(a,n) sort(arr,arr+n)
#define sortv(x) sort(x.begin(),x.end())

void file(){
    #ifdef LOCAL
    freopen("demo.in","r",stdin);
    freopen("demo.out","w",stdout);
    #endif
}

bool sortdes(const pair<int,int> &a, const pair<int,int> &b){return a.ss<b.ss;}
bool sortasc(const pair<int,int> &a, const pair<int,int> &b){return a.ss>b.ss;} 
int gcd(int x,int y){return __gcd(x,y);}

const int maxi = 1e6+10;
vector<int> v[maxi];
long long a[maxi];

void dfs(int x,int y){
    a[x]+=a[y];
    for(int i:v[x]){
        if(i!=y){
            dfs(i,x);
        }
    }
}

void test_case(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;++i){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        a[x]+=y;
    }
    dfs(1,0);
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    fastio;
    file();
    int T=1;
    // int T;
    // cin>>T;
    for(int nr=1;nr<=T;++nr) {
        // cout<<"Case #"<<nr<<": ";
		test_case();
    }
}