#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
 

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    set<int> d;
    rep(i,k){
        int a; cin >> a;
        d.insert(a);
    }

    for (int ans = n; ans <= 99999; ans++) {
        int x = ans;
        bool ok = true;
        while(x) {
            if(d.count(x % 10)) {
                ok = false;
                break;
            }
            x /= 10;
        }
        if(ok) {
            cout << ans << endl;
            return 0;
        }
    }
}

