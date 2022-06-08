#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> h(n); rep(i,n) cin >> h[i];
    sort(all(h));
    reverse(all(h));

    ll left = -1;
    ll right = 1002003004;
    while(right - left > 1){
        ll mid = (left + right)/2;
        ll cnt = 0;

        rep(i,n){
            if(h[i] - mid * b <= 0) break;
            cnt += max(0ll, ((h[i] - mid*b)+(a-b-1))/(a-b));
        }

        if(cnt > mid) left = mid;
        if(cnt <= mid) right = mid;

    }

    cout << right << endl;

}