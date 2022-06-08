#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
set<char> se;
bool check(int x){
    bool res = true;
    string s = to_string(x);
    rep(i, 0, s.size()){
        if (se.find(s[i]) != se.end()) res = false;
    }
    return res;
}

int main(){
    int n, k, ans;
    char d;
    sc(n), sc(k);
    rep(i, 0, k) cin >> d, se.insert(d);
    rep(i, n, 10*n){
        ans = i;
        if (check(ans)) break;
    }
    cout << ans << endl;
    return 0;
}