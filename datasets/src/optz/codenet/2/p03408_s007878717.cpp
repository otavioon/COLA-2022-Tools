#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
#include <list>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define all(a)  (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(int i = 0; i < n; i++)
#define repR(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define PB push_back
#define MP make_pair
#define INF (1e12)
#define MAX 500000



int main(){
    int n, m;
    map<string, int> mp;
    cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()) mp[s] = 1;
        else mp[s]++;
    }

    cin >> m;
    rep(i,m){
        string t;
        cin >> t;
        if(mp.find(t) == mp.end()) mp[t] = -1;
        else mp[t]--;
    }
    
    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second > ans) {
            ans = itr->second;
        }
    }
    cout << ans << endl;
    return 0;
}