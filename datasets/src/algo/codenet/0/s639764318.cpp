#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
ll dy[4] = {1,0,-1,0};
ll dx[4] = {0,1,0,-1};


int main(){
    string s; cin >> s;
    ll k; cin >> k;
    ll cnt=0;
    if(s.size()==1){
        cout << k/2 << endl;
        return 0;
    }
    bool flag = true;
    rep(i,s.size()-1){
        if(s[i]!=s[i+1]) flag = false;
    }
    ll first=1;
    rep(i,s.size()-1){
        if(s[i]==s[i+1]){
            first++;
        }else{
            break;
        }
    }
    rep(i,s.size()-1){
        if(s[i]==s[i+1]){
            s[i+1] = '.';
            cnt++;
        }
    }
    //cout << flag << endl;
    ll ans = k*cnt;
    if(s[s.size()-1]==s[0]){
        if(first%2!=0) ans += k-1;
    }
    //cout << ans << endl;
    if(flag && (k*s.size())%2==1) ans-=k/2;
    cout << ans << endl;
    //cout << first << endl;
}
