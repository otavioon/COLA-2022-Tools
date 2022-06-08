#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)

int main() {
    int N, K;
    vector<int> D(10);

    cin >> N >> K;
    rep(i, K) cin >> D[i];


    int num, a, b = 1, digit = 0;
    bool flag;

    while (true) {
        if (N / b != 0) digit++;
        else break;
        b *= 10;
    }

    for (int i = N; i < 1000000; i++) {
        flag = true;
        num = i;
        rep(j, digit) {
            a = num % 10;
            rep(k, K) if (a == D[k]) flag = false;
            num /= 10;
        }
        if (flag) {
            cout << i << endl;
            break;
        }
    }
    
}