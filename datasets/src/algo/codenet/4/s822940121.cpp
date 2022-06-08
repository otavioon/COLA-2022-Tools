#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

set<int> d;

bool ok(int x) {
    int n = d.size();
    while (x>0) {
        int b = x%10;
        x/=10;
        if (d.count(b)) {
            return false;
        }
    }
    return true;
}

int main () {

    int n,k;cin>>n>>k;


    rep(i,k) {
        int a;cin>>a;
        d.insert(a);
    }

    int i = n;

    while (1) {
        if (ok(i)) {
            cout<<i<<endl;
            return 0;
        } else {
            i++;
        }
    }

}