#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

int dx[] = {0, -1, 1, 0, -1, 1, -1, 1, 0};
int dy[] = {-1, 0, 0, 1, -1, -1, 1, 1, 0};

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}

#define _rep3(i,p,n) for(int i=(p),i##_counter=(n); i<i##_counter;++i)
#define _rep2(i,n,_) _rep3(i,0,n)
#define _rep_call(a, b, c, name, ...) name(a, b, c)
#define rep(...) _rep_call(__VA_ARGS__, _rep3, _rep2)

#define dump(x)  cerr << #x << " = " << (x) << '\n'
#define debug(x) cerr << #x << " = " << (x) << " (at line " << __LINE__ << ")" << " " << __FILE__ << '\n'

bool check(const set<int> &d, int i) {
    while (i) {
        if (d.find(i % 10) != d.end()) return false;
        i /= 10;
    }
    return true;
}

void Main() {
    int N, K; cin >> N >> K;
    set<int> d;
    rep(i, K) {
        int dd; cin >> dd;
        d.insert(dd);
    }
    rep(i, N, 1000000) {
        if (check(d, i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
    return 0;
}
