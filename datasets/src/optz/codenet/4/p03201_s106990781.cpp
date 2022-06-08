#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);};};
const int MOD = 1000000007;
const int INF = INT_MAX;
const ll LLINF = 1LL<<62;



int main(void) {

    ll n;
    cin>>n;
    set<ll> s;
    vll v(n);
    rep(i,n){
        ll d;
        cin>>d;
        s.insert(d);
        v[i]=d;
    }
    vector<ll> beki(35);
    beki[0]=1;
    for(ll i=1;i<35;i++)beki[i]=beki[i-1]*2;

    ll ans=0;
    Rort(v);
    for(int i=0;i<n;i++){
        if(s.find(v[i])==s.end())continue;
        for(int j=0;j<35;j++){
            if(beki[j]-v[i]>0){
                auto tmp=s.find(beki[j]-v[i]);
                if(tmp==s.end()||*tmp==v[i])continue;
                else {
                    s.erase(v[i]);
                    s.erase(beki[j]-v[i]);
                    ans++;
                    break;
                }
            }
        }
    }
    fin(ans);

}

