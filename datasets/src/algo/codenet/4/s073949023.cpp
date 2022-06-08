#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


int main(){
    int n,k;
    cin>>n>>k;
    set<int> d;
    rep(i,0,k) {int t;cin>>t; d.insert(t);};
    rep(i,n,100000){
        int t=i,found=0;
        while(t){
            if(d.find(t%10)!=d.end()) {found=1;break;}
            t/=10;
        }
        if(found) continue;
        cout<<i<<endl; break;
    }

    return 0;
}
