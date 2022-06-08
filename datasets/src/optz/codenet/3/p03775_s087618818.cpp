#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int64_t> make_divisors(int64_t n) {
    vector<int64_t> divisors;
    for (int64_t i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if(i!=1 && i*i!=n)
				divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    if (n != 1) divisors.push_back(n);
    int div_size = divisors.size();
    return divisors;
}

int max_digit(string a, string b) {
    return max(a.size(), b.size());
}

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> divisors = make_divisors(n);
    int ds = divisors.size(); 
    int pairs = (ds+1) / 2; 
    int ans = 7;
    rep(i,pairs) {
        string a = to_string(divisors[i]);
        string b = to_string(divisors[ds-i-1]);
        int f = max_digit(a, b);
        ans = min(f, ans);
    }
    cout << ans << endl;
}