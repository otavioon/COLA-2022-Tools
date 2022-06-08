#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;

#define no "no"
#define No "No"
#define NO "NO"
#define yes "yes"
#define Yes "Yes"
#define YES "YES"
#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(elem, _list) for(auto& (elem) : (_list))
#define view(_list) foreach(e, _list){ cout << e << sp; } cout << next
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define ALL(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e)
#define INF 1e+9
#define PI acos(-1)
#define TAU PI * 2
#define EPS 0.00000001
const ll MOD = 998244353;

int main() {
    string s;
    ll k;
    cin >> s >> k;

    ll cnt = 0;
    int index = 0;
    char now = s[0];
    for(int i = 1; i < size(s); ++i){
        char ne = s[i];
        if(now == ne){
            if(index == 0){
                index++;
                cnt++;
            }else{
                index = 0;
            }
        }else{
            now = ne;
            index = 0;
        }
    }
    
    println(cnt * k);
}
