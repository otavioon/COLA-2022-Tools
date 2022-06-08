#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

//桁数
int f(ll x) {
   int keta = 0;
   while(x > 0) {
       x /= 10;
       keta++;
   }
    return keta;
}

//約数列挙
vll d;
void divisor(ll n) {
   for(ll i = 1; i * i <= n; i++) {
       if(n % i == 0) {
           d.push_back(i);
           if(i * i != n) d.push_back(n / i);
       }
   }
   sort(all(d));
   return;
}

int main() {
    ll n;
    cin >> n;

    divisor(n);

    int ans = 114514;
    rep(i, d.size()) {
        int tmp = max(f(d[i]), f(d[d.size() - 1 - i]));
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
